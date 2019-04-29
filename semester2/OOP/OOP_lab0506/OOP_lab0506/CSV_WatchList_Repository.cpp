#include "CSV_WatchList_Repository.h"





CSV_WatchList_Repository::CSV_WatchList_Repository(std::vector<Tutorial>& a, std::string file):VRepository{a}, file_name{file}
{
}

void CSV_WatchList_Repository::save_tutorials_watch()
{
	std::ofstream f(this->file_name);
	if (!f.is_open())
		throw RepoError("Cannot open file!\n");
	std::vector<Tutorial> vect = this->get_all();
	for (auto t : vect)
	{
		f << t;
	}

	f.close();
}


void CSV_WatchList_Repository::add_watch_list(const Tutorial & t)
{
	this->arr.push_back(t);
	this->save_tutorials_watch();
}

void CSV_WatchList_Repository::delete_first_watch_list()
{
	this->arr.erase(this->arr.begin());
	this->save_tutorials_watch();
}

void CSV_WatchList_Repository::like_first_watch_list()
{
	auto it = std::find(this->arr.begin(), this->arr.end(), this->arr[0]);
	(*it).plus_like();
	this->save_tutorials_watch();
	//this->save_tutorials();
}

Tutorial CSV_WatchList_Repository::get_first()
{
	return this->arr[0];
}

void CSV_WatchList_Repository::play_first_watch_list()
{
	this->arr[0].play();
}

void CSV_WatchList_Repository::open_file()
{
	std::string given;
	given += "notepad.exe " + this->file_name;
	system(given.c_str());
}





CSV_WatchList_Repository::~CSV_WatchList_Repository()
{
}
