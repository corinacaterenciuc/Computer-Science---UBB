#include "Tutorial.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <iomanip>

Tutorial::Tutorial() :title{ " " },presenter{ " " },duration{ 0 },nr_likes{ 0 }, link{ " " }
{
}


Tutorial::Tutorial(const std::string & t, const std::string & p, Duration & d, int nr_l, const std::string & l)
{
	this->title = t;
	this->presenter = p;
	this->duration = d;
	this->nr_likes = nr_l;
	this->link = l;
}

bool Tutorial::operator==(const Tutorial & t)
{
	
	return (this->title == t.title);
}

Tutorial::~Tutorial()
{
	//nothing to destroy unfortunately
}

std::string Tutorial::get_title()
{
	return this->title;
}

std::string Tutorial::get_presenter()
{
	return this->presenter;
}

Duration Tutorial::get_duration()
{
	return this->duration;
}

int Tutorial::get_likes()
{
	return this->nr_likes;
}

std::string Tutorial::get_link()
{
	return this->link;
}

void Tutorial::play()
{ShellExecuteA(NULL, NULL, "chrome.exe", this->link.c_str(), NULL, SW_SHOWMAXIMIZED);}

void Tutorial::plus_like()
{
	this->nr_likes += 1;
}

std::string Tutorial::to_html()
{
	std::string convert_html;
	std::stringstream out_duration;
	out_duration << this->get_duration();

	std::string likes = std::to_string(this->get_likes());

	convert_html += "<tr> \n ";
	convert_html += "<td>" + this->get_title() + "</td> \n ";
	convert_html += "<td>" + this->get_presenter() + "</td> \n ";
	convert_html += "<td>" + out_duration.str() + "</td> \n ";
	convert_html += "<td>" + likes + "</td> \n ";
	convert_html += "<td><a href = \"" + this->get_link() + "\">Link</a>" +"</td> \n </tr> \n";


	

	return convert_html;
}

std::ostream & operator<<(std::ostream & s, const Tutorial & t)
{

	s << t.title << "," << t.presenter << "," << t.duration << "," << t.nr_likes << "," << t.link << std::endl; // "\n\t link: " << t.link << "\n";
	
	return s;
}

//std::istream & operator>>(std::istream & is, Duration & d)
//{
//	std::string line_duration;
//	getline(is, line_duration);
//
//	std::vector <std::string> tokens = create_token(line_duration, ':');
//
//	if (tokens.size() != 2)
//		return is;
//
//	d.min = std::stoi(tokens[0]);
//	d.sec = std::stoi(tokens[1]);
//
//	//is >> d.min >> d.sec;
//	return is;
//	// TODO: insert return statement here
//}

std::istream & operator>>(std::istream & is, Tutorial & t)
{
	std::string line_tutorial;
	getline(is, line_tutorial);
	
	std::vector <std::string> tokens = create_token(line_tutorial, ',');
	
	if (tokens.size() != 5)
		return is;
	t.title = tokens[0];
	t.presenter = tokens[1];
	std::vector<std::string> tokens_duration = create_token(tokens[2], ':');
	Duration d;
	d.set_min(std::stoi(tokens_duration[0]));
	d.set_sec(std::stoi(tokens_duration[1]));
	t.duration = d;

	t.nr_likes = std::stoi(tokens[3]);
	t.link = tokens[4];
	return is;
	/*is >> t.title >> t.presenter >> t.duration >> t.nr_likes >> t.link;
	return is;*/
	// TODO: insert return statement here
}



//----------------------------------------------------------------------------------------------------------------



Duration::Duration(int m, int s): min{m}, sec{s}
{
}

Duration & Duration::operator=(const Duration & d)
{
	// TODO: insert return statement here
	this->min = d.min;
	this->sec = d.sec;
	return *this;
}

bool Duration::operator==(const Duration & t)
{
	return (this->min == t.min && this->sec == t.sec);
}

Duration::~Duration()
{
	//nothing to dealocate
}

int Duration::get_min()
{

	return this->min;
}

int Duration::get_sec()
{
	return this->sec;
}

std::vector<std::string> create_token(std::string str, char delimiter)
{
	std::vector <std::string> tokens;
	std::stringstream ss(str);
	std::string token;
	while (getline(ss, token, delimiter))
		tokens.push_back(token);

	return tokens;
}



std::istream & operator>>(std::istream & is, Duration & d)
{
	std::string line_duration;
	getline(is, line_duration);

	std::vector <std::string> tokens = create_token(line_duration, ':');

	if (tokens.size() != 2)
		return is;

	d.min = std::stoi(tokens[0]);
	d.sec = std::stoi(tokens[1]);

	//is >> d.min >> d.sec;
	return is;
	// TODO: insert return statement here
}


std::ostream & operator<<(std::ostream &os,const Duration & d)
{
	// TODO: insert return statement here

	/*os << d.min << ":" << d.sec;
	return os;*/

	if(d.min < 10)
		if(d.sec < 10)
			os <<"0"<< d.min << ":" <<"0"<< d.sec;
		else
			os << "0" << d.min << ":" << d.sec;
	else
		if (d.sec < 10)
			os << d.min << ":" << "0" << d.sec;
		else
			os << d.min << ":" << d.sec;
	return os;
}




