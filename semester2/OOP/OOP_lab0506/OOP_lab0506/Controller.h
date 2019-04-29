#pragma once
#include "Repository.h"
#include <string>
#include "Tutorial.h"
#include <vector>
#include "Comparator.h"
#include "VRepository.h"
#include "Errors.h"


class Controller
{
private:
	VRepository<Tutorial> &repo;
	VRepository<Tutorial> &watch_list;
	TutorialValidator validator;
public:
	Controller(VRepository<Tutorial> & r, VRepository<Tutorial> & w, TutorialValidator v);
	~Controller();

	void add(const std::string &title, const std::string & presenter, int min,int sec, int likes, const std::string &link);
	void remove(const std::string &title);
	void update(const std::string &title,const std::string &presenter, int min, int sec, int likes,const std::string & link);
	int get_size_repo();
	std::vector<Tutorial> get_all_repo();

	std::vector<Tutorial> filter_by_presenter(const std::string &presenter);
	void add_watch_list(const Tutorial &t);
	void play_first_watch_list();
	void delete_first_watch_list();
	int get_size_watch();
	std::vector<Tutorial> get_all_watch();
	void open_watch_file();

	void generic_sort(std::vector<Tutorial> &arr, Comparator<Tutorial> &compare);

	void like_first_watch_list();
};

