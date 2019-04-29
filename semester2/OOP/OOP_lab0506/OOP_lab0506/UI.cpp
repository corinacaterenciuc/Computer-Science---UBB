#include "UI.h"
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include "Tutorial.h"

#include "Comparators.h"
#include "Errors.h"


using namespace std;


UI::UI(Controller & c):ctrl{c}
{
}

UI::~UI()
{
	//nothing to dealocate
}

void UI::add()
{
	
	string title, presenter, link;
	int min, sec, likes;
	cout << "Give the title >> ";
	getline(cin, title);
	cout << "Give the presenter >> ";
	getline(cin, presenter);
	cout << "Number of minutes out of my life >> ";
	cin >> min;
	cout << "Number of seconds out of my life >> ";
	cin >> sec;
	cout << "Number of likes >> ";
	cin >> likes;
	cin.ignore();
	cout << "Give the link >> ";
	getline(cin, link);

	this->ctrl.add(title, presenter, min, sec, likes, link);

}

void UI::remove()
{
	string title;
	cout << "Give the title >> ";
	getline(cin, title);
	this->ctrl.remove(title);
}

void UI::update()
{
	string title, presenter, link;
	int min, sec, likes;
	cout << "Give the title >> ";
	getline(cin, title);
	cout << "Give the new presenter or nothing>> ";
	getline(cin, presenter);
	cout << "Number of minutes or 0 >> ";
	cin >> min;
	cout << "Number of seconds or 0 >> ";
	cin >> sec;
	cout << "Number of likes or 0 >> ";
	cin >> likes;
	cin.ignore();
	cout << "Give the link or nothing>> ";
	getline(cin, link);

	this->ctrl.update(title, presenter, min, sec, likes, link);
}

void UI::print_all()
{
	if (this->ctrl.get_size_repo() == 0)
		cout << "\n There are no tutorials to print! \n";
	else
	{
		std::vector<Tutorial> ts = this->ctrl.get_all_repo();
		for (int i = 0; i < this->ctrl.get_size_repo(); i++)
		{
			/*if(ts[i].get_duration().get_sec() < 10)
				cout << ts[i].get_title() << "\n\t by " << ts[i].get_presenter() << "\n\t duration : " << ts[i].get_duration().get_min() << ":0"<< ts[i].get_duration().get_sec() << "\n\t likes: " << ts[i].get_likes() << "\n\t link: " << ts[i].get_link() << "\n";
			else
				cout << ts[i].get_title() << "\n\t by " << ts[i].get_presenter() << "\n\t duration : " << ts[i].get_duration().get_min() << ":" << ts[i].get_duration().get_sec() << "\n\t likes: " << ts[i].get_likes() << "\n\t link: " << ts[i].get_link() << "\n";
			*/
			cout << ts[i];
		}
	}
	
}

void UI::sort()
{
	int option;
	cout << " Press 1 for sorting descending by title or 2 for sorting ascending by number of likes >> ";
	cin >> option;
	std::vector<Tutorial> v = (this->ctrl.get_all_repo());
	if (option == 1)
	{

		DescendingByTitle cmp_title{};
		this->ctrl.generic_sort(v, cmp_title);
		for (auto t : v)
			cout << " -> " << t;

	}
	else if (option == 2)
	{
		AscendingByLikes cmp_likes{};
		this->ctrl.generic_sort(v, cmp_likes);
		for (auto t : v)
			cout << t.get_likes() << " -> " << t;
	}
	else
		cout << "Invalid option!\n";
}

void UI::filter_by_presenter()
{
	string presenter;
	cout << "Give the presenter >> ";
	getline(cin, presenter);

	vector<Tutorial> result = this->ctrl.filter_by_presenter(presenter);
	if (result.size() == 0)
		throw exception("No tutorial by the given presenter found!");
	int index = 0;

	while (true)
	{
		cout << result[index];
		result[index].play();
		cout << "\n 1. Add to personal watch list and next.\n";
		cout << " 2. No thank you, next. \n";
		cout << " 0. STOP!\n";
		int choice;
		cout << "\n your choice >> ";
		cin >> choice;
		cin.ignore();
		if (choice == 1)
		{
			this->ctrl.add_watch_list(result[index]);
			index++;
		}

		else if (choice == 0)
			break;
		else if (choice == 2)
			index++;
		else
			cout << "Invalid option!\n";
		
		if (index > result.size() - 1)
			index = 0;

	}


}

void UI::play_watch_list()
{
	if (this->ctrl.get_size_watch() == 0)
		cout << "There is nothing to play!\n";
	else
	{
		while (true)
		{
			this->ctrl.play_first_watch_list();
			//cout << "\n 1. LIKE watched tutorial. \n";
			cout << " 1. NEXT.\n";
			cout << " 0. EXIT.\n";
			cout << "\n Chosen button >> ";
			int button;
			cin >> button;
			cin.ignore();
			if (button == 1)
			{
				while (true)
				{
					cout << "\n 3. LIKE watched tutorial! \n";
					cout << " 4. Not my cup of tea...\n";
					int like;
					cout << "Like or Nah? >> ";
					cin >> like;
					cin.ignore();
					if (like == 3)
					{
						this->ctrl.like_first_watch_list();
						break;
					}
					else if (like == 4)
						break;
					else
						cout << "there are only two options!\n";
				}

				this->ctrl.delete_first_watch_list();
			}
			else if (button == 0)
				break;
			else
				cout << "No such option!\n";
		}
	}
	
	

}

