/**********************************************************************
  XtalOptGenetic - Tools neccessary for genetic structure optimization

  Copyright (C) 2009-2011 by David C. Lonie

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 ***********************************************************************/

#include <xtalopt/genetic.h>
#include <xtalopt/xtalopt.h>

#include <xtalopt/structures/xtal.h>
#include <xtalopt/ui/dialog.h>

#include <globalsearch/macros.h>

#include <openbabel/obiter.h>

#include <QtCore/QDebug>

using namespace std;
using namespace OpenBabel;
using namespace Eigen;
using namespace Avogadro;

namespace XtalOpt {

  Xtal* XtalOptGenetic::crossover(Xtal* xtal1, Xtal* xtal2, double minimumContribution, double &percent1) {

    INIT_RANDOM_GENERATOR();
    //
    // Random Assignments
    //
    // Where to slice in fractional units
    double cutVal = ((100.0-(2.0*minimumContribution) ) * RANDDOUBLE() + minimumContribution) / 100.0;
    percent1 = cutVal * 100.0;
    // Shift values = s_n_m:
    //  n = xtal (1,2)
    //  m = axes (1 = a_ch; 2,3 = secondary axes)
    double s_1_1, s_1_2, s_1_3, s_2_1, s_2_2, s_2_3;
    s_1_1 = RANDDOUBLE();
    s_2_1 = RANDDOUBLE();
    s_1_2 = RANDDOUBLE();
    s_2_2 = RANDDOUBLE();
    s_1_3 = RANDDOUBLE();
    s_2_3 = RANDDOUBLE();
    //
    // Transformation matrixes
    //
    //  We will rotate and reflect the cell and coords randomly prior
    //  to slicing the cell. This will be done via transformation
    //  matrices.
    //
    //  First, generate a list of the numbers 0-2, using each number
    //  only once. Then construct the matrix via:
    //
    //  0: +/-(1 0 0)
    //  1: +/-(0 1 0)
    //  2: +/-(0 0 1)
    //
    // Column vectors are actually used instead of row vectors so that
    // both the cell matrix and coordinates can be transformed by
    //
    // new = old * xform
    //
    // provided that both new and old are (or are composed of) row
    // vectors. For column vecs/matrices:
    //
    // new = (old.transpose() * xform).transpose()
    //
    // should do the trick.
    //
    QList<int> list1;
    list1.append(static_cast<int>(floor(RANDDOUBLE()*3)));
    if (list1.at(0) == 3) list1[0] = 2;
    switch (list1.at(0)) {
    case 0:
      if (RANDDOUBLE() > 0.5) {
        list1.append(1);
        list1.append(2);
      } else {
        list1.append(2);
        list1.append(1);
      }
      break;
    case 1:
      if (RANDDOUBLE() > 0.5) {
        list1.append(0);
        list1.append(2);
      } else {
        list1.append(2);
        list1.append(0);
      }
      break;
    case 2:
      if (RANDDOUBLE() > 0.5) {
        list1.append(0);
        list1.append(1);
      } else {
        list1.append(1);
        list1.append(0);
      }
      break;
    }

    QList<int> list2;
    list2.append(static_cast<int>(floor(RANDDOUBLE()*3)));
    if (list2.at(0) == 3) list2[0] = 2;
    switch (list2.at(0)) {
    case 0:
      if (RANDDOUBLE() > 0.5) {
        list2.append(1);
        list2.append(2);
      } else {
        list2.append(2);
        list2.append(1);
      }
      break;
    case 1:
      if (RANDDOUBLE() > 0.5) {
        list2.append(0);
        list2.append(2);
      } else {
        list2.append(2);
        list2.append(0);
      }
      break;
    case 2:
      if (RANDDOUBLE() > 0.5) {
        list2.append(0);
        list2.append(1);
      } else {
        list2.append(1);
        list2.append(0);
      }
      break;
    }
    //
    //  Now populate the matrices:
    //
    Eigen::Matrix3d xform1 = Eigen::Matrix3d::Zero();
    Eigen::Matrix3d xform2 = Eigen::Matrix3d::Zero();
    for (int i = 0; i < 3; i++) {
      double r1 = RANDDOUBLE() - 0.5;
      double r2 = RANDDOUBLE() - 0.5;
      int s1 = int(r1/fabs(r1));
      int s2 = int(r2/fabs(r2));
      if (list1.at(i) == 0)             xform1.block(0, i, 3, 1) << s1, 0, 0;
      else if (list1.at(i) == 1)	xform1.block(0, i, 3, 1) << 0, s1, 0;
      else if (list1.at(i) == 2)	xform1.block(0, i, 3, 1) << 0, 0, s1;
      if (list2.at(i) == 0)             xform2.block(0, i, 3, 1) << s2, 0, 0;
      else if (list2.at(i) == 1)	xform2.block(0, i, 3, 1) << 0, s2, 0;
      else if (list2.at(i) == 2)	xform2.block(0, i, 3, 1) << 0, 0, s2;
    }

    // Store unit cells
    matrix3x3 obcell1 = xtal1->OBUnitCell()->GetCellMatrix();
    matrix3x3 obcell2 = xtal2->OBUnitCell()->GetCellMatrix();
    // Convert to Eigen:
    Eigen::Matrix3d cell1 = Eigen::Matrix3d::Zero();
    Eigen::Matrix3d cell2 = Eigen::Matrix3d::Zero();
    for (int row = 0; row < 3; row++) {
      for (int col = 0; col < 3; col++) {
        cell1(row,col) = obcell1.Get(row, col);
        cell2(row,col) = obcell2.Get(row, col);
      }
    }

    // Get lists of atoms and fractional coordinates
    xtal1->lock()->lockForRead();
    // Save composition for checks later
    QList<QString> xtalAtoms	=  xtal1->getSymbols();
    QList<uint> xtalCounts	=  xtal1->getNumberOfAtomsAlpha();
    QList<Atom*> atomList1      =  xtal1->atoms();
    QList<Vector3d> fracCoordsList1;

    for (int i = 0; i < atomList1.size(); i++)
      fracCoordsList1.append(xtal1->cartToFrac(*(atomList1.at(i)->pos())));
    xtal1->lock()->unlock();

    xtal2->lock()->lockForRead();
    QList<Atom*> atomList2      = xtal2->atoms();
    QList<Vector3d> fracCoordsList2;
    for (int i = 0; i < atomList2.size(); i++)
      fracCoordsList2.append(xtal2->cartToFrac(*(atomList2.at(i)->pos())));
    xtal2->lock()->unlock();

    // Transform (reflect / rot)
    cell1 *= xform1;
    cell2 *= xform2;
    // Eigen::Vector3d is a column vector, so transpose before and
    // after transforming them.
    for (int i = 0; i < fracCoordsList1.size(); i++) {
      fracCoordsList1[i] = (fracCoordsList1[i].transpose() *
                            xform1).transpose();
      fracCoordsList2[i] = (fracCoordsList2[i].transpose() *
                            xform2).transpose();
    }

    // Shift coordinates:
    for (int i = 0; i < fracCoordsList1.size(); i++) {
      // <QList>[<QList index>][<0=x,1=y,2=z axes>]
      fracCoordsList1[i][0] += s_1_1;
      fracCoordsList2[i][0] += s_2_1;
      fracCoordsList1[i][1] += s_1_2;
      fracCoordsList2[i][1] += s_2_2;
      fracCoordsList1[i][2] += s_1_3;
      fracCoordsList2[i][2] += s_2_3;
    }

    // Wrap coordinates
    for (int i = 0; i < fracCoordsList1.size(); i++) {
      fracCoordsList1[i][0] = fmod(fracCoordsList1[i][0]+100, 1);
      fracCoordsList2[i][0] = fmod(fracCoordsList2[i][0]+100, 1);
      fracCoordsList1[i][1] = fmod(fracCoordsList1[i][1]+100, 1);
      fracCoordsList2[i][1] = fmod(fracCoordsList2[i][1]+100, 1);
      fracCoordsList1[i][2] = fmod(fracCoordsList1[i][2]+100, 1);
      fracCoordsList2[i][2] = fmod(fracCoordsList2[i][2]+100, 1);
    }

    //
    // Build new xtal from cutVal
    //
    // Average cell matricies
    // Randomly weight the parameters of the two parents
    double weight = RANDDOUBLE();
    matrix3x3 dims;
    for (uint row = 0; row < 3; row++) {
      for (uint col = 0; col < 3; col++) {
        dims.Set(row,col,
                 cell1(row,col) * weight +
                 cell2(row,col) * (1 - weight));
      }
    }

    // Build offspring
    Xtal *nxtal = new Xtal();
    nxtal->setCellInfo(dims.GetRow(0), dims.GetRow(1), dims.GetRow(2));
    QWriteLocker nxtalLocker (nxtal->lock());

    // Cut xtals and populate new one.
    for (int i = 0; i < fracCoordsList1.size(); i++) {
      if ( fracCoordsList1.at(i)[0] <= cutVal ) {
        Atom* newAtom = nxtal->addAtom();
        newAtom->setAtomicNumber(atomList1.at(i)->atomicNumber());
        newAtom->setPos(nxtal->fracToCart(fracCoordsList1.at(i)));
      }
      if ( fracCoordsList2.at(i)[0] > cutVal ) {
        Atom* newAtom = nxtal->addAtom();
        newAtom->setAtomicNumber(atomList2.at(i)->atomicNumber());
        newAtom->setPos(nxtal->fracToCart(fracCoordsList2.at(i)));
      }
    }

    // Check composition of nxtal
    QList<int> deltas;
    QList<QString> nxtalAtoms	=  nxtal->getSymbols();
    QList<uint> nxtalCounts	=  nxtal->getNumberOfAtomsAlpha();
    // Fill in 0's for any missing atom types in nxtal
    if (xtalAtoms != nxtalAtoms) {
      for (int i = 0; i < xtalAtoms.size(); i++) {
        if (i >= nxtalAtoms.size())
          nxtalAtoms.append("");
        if (xtalAtoms.at(i) != nxtalAtoms.at(i)) {
          nxtalAtoms.insert(i,xtalAtoms.at(i));
          nxtalCounts.insert(i, 0);
        }
      }
    }
    // Get differences --
    // a (+) value in deltas indicates that more atoms are needed in nxtal
    // a (-) value indicates less are needed.
    for (int i = 0; i < xtalCounts.size(); i++)
      deltas.append(xtalCounts.at(i) - nxtalCounts.at(i));
    // Correct for differences by inserting atoms from
    // discarded portions of parents or removing random atoms.
    int delta;
    for (int i = 0; i < deltas.size(); i++) {
      delta = deltas.at(i);
      //qDebug() << "Delta = " << delta;
      if (delta == 0) continue;
      while (delta < 0) { //qDebug() << "Too many " << xtalAtoms.at(i) << "!";
        // Randomly delete atoms from nxtal;
        // 1 in X chance of each atom being deleted, where
        // X is the total number of that atom type in nxtal.
        QList<Atom*> atomList = nxtal->atoms();
        for (int j = 0; j < atomList.size(); j++) {
          if (atomList.at(j)->atomicNumber() == OpenBabel::etab.GetAtomicNum(xtalAtoms.at(i).toStdString().c_str())) {
            // atom at j is the type that needs to be deleted.
            if (RANDDOUBLE() < 1.0/static_cast<double>(nxtalCounts.at(i))) {
              // If the odds are right, delete the atom and break loop to recheck condition.
              nxtal->removeAtom(atomList.at(j)); // removeAtom(Atom*) takes care of deleting pointer.
              delta++;
              break;
            }
          }
        }
      }
      while (delta > 0) { //qDebug() << "Too few " << xtalAtoms.at(i) << "!";
        // Randomly add atoms from discarded cuts of parent xtals;
        // 1 in X chance of each atom being added, where
        // X is the total number of atoms of that species in the parent.
        //
        // First, pick the parent. 50/50 chance for each:
        uint parent;
        if (RANDDOUBLE() < 0.5) parent = 1;
        else parent = 2;
        for (int j = 0; j < fracCoordsList1.size(); j++) { // size should be the same for both parents
          if (
              // if atom at j is the type that needs to be added,
              (
               ( parent == 1 && atomList1.at(j)->atomicNumber() == OpenBabel::etab.GetAtomicNum(xtalAtoms.at(i).toStdString().c_str()))
               ||
               ( parent == 2 && atomList2.at(j)->atomicNumber() == OpenBabel::etab.GetAtomicNum(xtalAtoms.at(i).toStdString().c_str()))
              )
              &&
              // and atom is in the discarded region of the cut,
              (
               ( parent == 1 && fracCoordsList1.at(j)[0] > cutVal )
               ||
               ( parent == 2 && fracCoordsList2.at(j)[0] <= cutVal)
               )
              &&
              // and the odds favor it, add the atom to nxtal
              ( RANDDOUBLE() < 1.0/static_cast<double>(xtalCounts.at(i)) )
              ) {
            Atom* newAtom = nxtal->addAtom();
            newAtom->setAtomicNumber(atomList1.at(j)->atomicNumber());
            if ( parent == 1)
              newAtom->setPos(nxtal->fracToCart(fracCoordsList1.at(j)));
            else // ( parent == 2)
              newAtom->setPos(nxtal->fracToCart(fracCoordsList2.at(j)));
            delta--;
            break;
          }
        }
      }
    }

    // Done!
    nxtal->wrapAtomsToCell();
    nxtal->setStatus(Xtal::WaitingForOptimization);
    return nxtal;
  }

