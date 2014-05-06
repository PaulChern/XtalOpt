/**********************************************************************
  XtalOpt - Tools for advanced crystal optimization

  Copyright (C) 2009-2011 by David Lonie

  This library is free software; you can redistribute it and/or modify
  it under the terms of the GNU Library General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 ***********************************************************************/

#include <xtalopt/ui/tab_init.h>

#include <xtalopt/xtalopt.h>

#include <QtCore/QSettings>

#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QTableWidgetItem>
#include <QtGui/QMessageBox>

#include "dialog.h"

namespace XtalOpt {

  TabInit::TabInit( XtalOptDialog *parent, XtalOpt *p ) :
    AbstractTab(parent, p)
  {
    ui.setupUi(m_tab_widget);

    // composition connections
    connect(ui.edit_composition, SIGNAL(textChanged(QString)),
            this, SLOT(getComposition(QString)));
    connect(ui.edit_composition, SIGNAL(editingFinished()),
            this, SLOT(updateComposition()));

    // unit cell dimension connections
    connect(ui.spin_a_min, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_b_min, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_c_min, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_alpha_min, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_beta_min, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_gamma_min, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_vol_min, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_a_max, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_b_max, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_c_max, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_alpha_max, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_beta_max, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_gamma_max, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_vol_max, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.spin_fixedVolume, SIGNAL(editingFinished()),
            this, SLOT(updateDimensions()));
    connect(ui.cb_fixedVolume, SIGNAL(toggled(bool)),
            this, SLOT(updateDimensions()));
    connect(ui.spin_scaleFactor, SIGNAL(valueChanged(double)),
            this, SLOT(updateDimensions()));
    connect(ui.spin_minRadius, SIGNAL(valueChanged(double)),
            this, SLOT(updateDimensions()));
    connect(ui.cb_interatomicDistanceLimit, SIGNAL(toggled(bool)),
            this, SLOT(updateDimensions()));
    // ZF
    connect(ui.cb_customIAD, SIGNAL(toggled(bool)),
            this, SLOT(updateDimensions()));
    connect(ui.cb_checkStepOpt, SIGNAL(toggled(bool)),
            this, SLOT(updateDimensions()));
    connect(ui.spin_maxRadius, SIGNAL(valueChanged(double)),
            this, SLOT(updateDimensions()));
    connect(ui.table_IAD, SIGNAL(itemSelectionChanged()),
            this, SLOT(updateMinIAD()));

    QHeaderView *horizontal = ui.table_comp->horizontalHeader();
    horizontal->setResizeMode(QHeaderView::ResizeToContents);

    initialize();
  }

  TabInit::~TabInit()
  {
  }

