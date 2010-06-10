/**********************************************************************
  XtalOpt - Tools for advanced crystal optimization

  Copyright (C) 2009-2010 by David Lonie

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.openmolecules.net/>

  This library is free software; you can redistribute it and/or modify
  it under the terms of the GNU Library General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public icense for more details.
 ***********************************************************************/

#ifndef TAB_INIT_H
#define TAB_INIT_H

#include "ui_tab_init.h"

class QMutex;

namespace XtalOpt {
  class XtalOptDialog;
  class XtalOpt;

  class TabInit : public QObject
  {
    Q_OBJECT

  public:
    explicit TabInit( XtalOptDialog *parent, XtalOpt *p );
    virtual ~TabInit();

    QWidget *getTabWidget() {return m_tab_widget;};

    enum CompositionColumns {
      CC_AtomicSymbol = 0,
      CC_Constrain,
      CC_X,
      CC_Y,
      CC_Z
    };

  public slots:
    // used to lock bits of the GUI that shouldn't be change when a
    // session starts. This will also pass the call on to all tabs.
    void lockGUI();
    void readSettings(const QString &filename = "");
    void writeSettings(const QString &filename = "");
    void updateGUI();
    void disconnectGUI();
    void getComposition(const QString & str);
    void updateComposition();
    void updateDimensions();
    void clearCompositionTable();
    void cleanUpCompositionTable();
    void addRowToCompositionTable(const QString & atom, bool constrain = false, double x = 0.0, double y = 0.0, double z = 0.0);

  signals:

  private:
    QMutex *m_compTableMutex;

    Ui::Tab_Init ui;
    QWidget *m_tab_widget;
    XtalOptDialog *m_dialog;
    XtalOpt *m_opt;
  };
}

#endif