  // Crossover designed specifically for crossing over different formula units
  Xtal* XtalOptGenetic::FUcrossover(Xtal* xtal1, Xtal* xtal2, double minimumContribution, double &percent1, double &percent2, const QList<uint> formulaUnitsList, QHash<uint, XtalCompositionStruct> comp) {

    INIT_RANDOM_GENERATOR();
    //
    // Random Assignments
    //
    // Where to slice in fractional units. For FUcrossover, the value may be
    // between the minimum contribution and 100% as opposed to being between
    // the minimum contribution and 100% - minimum contribution in the regular
    // crossover function
    double cutVal1 = ((100.0 - minimumContribution) * RANDDOUBLE() + minimumContribution) / 100.0;
    double cutVal2 = ((100.0 - minimumContribution) * RANDDOUBLE() + minimumContribution) / 100.0;
    percent1 = cutVal1 * 100.0;
    percent2 = cutVal2 * 100.0;
    //qDebug() << "cutVal1 is " << QString::number(cutVal1);
    //qDebug() << "cutVal2 is " << QString::number(cutVal2);
    // Shift values = s_n_m:
    //  n = xtal (1,2)
    //  m = axes (1 = a_ch; 2,3 = secondary axes)
    double s_1_1, s_1_2, s_1_3, s_2_1, s_2_2, s_2_3;
    s_1_1 = RANDDOUBLE();
    s_2_1 = RANDDOUBLE();
    s_1_2 = RANDDOUBLE();
    s_2_2 = RANDDOUBLE();
    s_1_3 = RANDDOUBLE();
    s_2_3 = RANDDOUBLE();
    //
    // Transformation matrixes
    //
    //  We will rotate and reflect the cell and coords randomly prior
    //  to slicing the cell. This will be done via transformation
    //  matrices.
    //
    //  First, generate a list of the numbers 0-2, using each number
    //  only once. Then construct the matrix via:
    //
    //  0: +/-(1 0 0)
    //  1: +/-(0 1 0)
    //  2: +/-(0 0 1)
    //
    // Column vectors are actually used instead of row vectors so that
    // both the cell matrix and coordinates can be transformed by
    //
    // new = old * xform
    //
    // provided that both new and old are (or are composed of) row
    // vectors. For column vecs/matrices:
    //
    // new = (old.transpose() * xform).transpose()
    //
    // should do the trick.
    //
    QList<int> list1;
    list1.append(static_cast<int>(floor(RANDDOUBLE()*3)));
    if (list1.at(0) == 3) list1[0] = 2;
    switch (list1.at(0)) {
    case 0:
      if (RANDDOUBLE() > 0.5) {
        list1.append(1);
        list1.append(2);
      } else {
        list1.append(2);
        list1.append(1);
      }
      break;
    case 1:
      if (RANDDOUBLE() > 0.5) {
        list1.append(0);
        list1.append(2);
      } else {
        list1.append(2);
        list1.append(0);
      }
      break;
    case 2:
      if (RANDDOUBLE() > 0.5) {
        list1.append(0);
        list1.append(1);
      } else {
        list1.append(1);
        list1.append(0);
      }
      break;
    }

    QList<int> list2;
    list2.append(static_cast<int>(floor(RANDDOUBLE()*3)));
    if (list2.at(0) == 3) list2[0] = 2;
    switch (list2.at(0)) {
    case 0:
      if (RANDDOUBLE() > 0.5) {
        list2.append(1);
        list2.append(2);
      } else {
        list2.append(2);
        list2.append(1);
      }
      break;
    case 1:
      if (RANDDOUBLE() > 0.5) {
        list2.append(0);
        list2.append(2);
      } else {
        list2.append(2);
        list2.append(0);
      }
      break;
    case 2:
      if (RANDDOUBLE() > 0.5) {
        list2.append(0);
        list2.append(1);
      } else {
        list2.append(1);
        list2.append(0);
      }
      break;
    }
    //
    //  Now populate the matrices:
    //
    Eigen::Matrix3d xform1 = Eigen::Matrix3d::Zero();
    Eigen::Matrix3d xform2 = Eigen::Matrix3d::Zero();
    for (int i = 0; i < 3; i++) {
      double r1 = RANDDOUBLE() - 0.5;
      double r2 = RANDDOUBLE() - 0.5;
      int s1 = int(r1/fabs(r1));
      int s2 = int(r2/fabs(r2));
      if (list1.at(i) == 0)             xform1.block(0, i, 3, 1) << s1, 0, 0;
      else if (list1.at(i) == 1)	xform1.block(0, i, 3, 1) << 0, s1, 0;
      else if (list1.at(i) == 2)	xform1.block(0, i, 3, 1) << 0, 0, s1;
      if (list2.at(i) == 0)             xform2.block(0, i, 3, 1) << s2, 0, 0;
      else if (list2.at(i) == 1)	xform2.block(0, i, 3, 1) << 0, s2, 0;
      else if (list2.at(i) == 2)	xform2.block(0, i, 3, 1) << 0, 0, s2;
    }

    // Store unit cells
    matrix3x3 obcell1 = xtal1->OBUnitCell()->GetCellMatrix();
    matrix3x3 obcell2 = xtal2->OBUnitCell()->GetCellMatrix();
    // Convert to Eigen:
    Eigen::Matrix3d cell1 = Eigen::Matrix3d::Zero();
    Eigen::Matrix3d cell2 = Eigen::Matrix3d::Zero();
    for (int row = 0; row < 3; row++) {
      for (int col = 0; col < 3; col++) {
        cell1(row,col) = obcell1.Get(row, col);
        cell2(row,col) = obcell2.Get(row, col);
       //qDebug() << "For cell 1, dims at row " << QString::number(row) << " and column " << QString::number(col) << " was " << QString::number(cell1(row,col)) << " before transformation.";

      }
    }

    // Get lists of atoms and fractional coordinates
    xtal1->lock()->lockForRead();
    // Save composition for checks later
    QList<QString> xtalAtoms	=  xtal1->getSymbols();
    QList<uint> xtalCounts1	=  xtal1->getNumberOfAtomsAlpha();
    QList<Atom*> atomList1      =  xtal1->atoms();
    uint xtal1FU                =  xtal1->getFormulaUnits();
    QList<Vector3d> fracCoordsList1;
    //qDebug() << "xtal1FU is " << QString::number(xtal1FU);

    // Obtain empirical formula
    QList<uint> empiricalFormulaList;
    for (int i = 0; i < xtalCounts1.size(); i++) {
      empiricalFormulaList.append(xtalCounts1.at(i) / xtal1FU);
    }

    for (int i = 0; i < atomList1.size(); i++)
      fracCoordsList1.append(xtal1->cartToFrac(*(atomList1.at(i)->pos())));
    xtal1->lock()->unlock();

    xtal2->lock()->lockForRead();
    QList<Atom*> atomList2      = xtal2->atoms();
    QList<Vector3d> fracCoordsList2;
    //qDebug() << "xtal2FU is " << QString::number(xtal2->getFormulaUnits());
    for (int i = 0; i < atomList2.size(); i++)
      fracCoordsList2.append(xtal2->cartToFrac(*(atomList2.at(i)->pos())));
    xtal2->lock()->unlock();

    // Will NOT transform (reflect / rot) the unit cell in FUcrossover
    cell1 *= xform1;
    cell2 *= xform2;
    // Eigen::Vector3d is a column vector, so transpose before and
    // after transforming them.
    for (int i = 0; i < fracCoordsList1.size(); i++) {
      fracCoordsList1[i] = (fracCoordsList1[i].transpose() *
                            xform1).transpose();
    }

    for (int i = 0; i < fracCoordsList2.size(); i++) {
      fracCoordsList2[i] = (fracCoordsList2[i].transpose() *
                            xform2).transpose();
    }

    // Shift coordinates:
    for (int i = 0; i < fracCoordsList1.size(); i++) {
      // <QList>[<QList index>][<0=x,1=y,2=z axes>]
      fracCoordsList1[i][0] += s_1_1;
      fracCoordsList1[i][1] += s_1_2;
      fracCoordsList1[i][2] += s_1_3;
    }

    for (int i = 0; i < fracCoordsList2.size(); i++) {
      // <QList>[<QList index>][<0=x,1=y,2=z axes>]
      fracCoordsList2[i][0] += s_2_1;
      fracCoordsList2[i][1] += s_2_2;
      fracCoordsList2[i][2] += s_2_3;
    }

    // Wrap coordinates
    for (int i = 0; i < fracCoordsList1.size(); i++) {
      fracCoordsList1[i][0] = fmod(fracCoordsList1[i][0]+100, 1);
      fracCoordsList1[i][1] = fmod(fracCoordsList1[i][1]+100, 1);
      fracCoordsList1[i][2] = fmod(fracCoordsList1[i][2]+100, 1);
    }

    for (int i = 0; i < fracCoordsList2.size(); i++) {
      fracCoordsList2[i][0] = fmod(fracCoordsList2[i][0]+100, 1);
      fracCoordsList2[i][1] = fmod(fracCoordsList2[i][1]+100, 1);
      fracCoordsList2[i][2] = fmod(fracCoordsList2[i][2]+100, 1);
    }

    // Find the largest component of each lattice vector and
    // invert that vector (multiply all components by -1) if
    // the largest component is negative. This is to avoid adding
    // oppositely signed vectors together (which results in a
    // very small volume)
    for (uint row = 0; row < 3; row++) {
      uint largestIndex = 0;
      for (uint col = 0; col < 3; col++) {
        if (fabs(cell1(row,col)) > fabs(cell1(row,largestIndex)))
          largestIndex = col;
      }
      if (fabs(cell1(row,largestIndex)) != cell1(row,largestIndex)) {
        for (uint col = 0; col < 3; col++) {
          cell1(row,col) = -1 * cell1(row,col);
        }
      }
    }

    for (uint row = 0; row < 3; row++) {
      uint largestIndex = 0;
      for (uint col = 0; col < 3; col++) {
        if (fabs(cell2(row,col)) > fabs(cell2(row,largestIndex)))
          largestIndex = col;
      }
      if (fabs(cell2(row,largestIndex)) != cell2(row,largestIndex)) {
        for (uint col = 0; col < 3; col++) {
          cell2(row,col) = -1 * cell2(row,col);
        }
      }
    }

    // Build new xtal from cutVal
    //
    // Average cell matricies
    // The weight the parameters of the two parents matches the cutVal
    double weight = RANDDOUBLE();
    matrix3x3 dims;
    for (uint row = 0; row < 3; row++) {
      for (uint col = 0; col < 3; col++) {
        // qDebug() << "For cell 1, dims at row " << QString::number(row) << " and column " << QString::number(col) << " is " << QString::number(cell1(row,col));
        // qDebug() << "For cell 2, dims at row " << QString::number(row) << " and column " << QString::number(col) << " is " << QString::number(cell2(row,col));
        dims.Set(row,col,
                 cell1(row,col) * cutVal1 +
                 cell2(row,col) * cutVal2);
        // qDebug() << "dims at row " << QString::number(row) << " and column " << QString::number(col) << " in the new cell is " << QString::number(dims.Get(row,col));
      }
    }
    // Build offspring
    Xtal *nxtal = new Xtal();
    nxtal->setCellInfo(dims.GetRow(0), dims.GetRow(1), dims.GetRow(2));
    QWriteLocker nxtalLocker (nxtal->lock());

    // Cut xtals and populate new one.
    QList<Vector3d> tempFracCoordsList1;
    for (int i = 0; i < fracCoordsList1.size(); i++) {
      tempFracCoordsList1 = fracCoordsList1;
      if ( fracCoordsList1.at(i)[0] <= cutVal1 ) {
        Atom* newAtom = nxtal->addAtom();
        newAtom->setAtomicNumber(atomList1.at(i)->atomicNumber());
        // Correct for atom position distortion across the cutVal axis
        tempFracCoordsList1[i][0] = (xtal1->getA() / nxtal->getA()) * fracCoordsList1.at(i)[0];
        newAtom->setPos(nxtal->fracToCart(tempFracCoordsList1.at(i)));
      }
    }

    QList<Vector3d> tempFracCoordsList2;
    for (int i = 0; i < fracCoordsList2.size(); i++) {
      tempFracCoordsList2 = fracCoordsList2;
      if ( fracCoordsList2.at(i)[0] <= cutVal2 ) {
        Atom* newAtom = nxtal->addAtom();
        newAtom->setAtomicNumber(atomList2.at(i)->atomicNumber());
        // Correct for atom position distortion across the cutVal axis
        tempFracCoordsList2[i][0] = (xtal2->getA() / nxtal->getA()) * fracCoordsList2.at(i)[0];
        // Reflect these atoms to the other side of the xtal via the plane
        // perpendicular to the cutVal axis
        tempFracCoordsList2[i][0] = 1 - fracCoordsList2.at(i)[0];
        newAtom->setPos(nxtal->fracToCart(tempFracCoordsList2.at(i)));
      }
    }

    // Check composition of nxtal
    QList<int> deltas;
    QList<QString> nxtalAtoms	=  nxtal->getSymbols();
    QList<uint> nxtalCounts	=  nxtal->getNumberOfAtomsAlpha();
    // Fill in 0's for any missing atom types in nxtal
    if (xtalAtoms != nxtalAtoms) {
      for (int i = 0; i < xtalAtoms.size(); i++) {
        if (i >= nxtalAtoms.size())
          nxtalAtoms.append("");
        if (xtalAtoms.at(i) != nxtalAtoms.at(i)) {
          nxtalAtoms.insert(i,xtalAtoms.at(i));
          nxtalCounts.insert(i, 0);
        }
      }
    }

    // Correct the ratios so that we end up with a correct composition
    QList<uint> targetXtalCounts = nxtalCounts;

    // Replace zeros with ones since we know there will be at least 1 atom of
    // each type. We don't want to divide by zero by accident later...
    for (int i = 0; i < targetXtalCounts.size(); i++)
      if (targetXtalCounts.at(i) == 0) targetXtalCounts[i] = 1;

    // Find the index with the smallest xtalCount in empiricalFormulaList
    uint smallestCountIndex = 0;
    for (int i = 1; i < empiricalFormulaList.size(); i++) {
      if (empiricalFormulaList.at(i) < empiricalFormulaList.at(i - 1)) smallestCountIndex = i;
    }

    // Make sure the smallest number of atoms in the new xtal is a multiple
    // of the smallest number of atoms in the empirical formula. If not,
    // decide randomly whether to increase or decrease to reach a valid
    // number of atoms.
    double rand = RANDDOUBLE();
    while (targetXtalCounts.at(smallestCountIndex) % (empiricalFormulaList.at(smallestCountIndex)) != 0) {
      if (rand <= 0.5) targetXtalCounts[smallestCountIndex] = targetXtalCounts.at(smallestCountIndex) - 1;
      if (targetXtalCounts.at(smallestCountIndex) == 0) rand = 1;
      else if (rand > 0.5) targetXtalCounts[smallestCountIndex] = targetXtalCounts.at(smallestCountIndex) + 1;
    }

    // Add or subtract atoms from targetXtalCounts until the proper ratios
    // have been reached.
    for (int i = 0; i < empiricalFormulaList.size(); i++) {
      double desiredRatio = static_cast<double>(empiricalFormulaList.at(i)) /
      static_cast<double>(empiricalFormulaList.at(smallestCountIndex));
      double actualRatio  = static_cast<double>(targetXtalCounts.at(i)) /
      static_cast<double>(targetXtalCounts.at(smallestCountIndex));
      while (desiredRatio != actualRatio) {
        if (desiredRatio < actualRatio) {
          // Need to decrease the numerator
          targetXtalCounts[i] = targetXtalCounts.at(i) - 1;
          actualRatio = static_cast<double>(targetXtalCounts.at(i)) /
          static_cast<double>(targetXtalCounts.at(smallestCountIndex));
        }
        else if (desiredRatio > actualRatio) {
          // Need to increase the numerator
          targetXtalCounts[i] = targetXtalCounts.at(i) + 1;
          actualRatio = static_cast<double>(targetXtalCounts.at(i)) /
          static_cast<double>(targetXtalCounts.at(smallestCountIndex));
        }
      }
    }

    bool onTheList = false;
    while (!onTheList) {
      // Count the number of formula units
      QList<uint> xtalCounts = targetXtalCounts;
      unsigned int minimumQuantityOfAtomType = xtalCounts.at(0);
      for (int i = 1; i < xtalCounts.size(); ++i) {
        if (minimumQuantityOfAtomType > xtalCounts.at(i)){
          minimumQuantityOfAtomType = xtalCounts.at(i);
        }
      }
      unsigned int numberOfFormulaUnits = 1;
      bool formulaUnitsFound;
      for (int i = minimumQuantityOfAtomType; i > 1; i--){
        formulaUnitsFound = true;
        for (int j = 0; j < xtalCounts.size(); ++j) {
          if(xtalCounts.at(j) % i != 0){
            formulaUnitsFound = false;
          }
        }
        if(formulaUnitsFound == true) {
          numberOfFormulaUnits = i;
          i = 1;
        }
      }

      // Check to make sure numberOfFormulaUnits is on the list
      for (int i = 0; i < formulaUnitsList.size(); i++) {
        if (numberOfFormulaUnits == formulaUnitsList.at(i)) onTheList = true;
      }

      // If it is not on the list, find the closest FU on the list and make that
      // the number of formula units. If there are two closest FU's, pick one
      // randomly.
      if (!onTheList) {
        int shortestDistance = numberOfFormulaUnits - formulaUnitsList.at(0);
        for (int i = 1; i < formulaUnitsList.size(); i++) {
          int newDistance = numberOfFormulaUnits - formulaUnitsList.at(i);
          if (abs(shortestDistance) == abs(newDistance)) {
            double randdouble = RANDDOUBLE();
            if (randdouble <= 0.5) shortestDistance = numberOfFormulaUnits - formulaUnitsList.at(i);
          }
          // We convert to int here to prevent an ambiguous abs() call when
          // compiling with AppleClang
          if (abs(shortestDistance) > abs((int)(numberOfFormulaUnits - formulaUnitsList.at(i)))) {
            shortestDistance = numberOfFormulaUnits - formulaUnitsList.at(i);
          }
        }

        // Shortest distance is positive if we want to decrease and negative if we want to increase
        uint closestFU = numberOfFormulaUnits - shortestDistance;

        // Adjust all the targetXtalCounts to make the closest number of formula units
        for (int i = 0; i < targetXtalCounts.size(); i++) {
          targetXtalCounts[i] = (targetXtalCounts.at(i) / numberOfFormulaUnits) * closestFU;
        }
      }
    }

    // And targetXtalCounts should now have the correct desired counts for each
    // atom to produce the closest FU that is on the list!

    // Get differences --
    // a (+) value in deltas indicates that more atoms are needed in nxtal
    // a (-) value indicates less are needed.
    for (int i = 0; i < targetXtalCounts.size(); i++)
      deltas.append(targetXtalCounts.at(i) - nxtalCounts.at(i));
    // Correct for differences by inserting atoms from
    // discarded portions of parents or removing random atoms.
    int delta;
    for (int i = 0; i < deltas.size(); i++) {
      delta = deltas.at(i);
      //qDebug() << "Delta = " << delta;
      if (delta == 0) continue;
      while (delta < 0) { //qDebug() << "Too many " << xtalAtoms.at(i) << "!";
        // Randomly delete atoms from nxtal;
        // 1 in X chance of each atom being deleted, where
        // X is the total number of that atom type in nxtal.
        QList<Atom*> atomList = nxtal->atoms();
        for (int j = 0; j < atomList.size(); j++) {
          if (atomList.at(j)->atomicNumber() == OpenBabel::etab.GetAtomicNum(xtalAtoms.at(i).toStdString().c_str())) {
            // atom at j is the type that needs to be deleted.
            if (RANDDOUBLE() < 1.0/static_cast<double>(nxtalCounts.at(i))) {
              // If the odds are right, delete the atom and break loop to recheck condition.
              nxtal->removeAtom(atomList.at(j)); // removeAtom(Atom*) takes care of deleting pointer.
              delta++;
              break;
            }
          }
        }
      }
      while (delta > 0) { //qDebug() << "Too few " << xtalAtoms.at(i) << "!";

        // For FUcrossover, we will try to add the atom randomly at first
        // If it fails we will try the traditional method
        if(nxtal->addAtomRandomly(OpenBabel::etab.GetAtomicNum(xtalAtoms.at(i).toStdString().c_str()), comp)) {
        delta--;
        break;
        }

        // Randomly add atoms from discarded cuts of parent xtals;
        // 1 in X chance of each atom being added, where
        // X is the total number of atoms of that species in the parent.
        //
        // First, pick the parent. 50/50 chance for each:

        uint parent;
        if (RANDDOUBLE() < 0.5) parent = 1;
        else parent = 2;
        if (parent == 1) {
          for (int j = 0; j < fracCoordsList1.size(); j++) { // size may be different for different parents
            if (
                // if atom at j is the type that needs to be added,
                ( atomList1.at(j)->atomicNumber() == OpenBabel::etab.GetAtomicNum(xtalAtoms.at(i).toStdString().c_str()))

                &&
                // and atom is in the discarded region of the cut,
                ( fracCoordsList1.at(j)[0] > cutVal1 )

                &&
                // and the odds favor it, add the atom to nxtal
                ( RANDDOUBLE() < 1.0/static_cast<double>(targetXtalCounts.at(i)) )
                ) {
              Atom* newAtom = nxtal->addAtom();
              newAtom->setAtomicNumber(atomList1.at(j)->atomicNumber());
              newAtom->setPos(nxtal->fracToCart(fracCoordsList1.at(j)));
              delta--;
              break;
            }
          }
        }
        else if (parent == 2) {
          for (int j = 0; j < fracCoordsList2.size(); j++) { // size may be different for different parents
            if (
                // if atom at j is the type that needs to be added,
                ( atomList2.at(j)->atomicNumber() == OpenBabel::etab.GetAtomicNum(xtalAtoms.at(i).toStdString().c_str()))

                &&
                // and atom is in the discarded region of the cut,
                ( fracCoordsList2.at(j)[0] > cutVal2 )

                &&
                // and the odds favor it, add the atom to nxtal
                ( RANDDOUBLE() < 1.0/static_cast<double>(targetXtalCounts.at(i)) )
                ) {
              Atom* newAtom = nxtal->addAtom();
              newAtom->setAtomicNumber(atomList2.at(j)->atomicNumber());
              // Reflect across plane perpendicular to cutVal axis
              QList<Vector3d> tempFracCoordsList2 = fracCoordsList2;
              tempFracCoordsList2[j][0] = 1 - fracCoordsList2.at(j)[0];
              newAtom->setPos(nxtal->fracToCart(tempFracCoordsList2.at(j)));
              delta--;
              break;
            }
          }
        }
      }
    }

    QList<Vector3d> nFracCoordsList;
    QList<Atom*> nAtomList      = nxtal->atoms();
    for (int i = 0; i < nAtomList.size(); i++) {
      nFracCoordsList.append(nxtal->cartToFrac(*(nAtomList.at(i)->pos())));
      // qDebug() << nAtomList.at(i)->atomicNumber() << " " << nFracCoordsList.at(i)[0] << " " << nFracCoordsList.at(i)[1] << " " << nFracCoordsList.at(i)[2];
    }

    // Done!
    nxtal->wrapAtomsToCell();
    nxtal->setStatus(Xtal::WaitingForOptimization);
    return nxtal;
  }

