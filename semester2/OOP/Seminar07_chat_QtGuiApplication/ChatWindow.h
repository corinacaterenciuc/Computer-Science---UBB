#pragma once
#include "Observer.h"
#include "ChatSession.h"
#include <QWidget>
#include "ui_ChatWindow.h"

class ChatWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	ChatWindow(std::string _user, ChatSession* _chat_session, QWidget *parent = Q_NULLPTR);

	void update() override;
	~ChatWindow() override;
	void sendMessage();

	

private:
	std::string user;
	ChatSession* chat_session;
	
	Ui::ChatWindow ui;
};