  void TabInit::writeSettings(const QString &filename)
  {
    SETTINGS(filename);

    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    settings->beginGroup("xtalopt/init/");

    const int VERSION = 2;
    settings->setValue("version",VERSION);

    settings->setValue("limits/a/min",        xtalopt->a_min);
    settings->setValue("limits/b/min",        xtalopt->b_min);
    settings->setValue("limits/c/min",        xtalopt->c_min);
    settings->setValue("limits/a/max",        xtalopt->a_max);
    settings->setValue("limits/b/max",        xtalopt->b_max);
    settings->setValue("limits/c/max",        xtalopt->c_max);
    settings->setValue("limits/alpha/min",    xtalopt->alpha_min);
    settings->setValue("limits/beta/min",     xtalopt->beta_min);
    settings->setValue("limits/gamma/min",    xtalopt->gamma_min);
    settings->setValue("limits/alpha/max",    xtalopt->alpha_max);
    settings->setValue("limits/beta/max",     xtalopt->beta_max);
    settings->setValue("limits/gamma/max",    xtalopt->gamma_max);
    settings->setValue("limits/volume/min",   xtalopt->vol_min);
    settings->setValue("limits/volume/max",   xtalopt->vol_max);
    settings->setValue("limits/volume/fixed", xtalopt->vol_fixed);
    settings->setValue("limits/scaleFactor",  xtalopt->scaleFactor);
    settings->setValue("limits/minRadius",    xtalopt->minRadius);
    settings->setValue("using/fixedVolume",   xtalopt->using_fixed_volume);
    settings->setValue("using/interatomicDistanceLimit",
                       xtalopt->using_interatomicDistanceLimit);
    // ZF
    settings->setValue("using/customIAD",
                        xtalopt->using_customIAD);
    settings->setValue("limits/maxRadius",    xtalopt->maxRadius);
    settings->setValue("using/checkStepOpt",
                        xtalopt->using_checkStepOpt);



    // Composition
    // We only want to save POTCAR info and Composition to the resume
    // file, not the main config file, so only dump the data here if
    // we are given a filename and it contains the string
    // "xtalopt.state"
    if (!filename.isEmpty() && filename.contains("xtalopt.state")) {
      settings->beginWriteArray("composition");
      QList<uint> keys = xtalopt->comp.keys();
      for (int i = 0; i < keys.size(); i++) {
        settings->setArrayIndex(i);
        settings->setValue("atomicNumber", keys.at(i));
        settings->setValue("quantity",
                           xtalopt->comp.value(keys.at(i)).quantity);
        settings->setValue("minRadius",
                           xtalopt->comp.value(keys.at(i)).minRadius);
      }
      settings->endArray();
    }

    // ZF
    if (xtalopt->using_customIAD==true) {
        unsigned int length = ui.table_IAD->rowCount();
        settings->beginWriteArray("customIAD");
        for (uint i = 0; i < length; i++){
            settings->setArrayIndex(i);
            QString symbol1 = ui.table_IAD->item(i, IC_SYMBOL1)->text();
            int atomicNum1 = OpenBabel::etab.GetAtomicNum(symbol1.trimmed().toStdString().c_str());
            QString symbol2 = ui.table_IAD->item(i, IC_SYMBOL2)->text();
            int atomicNum2 = OpenBabel::etab.GetAtomicNum(symbol2.trimmed().toStdString().c_str());
        
            settings->setValue("atomicNumber1",     atomicNum1);
            settings->setValue("atomicNumber2",     atomicNum2);
            settings->setValue("minInteratomicDist",     xtalopt->interComp[qMakePair<int, int>(atomicNum1, atomicNum2)].minIAD);
            settings->setValue("maxInteratomicDist",     xtalopt->interComp[qMakePair<int, int>(atomicNum1, atomicNum2)].maxIAD);
        }
        settings->endArray();
    }
    //
    //

    settings->endGroup();

    DESTROY_SETTINGS(filename);
  }