  Xtal* XtalOptGenetic::stripple(Xtal* xtal,
                                 double sigma_lattice_min, double sigma_lattice_max,
                                 double rho_min, double rho_max,
                                 uint eta, uint mu,
                                 double &sigma_lattice,
                                 double &rho) {
    INIT_RANDOM_GENERATOR();

    // lock parent xtal and copy into return xtal
    Xtal *nxtal = new Xtal;
    nxtal->setCellInfo(xtal->OBUnitCell()->GetCellMatrix());

    QReadLocker locker (xtal->lock());
    Atom *atm;
    for (uint i = 0; i < xtal->numAtoms(); i++) {
      atm = nxtal->addAtom();
      atm->setAtomicNumber(xtal->atom(i)->atomicNumber());
      atm->setPos(xtal->atom(i)->pos());
    }

    sigma_lattice = 0;
    rho = 0;

    // Note that this will repeat until EITHER sigma OR rho is greater
    // than its respective minimum value, not both
    do {
      sigma_lattice = RANDDOUBLE();
      sigma_lattice *= sigma_lattice_max;
      rho = RANDDOUBLE();
      rho *= rho_max;
      // If values are fixed (min==max), check to see if they need to
      // be set manually, since it is unlikely that the above
      // randomization will produce an acceptable value. Randomize
      // which parameter to check to avoid biasing setting one value
      // over the other.
      double r = RANDDOUBLE();
      if (r < 0.5 &&
          sigma_lattice_min == sigma_lattice_max &&
          rho < rho_min) {
        sigma_lattice = sigma_lattice_max;
      }
      if (r >= 0.5 &&
          rho_min == rho_max &&
          sigma_lattice < sigma_lattice_min) {
        rho = rho_max;
      }
    } while (sigma_lattice < sigma_lattice_min && rho < rho_min);

    XtalOptGenetic::strain(nxtal, sigma_lattice);
    XtalOptGenetic::ripple(nxtal, rho, eta, mu);

    nxtal->setStatus(Xtal::WaitingForOptimization);
    return nxtal;
  }

