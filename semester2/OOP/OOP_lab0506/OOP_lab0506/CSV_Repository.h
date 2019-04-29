#pragma once
#include "VRepository.h"
#include "Tutorial.h"
#include <vector>
#include <string>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>

#include "Errors.h"

class CSV_Repository :
	public VRepository<Tutorial>
{
private:
	std::string file_name;
public:
	CSV_Repository(std::vector<Tutorial> &a, std::string file);
	
	void load_tutorials_repo();
	//void load_tutorials_watch();

	void save_tutorials();
	//void save_tutorials_watch();

	void add(const Tutorial &t) override;
	void remove(const Tutorial &t) override;
	void update(const Tutorial &t_old, const Tutorial &t_new) override;
	void incerement_like(const Tutorial &t) override;

	//void add_watch_list(const Tutorial &t) override;
	//void delete_first_watch_list() override;
	//void like_first_watch_list() override;
	
	
	~CSV_Repository() override;
};