  void TabInit::readSettings(const QString &filename)
  {
    SETTINGS(filename);

    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    settings->beginGroup("xtalopt/init/");
    int loadedVersion = settings->value("version", 0).toInt();

    ui.spin_a_min->setValue(		settings->value("limits/a/min",		3).toDouble()   );
    ui.spin_b_min->setValue(		settings->value("limits/b/min",		3).toDouble()   );
    ui.spin_c_min->setValue(		settings->value("limits/c/min",		3).toDouble()   );
    ui.spin_a_max->setValue(		settings->value("limits/a/max",		10).toDouble()  );
    ui.spin_b_max->setValue(		settings->value("limits/b/max",		10).toDouble()  );
    ui.spin_c_max->setValue(		settings->value("limits/c/max",		10).toDouble()  );
    ui.spin_alpha_min->setValue(	settings->value("limits/alpha/min",	60).toDouble()  );
    ui.spin_beta_min->setValue(		settings->value("limits/beta/min",	60).toDouble()  );
    ui.spin_gamma_min->setValue(	settings->value("limits/gamma/min",	60).toDouble()  );
    ui.spin_alpha_max->setValue(	settings->value("limits/alpha/max",	120).toDouble() );
    ui.spin_beta_max->setValue(		settings->value("limits/beta/max",	120).toDouble() );
    ui.spin_gamma_max->setValue(	settings->value("limits/gamma/max",	120).toDouble() );
    ui.spin_vol_min->setValue(		settings->value("limits/volume/min",	1).toDouble()   );
    ui.spin_vol_max->setValue(		settings->value("limits/volume/max",	100000).toDouble());
    ui.spin_fixedVolume->setValue(	settings->value("limits/volume/fixed",	500).toDouble()	);
    ui.spin_scaleFactor->setValue(	settings->value("limits/scaleFactor",0.5).toDouble());
    ui.spin_minRadius->setValue(	  settings->value("limits/minRadius",0.25).toDouble());
    ui.cb_fixedVolume->setChecked(	settings->value("using/fixedVolume").toBool()	);
    ui.cb_interatomicDistanceLimit->setChecked(	settings->value("using/interatomicDistanceLimit").toBool());
    
    // ZF
    ui.cb_customIAD->setChecked( settings->value("using/customIAD").toBool());
    ui.spin_maxRadius->setValue(      settings->value("limits/maxRadius", 3.00).toDouble());
    ui.cb_checkStepOpt->setChecked( settings->value("using/checkStepOpt").toBool());


    // Composition
    if (!filename.isEmpty()) {
      int size = settings->beginReadArray("composition");
      xtalopt->comp = QHash<uint,XtalCompositionStruct> ();
      for (int i = 0; i < size; i++) {
        settings->setArrayIndex(i);
        uint atomicNum, quantity;
        XtalCompositionStruct entry;
        atomicNum = settings->value("atomicNumber").toUInt();
        quantity = settings->value("quantity").toUInt();
        entry.quantity = quantity;
        xtalopt->comp.insert(atomicNum, entry);
      }
      this->updateMinRadii();
      settings->endArray();
    }

    //ZF
    if (xtalopt->using_customIAD==true) {
        int size = settings->beginReadArray("customIAD");
        xtalopt->interComp = QHash<QPair<int, int>, IAD> ();
        for (int i = 0; i < size; i++){
            settings->setArrayIndex(i);
            int atomicNum1, atomicNum2;
            IAD entry;
            atomicNum1 = settings->value("atomicNumber1").toInt();
            atomicNum2 = settings->value("atomicNumber2").toInt();
            double minInteratomicDist = settings->value("minInteratomicDist").toDouble();
            double maxInteratomicDist = settings->value("maxInteratomicDist").toDouble();
            entry.minIAD = minInteratomicDist;
            entry.maxIAD = maxInteratomicDist;
            xtalopt->interComp[qMakePair<int, int>(atomicNum1, atomicNum2)] = entry;
        }
        this->updateCompositionTable();
        this->updateMinIAD();
        settings->endArray();
    }
    //
    //

    settings->endGroup();

    // Update config data
    switch (loadedVersion) {
    case 0:
    case 1:
      ui.cb_interatomicDistanceLimit->setChecked(
            settings->value("using/shortestInteratomicDistance",false).toBool());
      ui.cb_customIAD->setChecked(
            settings->value("using/customIAD",false).toBool());
    default:
      break;
    }

    // Enact changesSetup templates
    updateDimensions();
    updateGUI();
  }

