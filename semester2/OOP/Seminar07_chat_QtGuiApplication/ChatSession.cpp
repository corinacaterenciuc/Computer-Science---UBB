#include "ChatSession.h"



ChatSession::ChatSession()
{

}

void ChatSession::addMessage(std::string user, std::string mes)
{
	UserMessage u{ user, mes };
	/*auto it = find(this->messages.begin(), this->messages.end(), u);
	if (it != this->messages.end())
	{
		throw std::exception("alreadu existing");
	}*/

	this->messages.push_back(u);
	this->notify();
}


std::vector<UserMessage> ChatSession::getMessages()
{
	return this->messages;
}

ChatSession::~ChatSession()
{
}
