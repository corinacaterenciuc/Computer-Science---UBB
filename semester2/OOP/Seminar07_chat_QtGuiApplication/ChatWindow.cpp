#include "ChatWindow.h"

ChatWindow::ChatWindow(std::string _user, ChatSession* _chat_session, QWidget *parent )
	: QWidget(parent), chat_session{_chat_session}, user{_user}
{
	ui.setupUi(this);

	ui.pushButton_send->setShortcut(QKeySequence(Qt::Key_Return));
	connect(ui.pushButton_send, &QPushButton::clicked, this, &ChatWindow::sendMessage);

	
}

void ChatWindow::update()
{
	ui.listWidget_chat->clear();
	for (auto cs : this->chat_session->getMessages())
	{
		if (this->user == cs.get_name())
		{
			QListWidgetItem* i = new QListWidgetItem{ QString::fromStdString(cs.get_messge()) };
			//QListWidgetItem i{ QString::fromStdString(cs.get_messge()) };
			i->setTextAlignment(Qt::AlignRight);
			ui.listWidget_chat->addItem(i);

		}
		else
		{
			std::string m = " [" + cs.get_name() + "] " + cs.get_messge();
			QListWidgetItem* i = new QListWidgetItem{ QString::fromStdString(m) };
			ui.listWidget_chat->addItem(i);
		}
		
	}
}

void ChatWindow::sendMessage()
{
	std::string mes = ui.lineEdit_write->text().toLocal8Bit().constData();
	ui.lineEdit_write->clear();
	this->chat_session->addMessage(this->user, mes);

}

ChatWindow::~ChatWindow()
{
}
