#include "CSV_Repository.h"






CSV_Repository::CSV_Repository(std::vector<Tutorial>& a, std::string file)
	:VRepository{a}, file_name{file}
{
	this->load_tutorials_repo();
}

void CSV_Repository::load_tutorials_repo()
{
	std::ifstream f(this->file_name);
	if (!f.is_open())
		return;

	Tutorial t{};
	while (f >> t)
	{
		this->arr.push_back(t);
	}
	f.close();
}

//void CSV_Repository::load_tutorials_watch()
//{
//	std::ifstream f(this->file_name_watch);
//	if (!f.is_open())
//		return;
//
//	Tutorial t{};
//	while (f >> t)
//	{
//		this->watch_list.push_back(t);
//	}
//	f.close();
//}

void CSV_Repository::save_tutorials()
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

//void CSV_Repository::save_tutorials_watch()
//{
//	std::ofstream f(this->file_name_watch);
//	if (!f.is_open())
//		throw RepoError("Cannot open file!\n");
//	std::vector<Tutorial> vect = this->get_watch_list();
//	for (auto t : vect)
//	{
//		f << t;
//	}
//
//	f.close();
//}

void CSV_Repository::add(const Tutorial & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	if (it != this->arr.end())
		throw RepoError("The tutorial exists already!");
	this->arr.push_back(t);

	this->save_tutorials();
}

void CSV_Repository::remove(const Tutorial & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	if (it == this->arr.end())
		throw RepoError("The tutorial does not exist!");
	this->arr.erase(it);

	this->save_tutorials();
}

void CSV_Repository::update(const Tutorial & t_old, const Tutorial & t_new)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t_old);
	if (it == this->arr.end())
		throw RepoError("The tutorial does not exist!");
	std::replace(this->arr.begin(), this->arr.end(), t_old, t_new);
	this->save_tutorials();
}

void CSV_Repository::incerement_like(const Tutorial & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	(*it).plus_like();
	this->save_tutorials();

}

//void CSV_Repository::add_watch_list(const Tutorial & t)
//{
//	this->watch_list.push_back(t);
//	this->save_tutorials_watch();
//}
//
//void CSV_Repository::delete_first_watch_list()
//{
//	this->watch_list.erase(this->watch_list.begin());
//	this->save_tutorials_watch();
//}
//
//void CSV_Repository::like_first_watch_list()
//{
//	auto it = std::find(this->arr.begin(), this->arr.end(), this->watch_list[0]);
//	(*it).plus_like();
//	this->save_tutorials_watch();
//	this->save_tutorials();
//}

CSV_Repository::~CSV_Repository()
{
}
