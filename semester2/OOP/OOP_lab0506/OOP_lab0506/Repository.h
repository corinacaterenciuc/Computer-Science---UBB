#pragma once
#include "DynamicVector.h"
#include "Tutorial.h"
#include "vector"
class Repository
{
private:
	std::vector<Tutorial> &arr;
	std::vector <Tutorial> &watch_list;

	
public:
	Repository(std::vector<Tutorial> &a, std::vector<Tutorial> &w);
	~Repository();

	void add(const Tutorial &t);
	void remove(const Tutorial &t);
	void update(const Tutorial &t_old, const Tutorial &t_new);
	Tutorial get_tutorial(const Tutorial &t);
	int get_size_repo();
	std::vector<Tutorial> get_tutorials();

	void add_watch_list(const Tutorial &t);
	void play_first_watch_list();
	void delete_first_watch_list();
	int get_size_watch();
	std::vector<Tutorial> get_watch_list();
	

	void like_first_watch_list();
};

