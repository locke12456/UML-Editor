/********************************************************************************
** Form generated from reading UI file 'umlediter.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UMLEDITER_H
#define UI_UMLEDITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_File;
    QAction *actionOpen_File;
    QAction *actionClose;
    QAction *actionLine;
    QAction *actionAdd;
    QAction *actionRemove;
    QAction *actionSelect;
    QAction *actionBroom;
    QAction *actionAdd_package;
    QAction *actionAdd_class;
    QAction *actionAdd_association;
    QAction *actionAdd_aggregation;
    QAction *actionAdd_composition;
    QAction *actionAdd_association_end;
    QAction *actionAdd_generalization;
    QAction *actionAdd_interface;
    QAction *actionAdd_Realization;
    QAction *actionAdd_dependency;
    QAction *actionAdd_attribute;
    QAction *actionAdd_operation;
    QAction *actionAdd_data_type;
    QAction *actionAdd_uni_association;
    QAction *actionAdd_use_case;
    QAction *actionRename;
    QAction *actionGroup;
    QAction *actionUngroup;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QDockWidget *dockCenter;
    QWidget *dockWidgetContents_4;
    QGraphicsView *painter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(790, 625);
        MainWindow->setMinimumSize(QSize(790, 625));
        MainWindow->setMaximumSize(QSize(790, 625));
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName(QStringLiteral("actionNew_File"));
        QIcon icon;
        icon.addFile(QStringLiteral("resouce/Milky/Icons/64/8.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_File->setIcon(icon);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("resouce/Milky/Icons/64/119.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_File->setIcon(icon1);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("resouce/Milky/Icons/64/9.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QStringLiteral("actionLine"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("resouce/Milky/Icons/64/31.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLine->setIcon(icon3);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("resouce/Milky/Icons/64/112.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon4);
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("resouce/Milky/Icons/64/118.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon5);
        actionSelect = new QAction(MainWindow);
        actionSelect->setObjectName(QStringLiteral("actionSelect"));
        actionSelect->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral("resouce/uml/uml-_0000_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect->setIcon(icon6);
        actionBroom = new QAction(MainWindow);
        actionBroom->setObjectName(QStringLiteral("actionBroom"));
        actionBroom->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral("resouce/uml/uml-_0001_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBroom->setIcon(icon7);
        actionAdd_package = new QAction(MainWindow);
        actionAdd_package->setObjectName(QStringLiteral("actionAdd_package"));
        actionAdd_package->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral("resouce/uml/uml-_0011_11.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_package->setIcon(icon8);
        actionAdd_class = new QAction(MainWindow);
        actionAdd_class->setObjectName(QStringLiteral("actionAdd_class"));
        actionAdd_class->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral("resouce/uml/uml-_0012_12.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_class->setIcon(icon9);
        actionAdd_association = new QAction(MainWindow);
        actionAdd_association->setObjectName(QStringLiteral("actionAdd_association"));
        actionAdd_association->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral("resouce/uml/uml-_0002_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_association->setIcon(icon10);
        actionAdd_aggregation = new QAction(MainWindow);
        actionAdd_aggregation->setObjectName(QStringLiteral("actionAdd_aggregation"));
        actionAdd_aggregation->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QStringLiteral("resouce/uml/uml-_0003_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_aggregation->setIcon(icon11);
        actionAdd_composition = new QAction(MainWindow);
        actionAdd_composition->setObjectName(QStringLiteral("actionAdd_composition"));
        actionAdd_composition->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QStringLiteral("resouce/uml/uml-_0004_4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_composition->setIcon(icon12);
        actionAdd_association_end = new QAction(MainWindow);
        actionAdd_association_end->setObjectName(QStringLiteral("actionAdd_association_end"));
        actionAdd_association_end->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QStringLiteral("resouce/uml/uml-_0013_13.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_association_end->setIcon(icon13);
        actionAdd_generalization = new QAction(MainWindow);
        actionAdd_generalization->setObjectName(QStringLiteral("actionAdd_generalization"));
        actionAdd_generalization->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QStringLiteral("resouce/uml/uml-_0014_14.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_generalization->setIcon(icon14);
        actionAdd_interface = new QAction(MainWindow);
        actionAdd_interface->setObjectName(QStringLiteral("actionAdd_interface"));
        actionAdd_interface->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QStringLiteral("resouce/uml/uml-_0015_15.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_interface->setIcon(icon15);
        actionAdd_Realization = new QAction(MainWindow);
        actionAdd_Realization->setObjectName(QStringLiteral("actionAdd_Realization"));
        actionAdd_Realization->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QStringLiteral("resouce/uml/uml-_0018_18.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Realization->setIcon(icon16);
        actionAdd_dependency = new QAction(MainWindow);
        actionAdd_dependency->setObjectName(QStringLiteral("actionAdd_dependency"));
        actionAdd_dependency->setCheckable(true);
        QIcon icon17;
        icon17.addFile(QStringLiteral("resouce/uml/uml-_0005_5.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_dependency->setIcon(icon17);
        actionAdd_attribute = new QAction(MainWindow);
        actionAdd_attribute->setObjectName(QStringLiteral("actionAdd_attribute"));
        actionAdd_attribute->setCheckable(true);
        QIcon icon18;
        icon18.addFile(QStringLiteral("resouce/uml/uml-_0016_16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_attribute->setIcon(icon18);
        actionAdd_operation = new QAction(MainWindow);
        actionAdd_operation->setObjectName(QStringLiteral("actionAdd_operation"));
        actionAdd_operation->setCheckable(true);
        QIcon icon19;
        icon19.addFile(QStringLiteral("resouce/uml/uml-_0017_17.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_operation->setIcon(icon19);
        actionAdd_data_type = new QAction(MainWindow);
        actionAdd_data_type->setObjectName(QStringLiteral("actionAdd_data_type"));
        actionAdd_data_type->setCheckable(true);
        QIcon icon20;
        icon20.addFile(QStringLiteral("resouce/uml/uml-_0007_7.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_data_type->setIcon(icon20);
        actionAdd_uni_association = new QAction(MainWindow);
        actionAdd_uni_association->setObjectName(QStringLiteral("actionAdd_uni_association"));
        actionAdd_uni_association->setCheckable(true);
        QIcon icon21;
        icon21.addFile(QStringLiteral("resouce/uml/uml-_0019_19.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_uni_association->setIcon(icon21);
        actionAdd_use_case = new QAction(MainWindow);
        actionAdd_use_case->setObjectName(QStringLiteral("actionAdd_use_case"));
        actionAdd_use_case->setCheckable(true);
        QIcon icon22;
        icon22.addFile(QStringLiteral("resouce/uml/uml-_0020_20.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_use_case->setIcon(icon22);
        actionRename = new QAction(MainWindow);
        actionRename->setObjectName(QStringLiteral("actionRename"));
        actionGroup = new QAction(MainWindow);
        actionGroup->setObjectName(QStringLiteral("actionGroup"));
        actionUngroup = new QAction(MainWindow);
        actionUngroup->setObjectName(QStringLiteral("actionUngroup"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 790, 17));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockCenter = new QDockWidget(MainWindow);
        dockCenter->setObjectName(QStringLiteral("dockCenter"));
        dockCenter->setMinimumSize(QSize(790, 534));
        dockCenter->setMaximumSize(QSize(790, 534));
        dockCenter->setAutoFillBackground(true);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        painter = new QGraphicsView(dockWidgetContents_4);
        painter->setObjectName(QStringLiteral("painter"));
        painter->setGeometry(QRect(5, 1, 781, 551));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(painter->sizePolicy().hasHeightForWidth());
        painter->setSizePolicy(sizePolicy);
        painter->setMinimumSize(QSize(781, 511));
        painter->setMaximumSize(QSize(781, 551));
        dockCenter->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockCenter);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuEdit->addAction(actionRename);
        menuEdit->addAction(actionGroup);
        menuEdit->addAction(actionUngroup);
        mainToolBar->addAction(actionNew_File);
        mainToolBar->addAction(actionOpen_File);
        mainToolBar->addAction(actionClose);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionRemove);
        toolBar->addAction(actionSelect);
        toolBar->addAction(actionBroom);
        toolBar->addSeparator();
        toolBar->addAction(actionAdd_use_case);
        toolBar->addAction(actionAdd_package);
        toolBar->addAction(actionAdd_interface);
        toolBar->addAction(actionAdd_class);
        toolBar->addSeparator();
        toolBar->addAction(actionAdd_association);
        toolBar->addAction(actionAdd_uni_association);
        toolBar->addAction(actionAdd_aggregation);
        toolBar->addAction(actionAdd_composition);
        toolBar->addAction(actionAdd_association_end);
        toolBar->addAction(actionAdd_generalization);
        toolBar->addSeparator();
        toolBar->addAction(actionAdd_Realization);
        toolBar->addSeparator();
        toolBar->addAction(actionAdd_dependency);
        toolBar->addSeparator();
        toolBar->addAction(actionAdd_attribute);
        toolBar->addAction(actionAdd_operation);
        toolBar->addSeparator();
        toolBar->addAction(actionAdd_data_type);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UML Editer", 0));
        actionNew_File->setText(QApplication::translate("MainWindow", "New File", 0));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionLine->setText(QApplication::translate("MainWindow", "Line", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        actionRemove->setText(QApplication::translate("MainWindow", "Remove", 0));
        actionSelect->setText(QApplication::translate("MainWindow", "Select", 0));
        actionBroom->setText(QApplication::translate("MainWindow", "Broom", 0));
        actionAdd_package->setText(QApplication::translate("MainWindow", "Add package", 0));
        actionAdd_class->setText(QApplication::translate("MainWindow", "Add class", 0));
        actionAdd_association->setText(QApplication::translate("MainWindow", "Add association", 0));
        actionAdd_aggregation->setText(QApplication::translate("MainWindow", "Add aggregation", 0));
        actionAdd_composition->setText(QApplication::translate("MainWindow", "Add composition", 0));
        actionAdd_association_end->setText(QApplication::translate("MainWindow", "Add association end", 0));
        actionAdd_generalization->setText(QApplication::translate("MainWindow", "Add generalization", 0));
        actionAdd_interface->setText(QApplication::translate("MainWindow", "Add interface", 0));
        actionAdd_Realization->setText(QApplication::translate("MainWindow", "Add Realization", 0));
        actionAdd_dependency->setText(QApplication::translate("MainWindow", "Add dependency", 0));
        actionAdd_attribute->setText(QApplication::translate("MainWindow", "Add attribute", 0));
        actionAdd_operation->setText(QApplication::translate("MainWindow", "Add operation", 0));
        actionAdd_data_type->setText(QApplication::translate("MainWindow", "Add data type", 0));
        actionAdd_uni_association->setText(QApplication::translate("MainWindow", "Add uni association", 0));
        actionAdd_use_case->setText(QApplication::translate("MainWindow", "Add use case", 0));
        actionRename->setText(QApplication::translate("MainWindow", "Rename", 0));
        actionGroup->setText(QApplication::translate("MainWindow", "Group", 0));
        actionUngroup->setText(QApplication::translate("MainWindow", "Ungroup", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UMLEDITER_H