  void TabInit::updateGUI()
  {
    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    ui.spin_a_min->setValue(       xtalopt->a_min);
    ui.spin_b_min->setValue(       xtalopt->b_min);
    ui.spin_c_min->setValue(       xtalopt->c_min);
    ui.spin_a_max->setValue(       xtalopt->a_max);
    ui.spin_b_max->setValue(       xtalopt->b_max);
    ui.spin_c_max->setValue(       xtalopt->c_max);
    ui.spin_alpha_min->setValue(   xtalopt->alpha_min);
    ui.spin_beta_min->setValue(    xtalopt->beta_min);
    ui.spin_gamma_min->setValue(   xtalopt->gamma_min);
    ui.spin_alpha_max->setValue(   xtalopt->alpha_max);
    ui.spin_beta_max->setValue(    xtalopt->beta_max);
    ui.spin_gamma_max->setValue(   xtalopt->gamma_max);
    ui.spin_vol_min->setValue(     xtalopt->vol_min);
    ui.spin_vol_max->setValue(     xtalopt->vol_max);
    ui.spin_fixedVolume->setValue( xtalopt->vol_fixed);
    ui.spin_scaleFactor->setValue( xtalopt->scaleFactor);
    ui.spin_minRadius->setValue(   xtalopt->minRadius);
    ui.cb_fixedVolume->setChecked( xtalopt->using_fixed_volume);
    ui.cb_interatomicDistanceLimit->setChecked(
          xtalopt->using_interatomicDistanceLimit);
    ui.cb_customIAD->setChecked(   xtalopt->using_customIAD);
   updateComposition();
  }

  void TabInit::lockGUI()
  {
    ui.edit_composition->setDisabled(true);
    ui.table_IAD->setDisabled(true);
  }

  void TabInit::getComposition(const QString &str)
  {
    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    QHash<QPair<int, int>, IAD> interComp;
    QHash<uint, XtalCompositionStruct> comp;
    QString symbol;
    QString symbol2;
    unsigned int atomicNum;
    unsigned int atomicNum2;
    unsigned int quantity;
    QStringList symbolList;
    QStringList quantityList;

    // Parse numbers between letters
    symbolList = str.split(QRegExp("[0-9]"), QString::SkipEmptyParts);
    // Parse letters between numbers
    quantityList = str.split(QRegExp("[A-Z,a-z]"), QString::SkipEmptyParts);

    xtalopt->testingMode = (str.contains("testingMode")) ? true : false;

    // Use the shorter of the lists for the length
    unsigned int length = (symbolList.size() < quantityList.size())
        ? symbolList.size() : quantityList.size();

    if ( length == 0 ) {
      xtalopt->comp.clear();
      this->updateCompositionTable();
      return;
    }

    // Build hash
    for (uint i = 0; i < length; i++){
      symbol    = symbolList.at(i);
      atomicNum = OpenBabel::etab.GetAtomicNum(
            symbol.trimmed().toStdString().c_str());
      quantity	= quantityList.at(i).toUInt();

      if (symbol.contains("nRunsStart")) {
        xtalopt->test_nRunsStart = quantity;
        continue;
      }
      if (symbol.contains("nRunsEnd")) {
        xtalopt->test_nRunsEnd = quantity;
        continue;
      }
      if (symbol.contains("nStructs")) {
        xtalopt->test_nStructs = quantity;
        continue;
      }

      // Validate symbol
      if (!atomicNum) continue; // Invalid symbol entered

      // Add to hash
      if (!comp.keys().contains(atomicNum)) {
        XtalCompositionStruct entry;
        entry.quantity = 0;
        entry.minRadius = 0.0;
        comp[atomicNum] = entry; // initialize if needed
      }

      comp[atomicNum].quantity += quantity;
      
      // ZF
        for (uint j = 0; j < length; j++){
            symbol2    = symbolList.at(j);
            atomicNum2 = OpenBabel::etab.GetAtomicNum(
                symbol2.trimmed().toStdString().c_str());
        
        // Validate symbol
        // if (!atomicNum1) continue; // Invalid symbol entered
        // if (!atomicNum2) continue; // Invalid symbol entered
    
            // Add twice to hash (if the two atoms are different)
            if (!interComp.contains(qMakePair<int, int>(atomicNum, atomicNum2))) {
                IAD entry;
                entry.minIAD = OpenBabel::etab.GetCovalentRad(atomicNum) + OpenBabel::etab.GetCovalentRad(atomicNum2);
                entry.maxIAD = entry.minIAD * 2.0;
                interComp[qMakePair<int, int>(atomicNum, atomicNum2)] = entry;
            }
            if (atomicNum!=atomicNum2){
                if (!interComp.contains(qMakePair<int, int>(atomicNum2, atomicNum))) {
                    IAD entry;
                    entry.minIAD = OpenBabel::etab.GetCovalentRad(atomicNum) + OpenBabel::etab.GetCovalentRad(atomicNum2);
                    entry.maxIAD = entry.minIAD * 2.0;
                    interComp[qMakePair<int, int>(atomicNum2, atomicNum)] = entry;
                }
            }
        }
        //
        //
    }

    xtalopt->interComp = interComp; 
    xtalopt->comp = comp;

    this->updateMinRadii();
    // ZF
    this->updateMinIAD();
    //
    this->updateCompositionTable();
 

 }