  Xtal* XtalOptGenetic::permustrain(Xtal* xtal, double sigma_lattice_max, uint exchanges, double &sigma_lattice) {
    INIT_RANDOM_GENERATOR();
    // lock parent xtal for reading
    QReadLocker locker (xtal->lock());

    // Copy info over from parent to new xtal
    Xtal *nxtal = new Xtal;
    nxtal->setCellInfo(xtal->OBUnitCell()->GetCellMatrix());
    QWriteLocker nxtalLocker (nxtal->lock());
    QList<Atom*> atoms = xtal->atoms();
    for (int i = 0; i < atoms.size(); i++) {
      Atom* atom = nxtal->addAtom();
      atom->setAtomicNumber(atoms.at(i)->atomicNumber());
      atom->setPos(atoms.at(i)->pos());
    }

    // Perform lattice strain
    sigma_lattice = sigma_lattice_max * RANDDOUBLE();
    XtalOptGenetic::strain(nxtal, sigma_lattice);
    XtalOptGenetic::exchange(nxtal, exchanges);

    // Clean up
    nxtal->wrapAtomsToCell();
    nxtal->setStatus(Xtal::WaitingForOptimization);

    return nxtal;
  }

  void XtalOptGenetic::exchange(Xtal *xtal, uint exchanges) {
    INIT_RANDOM_GENERATOR();
    // Check that there is more than 1 atom type present.
    // If not, print a warning and return input xtal:
    if (xtal->getSymbols().size() <= 1) {
      qWarning()
        << "WARNING: *********************************************************************" << endl
        << "WARNING: * Cannot perform exchange with fewer than 2 atomic species present. *" << endl
        << "WARNING: *********************************************************************";
      return;
    }

    QList<Atom*> atoms = xtal->atoms();
    // Swap <exchanges> number of atoms
    for (uint ex = 0; ex < exchanges; ex++) {
      // Generate some indicies
      uint index1 = 0, index2 = 0;
      // Make sure we're swapping different atom types
      while (atoms.at(index1)->atomicNumber() == atoms.at(index2)->atomicNumber()) {
        index1 = index2 = 0;
        while (index1 == index2) {
          index1 = static_cast<uint>(RANDDOUBLE() * atoms.size());
          index2 = static_cast<uint>(RANDDOUBLE() * atoms.size());
        }
      }
      // Swap the atoms
      const Vector3d tmp = *(atoms.at(index1)->pos());
      atoms.at(index1)->setPos(*(atoms.at(index2)->pos()));
      atoms.at(index2)->setPos(tmp);
    }
    return;
  }

