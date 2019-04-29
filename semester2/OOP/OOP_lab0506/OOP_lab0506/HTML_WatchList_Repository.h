#pragma once
#include "VRepository.h"
#include <string>
#include "Tutorial.h"
#include "Errors.h"
#include <iostream>
#include <fstream>

#include <Windows.h>
#include <sstream>
#include <iomanip>


class HTML_WatchList_Repository :
	public VRepository<Tutorial>
{
private:
	std::string file_name;
public:
	HTML_WatchList_Repository(std::vector<Tutorial> &a, std::string file);

	void save_tutorials_watch();

	void add_watch_list(const Tutorial &t) override;
	void delete_first_watch_list() override;
	void like_first_watch_list() override;
	Tutorial get_first() override;

	void play_first_watch_list() override;

	void open_file() override;




	~HTML_WatchList_Repository() override;
};