  void TabInit::updateCompositionTable()
  {
    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    QList<unsigned int> keys = xtalopt->comp.keys();
    qSort(keys);

    // Adjust table size:
    int numRows = keys.size();
    ui.table_comp->setRowCount(numRows);
    int numRows2 = keys.size();
         for(int j = numRows2-1; j > 0; j--){
            numRows2=numRows2+j;
        }
   int z = 0;
    for (int i = 0; i < numRows; i++) {
      unsigned int atomicNum = keys.at(i);

      QString symbol	= QString(OpenBabel::etab.GetSymbol(atomicNum));
      unsigned int quantity  = xtalopt->comp[atomicNum].quantity;
      double mass	= OpenBabel::etab.GetMass(atomicNum);
      double minRadius = xtalopt->comp[atomicNum].minRadius;

      QTableWidgetItem *symbolItem =
          new QTableWidgetItem(symbol);
      QTableWidgetItem *atomicNumItem =
          new QTableWidgetItem(QString::number(atomicNum));
      QTableWidgetItem *quantityItem =
          new QTableWidgetItem(QString::number(quantity));
      QTableWidgetItem *massItem =
          new QTableWidgetItem(QString::number(mass));
      QTableWidgetItem *minRadiusItem;
      if (xtalopt->using_interatomicDistanceLimit)
        minRadiusItem = new QTableWidgetItem(QString::number(minRadius));
      else
        minRadiusItem = new QTableWidgetItem(tr("n/a"));

      ui.table_comp->setItem(i, CC_SYMBOL, symbolItem);
      ui.table_comp->setItem(i, CC_ATOMICNUM, atomicNumItem);
      ui.table_comp->setItem(i, CC_QUANTITY, quantityItem);
      ui.table_comp->setItem(i, CC_MASS, massItem);
      ui.table_comp->setItem(i, CC_MINRADIUS, minRadiusItem);

      //ZF
      if (ui.cb_customIAD->isChecked()) {
        ui.table_IAD->setRowCount(numRows2);
         
        for (int k = i; k < numRows; k++) {
            unsigned int atomicNum2 = keys.at(k);
            
            QString symbol1 = QString(OpenBabel::etab.GetSymbol(atomicNum));
            QString symbol2 = QString(OpenBabel::etab.GetSymbol(atomicNum2));
            
            QTableWidgetItem *symbol1Item =
                new QTableWidgetItem(symbol1);
            QTableWidgetItem *symbol2Item =
                new QTableWidgetItem(symbol2);           

            ui.table_IAD->setItem(z, IC_SYMBOL1, symbol1Item);
            ui.table_IAD->setItem(z, IC_SYMBOL2, symbol2Item);
           
            QString minIAD = QString::number(xtalopt->interComp[qMakePair<int, int>(atomicNum, atomicNum2)].minIAD, 'f', 3);
            QString maxIAD = QString::number(xtalopt->interComp[qMakePair<int, int>(atomicNum, atomicNum2)].maxIAD, 'f', 3);
            QTableWidgetItem *minIADItem =
                new QTableWidgetItem(minIAD);
            QTableWidgetItem *maxIADItem =
                new QTableWidgetItem(maxIAD);
            ui.table_IAD->setItem(z, IC_MINIAD, minIADItem);
            ui.table_IAD->setItem(z, IC_MAXIAD, maxIADItem);

            z++;
        }
      }
    }
  }

