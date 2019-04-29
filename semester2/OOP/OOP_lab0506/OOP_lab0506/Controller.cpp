#include "Controller.h"
#include <vector>
#include <algorithm>
#include <string>

#include <iostream>



Controller::Controller(VRepository<Tutorial> &r, VRepository<Tutorial> & w, TutorialValidator v) :repo{ r }, watch_list{ w }, validator{ v }
{
}


Controller::~Controller()
{
	// nothing to destroy
}

void Controller::add(const std::string & title, const std::string & presenter, int min, int sec, int  likes, const std::string & link)
{
	/*if (title == " " || presenter == " " || likes < 0 || link == " " || min<0 || sec<0)
		throw std::exception("Invalid parameters for creatig a tutorial!");*/


	Duration duration{ min,sec };
	Tutorial t{ title,presenter,duration,likes,link };

	this->validator.validate(t);

	this->repo.add(t);
}

void Controller::remove(const std::string & title)
{
	if (title == " ")
		throw ControllerError("Invalid title!");
	Duration d{};
	Tutorial t{ title, " ",d,0," " };
	this->repo.remove(t);

}

void Controller::update(const std::string &title,const  std::string & presenter, int min, int sec, int likes, const std::string & link)
{
	Duration d{};
	Duration d_given{ min,sec };
	Duration d_new{};
	std::string p_new;
	int likes_new;
	std::string link_new;
	Tutorial t{ title, " ",d,0," " };
	Tutorial t_old = this->repo.get_tutorial(t);
	if (presenter == "")
		p_new = t_old.get_presenter();
	else
		p_new = presenter;

	if (min == 0 && sec == 0)
		d_new = t_old.get_duration();
	else
		d_new = d_given;

	if (likes == 0)
		likes_new = t_old.get_likes();
	else
		likes_new = likes;

	if (link == "")
		link_new = t_old.get_link();
	else
		link_new = link;

	Tutorial t_new(title, p_new, d_new, likes_new, link_new);

	this->repo.update(t, t_new);

}

int Controller::get_size_repo()
{
	return this->repo.get_size();
}

std::vector<Tutorial> Controller::get_all_repo()
{
	return this->repo.get_all();
}

std::vector<Tutorial> Controller::filter_by_presenter(const std::string & presenter)
{
	std::vector<Tutorial> result;
	std::vector<Tutorial> all = this->get_all_repo();

	if (presenter == "")
	{
		return all;
	}
	// result.begin(),
	auto it = copy_if(all.begin(), all.end(), std::back_inserter(result), [presenter](Tutorial &t) {  return t.get_presenter() == presenter; });// t.get_presenter().find(presenter) != std::string::npos;});// t.get_presenter() == presenter;});

	//result.resize(distance(result.begin(), it));
	return result;
}

	
	
	/*if (presenter == "")
	{
		for (int i = 0; i < this->get_size_repo(); i++)
			result.push_back(t[i]);
		
	}
		
	else
	{
		for (int i = 0; i < this->get_size_repo(); i++)
		{
			if (t->get_presenter().find(presenter) != std::string::npos)
				result.push_back(t[i]);
		}
	}
	return result;*/


void Controller::add_watch_list(const Tutorial & t)
{
	this->watch_list.add_watch_list(t);
}

void Controller::play_first_watch_list(){this->watch_list.play_first_watch_list();}

void Controller::delete_first_watch_list()
{
	this->watch_list.delete_first_watch_list();
}

int Controller::get_size_watch()
{
	return this->watch_list.get_size();
}

std::vector<Tutorial> Controller::get_all_watch()
{
	return this->watch_list.get_all();
}

void Controller::open_watch_file()
{
	this->watch_list.open_file();
}

void Controller::generic_sort(std::vector<Tutorial> &arr, Comparator<Tutorial> &compare)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i; j < arr.size(); j++)
		{
			if (!compare.compare(arr[i], arr[j]))
			{
				auto aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
	}

	//for (int i = 0; i < arr.size(); i++)
	//{
	//	auto key = arr[i];
	//	int j = i - 1;

	//	/* Move elements of arr[0..i-1], that are
	//	  greater than key, to one position ahead
	//	  of their current position */
	//	while (j >= 0 && compare.compare(arr[i],key)) {
	//		arr[j + 1] = arr[j];
	//		j = j - 1;
	//	}
	//	arr[j + 1] = key;
	//}

	
}

void Controller::like_first_watch_list()
{
	this->watch_list.like_first_watch_list();
	this->repo.incerement_like(this->watch_list.get_first());
}
