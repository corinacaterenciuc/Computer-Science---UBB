/********************************************************************************
** Form generated from reading UI file 'OOP_Seminar07_chat_QtGuiApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOP_SEMINAR07_CHAT_QTGUIAPPLICATION_H
#define UI_OOP_SEMINAR07_CHAT_QTGUIAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OOP_Seminar07_chat_QtGuiApplicationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OOP_Seminar07_chat_QtGuiApplicationClass)
    {
        if (OOP_Seminar07_chat_QtGuiApplicationClass->objectName().isEmpty())
            OOP_Seminar07_chat_QtGuiApplicationClass->setObjectName(QString::fromUtf8("OOP_Seminar07_chat_QtGuiApplicationClass"));
        OOP_Seminar07_chat_QtGuiApplicationClass->resize(600, 400);
        menuBar = new QMenuBar(OOP_Seminar07_chat_QtGuiApplicationClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        OOP_Seminar07_chat_QtGuiApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OOP_Seminar07_chat_QtGuiApplicationClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        OOP_Seminar07_chat_QtGuiApplicationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(OOP_Seminar07_chat_QtGuiApplicationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        OOP_Seminar07_chat_QtGuiApplicationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OOP_Seminar07_chat_QtGuiApplicationClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        OOP_Seminar07_chat_QtGuiApplicationClass->setStatusBar(statusBar);

        retranslateUi(OOP_Seminar07_chat_QtGuiApplicationClass);

        QMetaObject::connectSlotsByName(OOP_Seminar07_chat_QtGuiApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *OOP_Seminar07_chat_QtGuiApplicationClass)
    {
        OOP_Seminar07_chat_QtGuiApplicationClass->setWindowTitle(QCoreApplication::translate("OOP_Seminar07_chat_QtGuiApplicationClass", "OOP_Seminar07_chat_QtGuiApplication", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOP_Seminar07_chat_QtGuiApplicationClass: public Ui_OOP_Seminar07_chat_QtGuiApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOP_SEMINAR07_CHAT_QTGUIAPPLICATION_H