  void TabInit::updateComposition()
  {
    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    QList<uint> keys = xtalopt->comp.keys();
    qSort(keys);
    QString tmp;
    QTextStream str (&tmp);
    for (int i = 0; i < keys.size(); i++) {
      uint q = xtalopt->comp.value(keys.at(i)).quantity;
      str << OpenBabel::etab.GetSymbol(keys.at(i)) << q << " ";
    }
    if (xtalopt->testingMode) {
      str << "nRunsStart" << xtalopt->test_nRunsStart << " "
          << "nRunsEnd" << xtalopt->test_nRunsEnd << " "
          << "nStructs" << xtalopt->test_nStructs << " "
          << "testingMode ";
    }
    ui.edit_composition->setText(tmp.trimmed());
  }

  void TabInit::updateDimensions()
  {
    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    // Check for conflicts -- favor lower value
    if (ui.spin_a_min->value()		> ui.spin_a_max->value())	ui.spin_a_max->setValue(	ui.spin_a_min->value());
    if (ui.spin_b_min->value()          > ui.spin_b_max->value())	ui.spin_b_max->setValue(	ui.spin_b_min->value());
    if (ui.spin_c_min->value()          > ui.spin_c_max->value())	ui.spin_c_max->setValue(	ui.spin_c_min->value());
    if (ui.spin_alpha_min->value()      > ui.spin_alpha_max->value())	ui.spin_alpha_max->setValue(	ui.spin_alpha_min->value());
    if (ui.spin_beta_min->value()       > ui.spin_beta_max->value())	ui.spin_beta_max->setValue(     ui.spin_beta_min->value());
    if (ui.spin_gamma_min->value()      > ui.spin_gamma_max->value())	ui.spin_gamma_max->setValue(	ui.spin_gamma_min->value());
    if (ui.spin_vol_min->value()        > ui.spin_vol_max->value())	ui.spin_vol_max->setValue(	ui.spin_vol_min->value());

    // Assign variables
    xtalopt->a_min		= ui.spin_a_min->value();
    xtalopt->b_min		= ui.spin_b_min->value();
    xtalopt->c_min		= ui.spin_c_min->value();
    xtalopt->alpha_min	= ui.spin_alpha_min->value();
    xtalopt->beta_min	= ui.spin_beta_min->value();
    xtalopt->gamma_min	= ui.spin_gamma_min->value();
    xtalopt->vol_min		= ui.spin_vol_min->value();

    xtalopt->a_max		= ui.spin_a_max->value();
    xtalopt->b_max		= ui.spin_b_max->value();
    xtalopt->c_max		= ui.spin_c_max->value();
    xtalopt->alpha_max	= ui.spin_alpha_max->value();
    xtalopt->beta_max	= ui.spin_beta_max->value();
    xtalopt->gamma_max	= ui.spin_gamma_max->value();
    xtalopt->vol_max		= ui.spin_vol_max->value();

    xtalopt->using_fixed_volume = ui.cb_fixedVolume->isChecked();
    xtalopt->vol_fixed	= ui.spin_fixedVolume->value();

    if (xtalopt->scaleFactor != ui.spin_scaleFactor->value() ||
        xtalopt->minRadius   != ui.spin_minRadius->value() ||
        xtalopt->using_interatomicDistanceLimit !=
        ui.cb_interatomicDistanceLimit->isChecked()) {
      xtalopt->scaleFactor = ui.spin_scaleFactor->value();
      xtalopt->minRadius = ui.spin_minRadius->value();
      xtalopt->using_interatomicDistanceLimit =
          ui.cb_interatomicDistanceLimit->isChecked();
      this->updateCompositionTable();
      this->updateMinRadii();
    }

    // ZF
    if (xtalopt->using_customIAD != ui.cb_customIAD->isChecked()) {
        xtalopt->using_customIAD = ui.cb_customIAD->isChecked();
        this->updateMinIAD();
        this->updateCompositionTable();
    }
       if (xtalopt->maxRadius != ui.spin_maxRadius->value()) {
                xtalopt->maxRadius = ui.spin_maxRadius->value();
                   }
          if (xtalopt->using_checkStepOpt != ui.cb_checkStepOpt->isChecked()) {
                     xtalopt->using_checkStepOpt = ui.cb_checkStepOpt->isChecked();
                        }
    //
  }
  void TabInit::updateMinRadii()
  {
    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    for (QHash<unsigned int, XtalCompositionStruct>::iterator
         it = xtalopt->comp.begin(), it_end = xtalopt->comp.end();
         it != it_end; ++it) {
      it.value().minRadius = xtalopt->scaleFactor *
          OpenBabel::etab.GetCovalentRad(it.key());
      // Ensure that all minimum radii are > 0.25 (esp. H!)
      if (it.value().minRadius < xtalopt->minRadius) {
        it.value().minRadius = xtalopt->minRadius;
      }
    }
  }

