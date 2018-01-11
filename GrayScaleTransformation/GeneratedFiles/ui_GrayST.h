/********************************************************************************
** Form generated from reading UI file 'GrayST.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAYST_H
#define UI_GRAYST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraySTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraySTClass)
    {
        if (GraySTClass->objectName().isEmpty())
            GraySTClass->setObjectName(QStringLiteral("GraySTClass"));
        GraySTClass->resize(600, 400);
        menuBar = new QMenuBar(GraySTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GraySTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GraySTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GraySTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GraySTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GraySTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GraySTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GraySTClass->setStatusBar(statusBar);

        retranslateUi(GraySTClass);

        QMetaObject::connectSlotsByName(GraySTClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraySTClass)
    {
        GraySTClass->setWindowTitle(QApplication::translate("GraySTClass", "GrayST", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GraySTClass: public Ui_GraySTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAYST_H
