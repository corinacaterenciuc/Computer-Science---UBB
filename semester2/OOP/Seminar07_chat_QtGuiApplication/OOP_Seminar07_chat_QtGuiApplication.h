#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOP_Seminar07_chat_QtGuiApplication.h"

class OOP_Seminar07_chat_QtGuiApplication : public QMainWindow
{
	Q_OBJECT

public:
	OOP_Seminar07_chat_QtGuiApplication(QWidget *parent = Q_NULLPTR);

private:
	Ui::OOP_Seminar07_chat_QtGuiApplicationClass ui;
};
