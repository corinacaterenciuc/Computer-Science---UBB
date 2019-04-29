#pragma once
#include <exception>
#include <string>
#include "Tutorial.h"
class ValidatorError: public std::exception
{
private:
	std::string message;
public:
	ValidatorError(std::string m);
	const char* what() const noexcept override;
	
};


class RepoError : public std::exception
{
private:
	std::string message;
public:
	RepoError(std::string m);
	const char* what() const noexcept override;

};


class ControllerError : public std::exception
{
private:
	std::string message;
public:
	ControllerError(std::string m);
	const char* what() const noexcept override;

};


class TutorialValidator
{
public:
	static void validate( Tutorial &t);
};

