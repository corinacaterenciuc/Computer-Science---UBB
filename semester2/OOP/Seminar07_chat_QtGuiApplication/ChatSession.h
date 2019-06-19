#pragma once
#include "Subject.h"
#include <string>
#include "UserMessage.h"
class ChatSession :
	public Subject
{
private:
	std::vector<UserMessage> messages;
public:
	ChatSession();

	void addMessage(std::string user, std::string mes);

	std::vector<UserMessage> getMessages();

	~ChatSession();
};

