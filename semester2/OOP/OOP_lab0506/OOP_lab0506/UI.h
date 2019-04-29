#pragma once
#include "Controller.h"
class UI
{
private:
	Controller ctrl;
public:
	UI(Controller &c);
	~UI();

	void add();
	void remove();
	void update();
	void print_all();
	void sort();

	void filter_by_presenter();
	void play_watch_list();
	void print_watch_list();

	void add_existing_tutorials();
	void print_menu_admin();
	void print_menu_user();
	void start();




};