  // ZF
  void TabInit::updateMinIAD()
  {
    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    QHash<QPair<int, int>, IAD> interComp;
    
    unsigned int length = ui.table_IAD->rowCount();


    for (uint i = 0; i < length; i++){
        QString symbol1 = ui.table_IAD->item(i, IC_SYMBOL1)->text();
        int atomicNum1 = OpenBabel::etab.GetAtomicNum(symbol1.trimmed().toStdString().c_str());
        QString symbol2 = ui.table_IAD->item(i, IC_SYMBOL2)->text();
        int atomicNum2 = OpenBabel::etab.GetAtomicNum(symbol2.trimmed().toStdString().c_str());
        QString strMINIAD = ui.table_IAD->item(i, IC_MINIAD)->text();
        QString strMAXIAD = ui.table_IAD->item(i, IC_MAXIAD)->text();
        double minIAD = ui.table_IAD->item(i, IC_MINIAD)->text().toDouble();
        double maxIAD = ui.table_IAD->item(i, IC_MAXIAD)->text().toDouble();
            QTableWidgetItem *minIADItem =
                new QTableWidgetItem(QString::number(minIAD, 'f', 3));
            QTableWidgetItem *maxIADItem =
                new QTableWidgetItem(QString::number(maxIAD, 'f', 3));
                ui.table_IAD->setItem(i, IC_MINIAD, minIADItem);
                ui.table_IAD->setItem(i, IC_MAXIAD, maxIADItem);

        interComp[qMakePair<int, int>(atomicNum1, atomicNum2)].minIAD = minIAD;
        interComp[qMakePair<int, int>(atomicNum1, atomicNum2)].maxIAD = maxIAD;
        xtalopt->interComp[qMakePair<int, int>(atomicNum1, atomicNum2)].minIAD = minIAD;
        xtalopt->interComp[qMakePair<int, int>(atomicNum1, atomicNum2)].maxIAD = maxIAD;

        if (atomicNum1!=atomicNum2){
            xtalopt->interComp[qMakePair<int, int>(atomicNum2, atomicNum1)].minIAD = minIAD;
            xtalopt->interComp[qMakePair<int, int>(atomicNum2, atomicNum1)].maxIAD = maxIAD;
            interComp[qMakePair<int, int>(atomicNum2, atomicNum1)].minIAD = minIAD;
            interComp[qMakePair<int, int>(atomicNum2, atomicNum1)].maxIAD = maxIAD;
        }
    }
  }
}
