#pragma once
#include "VRepository.h"
#include "Tutorial.h"
#include <string>

#include <iostream>
#include <fstream>
#include "Errors.h"
class CSV_WatchList_Repository :
	public VRepository<Tutorial>
{
private:
	std::string file_name;
public:
	CSV_WatchList_Repository(std::vector<Tutorial> &a, std::string file);

	void save_tutorials_watch();

	void add_watch_list(const Tutorial &t) override;
	void delete_first_watch_list() override;
	void like_first_watch_list() override;
	Tutorial get_first() override;

	void play_first_watch_list() override;

	void open_file() override;



	~CSV_WatchList_Repository() override;
};