void UI::print_watch_list()
{
	if (this->ctrl.get_size_watch() == 0)
		cout << "There are no tutorials in the watch list!\n";
	else
	{
		std::vector<Tutorial> watch_list = this->ctrl.get_all_watch();

		for (auto t : watch_list)
			cout << t;
		/*for (int i = 0; i < this->ctrl.get_size_watch(); i++)
		{
			cout << watch_list[i];
		}*/
	}
}


void UI::add_existing_tutorials()
{
	this->ctrl.add("Function Pointers in C/C++", "mycodeacademy", 11, 57, 2000, "https://www.youtube.com/watch?v=ynYtgGUNelE");
	this->ctrl.add("C++ Tutorial 10 : Object Oriented Programming", "Derek Banas", 40, 54, 844, "https://www.youtube.com/watch?v=ZOKLjJF54Xc");
	this->ctrl.add("C++ Programming", "Derek Banas", 70, 30, 49000, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
	this->ctrl.add("Buckys C++ Programming Tutorials - 50 - Operator Overloading","thenewboston",5,34,1600,"https://www.youtube.com/watch?v=PgGhEovFhd0");
	this->ctrl.add("Let's Learn C++ ~ Basics: 1 of 14 ~ Visual Studio Setup + My First Program","Trevor Payne",16,27,3300,"https://www.youtube.com/watch?v=_r5i5ZtUpUM");
	this->ctrl.add("Python Vs. C++ | same program [syntax]", "YuriParadise",2,48,402,"https://www.youtube.com/watch?v=lmyMhi-WnM8");
	this->ctrl.add("C++Now 2018: Rong Lu 'C++ Development with Visual Studio Code'","BoostCon",93,26,313,"https://www.youtube.com/watch?v=-erXR6k9TeE");
	this->ctrl.add("Buckys C++ Programming Tutorials - 55 - Introduction to Polymorphism","thenewboston",9,59,2100,"https://www.youtube.com/watch?v=R_PPA9eejDw");
	this->ctrl.add("C++ Unit Testing with Google Test Tutorial","JetBrainsTV",14,58,680,"https://www.youtube.com/watch?v=16FI1-d2P4E");
	this->ctrl.add("Beginner C++ Game Programming Tutorial 0 DirectX [Introduction/Setup]","ChiliTomatoNoodle",16,3,8400,"https://www.youtube.com/watch?v=PwuIEMUFUnQ");
}

void UI::print_menu_admin()
{
	cout << "\nAs the Administrator, your options are: \n";
	cout << "\t1. Add a tutorial. \n";
	cout << "\t2. Remove a tutorial. \n";
	cout << "\t3. Update a tutorial. \n";
	cout << "\t4. List all tutorials. \n";
	cout << "\t5. Sort the tutorials. \n\n";
	cout << "\t0. Exit \n\n";
}

void UI::print_menu_user()
{
	cout << "\nAs the User, your options are: \n";
	cout << "\t1. See the tutorials in the database having a given presenter. \n";
	cout << "\t2. Play watch list. \n";
	cout << "\t3. See watch list. \n";
	cout << "\t4. Open watch list file \n\n";
	cout << "\t0. Exit \n\n";
	//cout << "\t4. List all tutorials. \n\n";
	
}


void UI::start()
{
	int op;
	bool work = true;
	while (work)
	{
		int option = 0;
		cout << "Press: \n\t 1 -  for Admin mode\n\t 2 -  for User mode \n\t 0 - for exit. >>";
		cin >> option;
		cin.ignore();

		//Administrator mode
		if (option == 1)
		{
			while (true)
			{
				this->print_menu_admin();
				cout << "Enter option >> ";
				try
				{
					cin >> op;
					cin.ignore();
					if (op == 1)
						this->add();
					else if (op == 2)
						this->remove();
					else if (op == 3)
						this->update();
					else if (op == 4)
						this->print_all();
					else if (op == 5)
						this->sort();
					else if (op == 0)
						break;
					else
						throw exception("Invalid option!");
				}
				catch (ValidatorError &valid_error)
				{
					cout << "Validation error : " << valid_error.what();
				}
				catch (RepoError &repo_error)
				{
					cout << "Repository error: " <<repo_error.what();
				}
				catch (ControllerError &ctrl_error)
				{
					cout << "Controler error: " <<ctrl_error.what();
				}
				catch (exception &exc)
				{
					cout << "Error occured: " <<exc.what();
				}
			}

		}
		// User mode
		else if (option == 2)
		{
			while (true)
			{
				this->print_menu_user();
				cout << "Enter option >> ";
				try
				{
					cin >> op;
					cin.ignore();
					if (op == 1)
						this->filter_by_presenter();
					else if (op == 2)
						this->play_watch_list();
					else if (op == 3)
						this->print_watch_list();
					else if (op == 4)
						this->ctrl.open_watch_file();
					else if (op == 0)
						break;
					else
						throw exception("Invalid option!");
				}
				catch (ValidatorError &valid_error)
				{
					cout << "Validation error : " << valid_error.what();
				}
				catch (RepoError &repo_error)
				{
					cout << "Repository error: " << repo_error.what();
				}
				catch (ControllerError &ctrl_error)
				{
					cout << "Controler error: " << ctrl_error.what();
				}
				catch (exception &exc)
				{
					cout << "Error occured: " << exc.what();
				}
			}
		}
		//exist
		else if (option == 0)
			work = false;
		//mistakes
		else
			cout << "Invalid option! Please try again ...\n";
		
		
		
	}
	
}
