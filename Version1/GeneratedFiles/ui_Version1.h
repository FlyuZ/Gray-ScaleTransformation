/********************************************************************************
** Form generated from reading UI file 'Version1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSION1_H
#define UI_VERSION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Version1Class
{
public:
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Version1Class)
    {
        if (Version1Class->objectName().isEmpty())
            Version1Class->setObjectName(QStringLiteral("Version1Class"));
        Version1Class->resize(600, 400);
        centralWidget = new QWidget(Version1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Version1Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Version1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Version1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Version1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Version1Class->setStatusBar(statusBar);

        retranslateUi(Version1Class);

        QMetaObject::connectSlotsByName(Version1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Version1Class)
    {
        Version1Class->setWindowTitle(QApplication::translate("Version1Class", "Version1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Version1Class: public Ui_Version1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSION1_H
