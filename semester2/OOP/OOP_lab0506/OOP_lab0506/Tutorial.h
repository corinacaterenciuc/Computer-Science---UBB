#pragma once
#include <string>
#include <iostream>

#include "DynamicVector.h"

#include <vector>
#include <string>

class Duration
{
private:
	int min;
	int sec;
	friend class Tutorial;

	
public:
	Duration(int m = 0, int s =0);
	Duration& operator=(const Duration &d);
	bool operator==(const Duration &t);
	friend std::ostream& operator<<(std::ostream &os,const Duration &d);
	friend std::istream& operator>>(std::istream &is,  Duration &d);

	void set_min(int m) {
		this->min = m;
	}
	void set_sec(int s) {
		this->sec = s;
	}
	~Duration();

	int get_min();
	int get_sec();



};

std::vector<std::string> create_token(std::string str, char delimiter);


class Tutorial
{
private:
	std::string title;
	std::string presenter;
	Duration duration;
	int nr_likes;
	std::string link;

	friend class Duration;
public:
	Tutorial();
	Tutorial(const std::string &t, const std::string &p, Duration &d, int nr_l, const std::string &l);
	bool operator==(const Tutorial &t);
	friend std::ostream& operator<<(std::ostream &os, const Tutorial& t);
	friend std::istream& operator>>(std::istream &is,  Tutorial& t);
	~Tutorial();

	std::string get_title();
	std::string get_presenter();
	Duration get_duration();
	int get_likes();
	std::string get_link();
	void play();
	void plus_like();

	std::string to_html();
	


};

