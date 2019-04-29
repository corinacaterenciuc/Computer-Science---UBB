#include "Repository.h"
#include <cstdlib>
#include <algorithm>




Repository::Repository(std::vector<Tutorial> & a, std::vector<Tutorial> &w):arr{a}, watch_list {w}
{
}

Repository::~Repository()
{
	//nothing to dealocate
}

void Repository::add(const Tutorial & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	if (it != this->arr.end())
		throw std::exception("The tutorial exists already!");
	this->arr.push_back(t);
}

void Repository::remove(const Tutorial & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	if (it == this->arr.end())
		throw std::exception("The tutorial does not exist!");
	this->arr.erase(it);
}

void Repository::update(const Tutorial & t_old, const Tutorial & t_new)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t_old);
	if (it == this->arr.end())
		throw std::exception("The tutorial does not exist!");
	std::replace(this->arr.begin(), this->arr.end(), t_old, t_new);
	//this->arr.update(t_old, t_new);
}

Tutorial Repository::get_tutorial(const Tutorial & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	if (it == this->arr.end())
		throw std::exception("The tutorial does not exist!");
	return *it;
}

int Repository::get_size_repo()
{
	return this->arr.size();
}

std::vector<Tutorial> Repository::get_tutorials()
{
	return this->arr;
}

void Repository::add_watch_list(const Tutorial & t)
{
	this->watch_list.push_back(t);
}

void Repository::play_first_watch_list(){this->watch_list[0].play();}

void Repository::delete_first_watch_list()
{

	this->watch_list.erase(this->watch_list.begin());
}

int Repository::get_size_watch()
{
	return this->watch_list.size();
}

std::vector<Tutorial> Repository::get_watch_list()
{
	return this->watch_list;
}



void Repository::like_first_watch_list()
{
	auto it = std::find(this->arr.begin(), this->arr.end(), this->watch_list[0]);
	(*it).plus_like();

	/*for (int i = 0; i < this->arr.size(); i++)
		if (this->watch_list[0] == this->arr[i])
			this->arr[i].plus_like();*/
}

//void Repository::like_tutorial( Tutorial & t)
//{
//	for (int i = 0; i < this->arr.get_size(); i++)
//		if (t == this->arr[i])
//			this->arr[i].plus_like();
//
//
//}