  void XtalOptGenetic::strain(Xtal *xtal, double sigma_lattice) {
    INIT_RANDOM_GENERATOR();
    // Build Voight strain matrix
    double volume = xtal->getVolume();
    matrix3x3 strainM;
    const double NV_MAGICCONST = 4 * exp(-0.5)/sqrt(2.0);
    for (uint row = 0; row < 3; row++) {
      for (uint col = row; col < 3; col++) {
        // Generate random value from a Gaussian distribution.
        // Ported from Python's standard random library.
        // Uses Kinderman and Monahan method. Reference: Kinderman,
        // A.J. and Monahan, J.F., "Computer generation of random
        // variables using the ratio of uniform deviates", ACM Trans
        // Math Software, 3, (1977), pp257-260.
        // mu = 0, sigma = sigma_lattice
        double z;
        while (true) {
          double u1 = RANDDOUBLE();
          double u2 = 1.0 - RANDDOUBLE();
          if (u2 == 0.0) continue; // happens a _lot_ with MSVC...
          z = NV_MAGICCONST*(u1-0.5)/u2;
          double zz = z*z/4.0;
          if (zz <= -log(u2))
            break;
        }
        double epsilon = z*sigma_lattice;
        // qDebug() << "epsilon(" << row << ", " << col << ") = " << epsilon;
        if (col == row) {
          strainM.Set(row, col, 1 + epsilon);
        } else {
          strainM.Set(row, col, epsilon/2.0);
          strainM.Set(col, row, epsilon/2.0);
        }
      }
    }

    // Store fractional coordinates
    QList<Atom*> atomList       = xtal->atoms();
    QList<Vector3d> fracCoordsList;
    for (int i = 0; i < atomList.size(); i++)
      fracCoordsList.append(xtal->cartToFrac(*(atomList.at(i)->pos())));

    // Apply strain
    xtal->setCellInfo(xtal->OBUnitCell()->GetCellMatrix() * strainM);

    // Reset coordinates
    for (int i = 0; i < atomList.size(); i++)
      atomList.at(i)->setPos(xtal->fracToCart(fracCoordsList.at(i)));

    // Rescale volume
    xtal->setVolume(volume);
    xtal->wrapAtomsToCell();
  }

