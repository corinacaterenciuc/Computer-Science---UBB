#pragma once
#include <string>
class UserMessage
{
private:
	std::string user;
	std::string mes;
public:
	UserMessage(std::string _user, std::string _mes);
	std::string get_name() {
		return this->user;
	}
	std::string get_messge() {
		return this->mes;
	}
	~UserMessage();
};

