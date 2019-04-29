#include "HTML_WatchList_Repository.h"



HTML_WatchList_Repository::HTML_WatchList_Repository(std::vector<Tutorial> &a, std::string file):VRepository{a}, file_name{file}
{
}

void HTML_WatchList_Repository::save_tutorials_watch()
{
	std::ofstream f(this->file_name);
	if (!f.is_open())
		throw RepoError("Cannot open file!\n");
	std::string header, tail;
	header += "<!DOCTYPE html> \n <html> \n <head> \n <title>Playlist</title> \n </head> \n <body> \n <table border = \"1\"> \n <tr> \n <td>Title</td> \n <td>Presenter</td> \n <td>Duration</td>  \n <td>Likes</td> \n <td>Youtube link</td> \n </tr>";
	tail += "</table> \n </body> \n </html>";
	std::vector<Tutorial> vect = this->get_all();
	f << header;
	for (auto t : vect)
	{
		std::string html_tutorial = t.to_html();
		f << html_tutorial;
	}
	f << tail;

	f.close();
}


void HTML_WatchList_Repository::add_watch_list(const Tutorial & t)
{
	this->arr.push_back(t);
	this->save_tutorials_watch();
}

void HTML_WatchList_Repository::delete_first_watch_list()
{
	this->arr.erase(this->arr.begin());
	this->save_tutorials_watch();
}

void HTML_WatchList_Repository::like_first_watch_list()
{
	auto it = std::find(this->arr.begin(), this->arr.end(), this->arr[0]);
	(*it).plus_like();
	this->save_tutorials_watch();
	//this->save_tutorials();
}

Tutorial HTML_WatchList_Repository::get_first()
{
	return this->arr[0];
}

void HTML_WatchList_Repository::play_first_watch_list()
{
	this->arr[0].play();
}

void HTML_WatchList_Repository::open_file()
{
	char path[500];
	GetCurrentDirectoryA(500, path);
	std::string final_path = path;
	final_path += "\\" + this->file_name;
	ShellExecuteA(NULL, "open", final_path.c_str(), NULL, NULL, SW_SHOWNORMAL);
}




HTML_WatchList_Repository::~HTML_WatchList_Repository()
{

}