  void XtalOptGenetic::ripple(Xtal* xtal, double rho, uint eta, uint mu) {
    INIT_RANDOM_GENERATOR();
    double phase1 = RANDDOUBLE() * 2 * M_PI;
    double phase2 = RANDDOUBLE() * 2 * M_PI;

    // Get random direction to shift atoms (x=0, y=1, z=2)
    int shiftAxis = 3, axis1, axis2;
    while (shiftAxis == 3)
      shiftAxis = static_cast<uint>(RANDDOUBLE() * 3);
    switch (shiftAxis) {
    case 0:
      axis1 = 1;
      axis2 = 2;
      break;
    case 1:
      axis1 = 0;
      axis2 = 2;
      break;
    case 2:
      axis1 = 0;
      axis2 = 1;
      break;
    default:
      qWarning() << "Something is wrong in the periodic displacement operator -- shiftAxis should not be " << shiftAxis;
      break;
    }

    QList<Atom*> atoms = xtal->atoms();
    QList<Vector3d> fracCoordsList;

    for (int i = 0; i < atoms.size(); i++)
      fracCoordsList.append(xtal->cartToFrac(*(atoms.at(i)->pos())));

    Vector3d v;
    double shift;
    for (int i = 0; i < fracCoordsList.size(); i++) {
      v = fracCoordsList.at(i);
      shift = rho*
        cos(
            2*M_PI*eta*v[axis1] + phase1
            )*
        cos(
            2*M_PI*mu*v[axis2] + phase2
            );
      //qDebug() << "Before: " << v.x() << " " << v.y() << " " << v.z();
      v[shiftAxis] += shift;
      //qDebug() << "After:  " << v.x() << " " << v.y() << " " << v.z();
      fracCoordsList[i] = v;
    }

    Atom *atm;
    for (int i = 0; i < atoms.size(); i++) {
      atm = atoms.at(i);
      atm->setPos(xtal->fracToCart(fracCoordsList.at(i)));
    }
    xtal->wrapAtomsToCell();
  }

} // end namespace XtalOpt
