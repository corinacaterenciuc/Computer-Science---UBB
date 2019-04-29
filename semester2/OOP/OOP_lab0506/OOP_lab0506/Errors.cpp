#include "Errors.h"





ValidatorError::ValidatorError(std::string m): message{m}
{
}

const char * ValidatorError::what() const noexcept
{
	return this->message.c_str();
}

RepoError::RepoError(std::string m): message{m}
{
}

const char * RepoError::what() const noexcept
{
	return this->message.c_str();
}

ControllerError::ControllerError(std::string m):message{m}
{
}

const char * ControllerError::what() const noexcept
{
	return this->message.c_str();
}

void TutorialValidator::validate( Tutorial & t)
{
	std::string error;
	if (t.get_title().size() <= 2)
		error += "the title must have at least 3 characters!\n";
	if (t.get_presenter().size() <= 2)
		error += "the presenter must have at least 3 characters!\n";
	if (t.get_duration().get_min() < 0 || t.get_duration().get_sec() < 0 || t.get_duration().get_sec() > 59)
		error += "the minutes and seconds must be positive integers, and the seconds cannot be greater than 59!\n";
	if (t.get_likes() < 0)
		error += "the number of likes must be a positive integer!\n";
	if (t.get_link().size() < 10)
		error += "the link is usually a larger string!\n";

	if (error.size() > 0)
		throw ValidatorError(error);


}
