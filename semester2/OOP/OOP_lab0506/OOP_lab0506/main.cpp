#include <iostream>
#include "Tutorial.h"
#include "Controller.h"
#include "UI.h"
#include <crtdbg.h>
#include "Tests.h"


#include "CSV_Repository.h"
#include "CSV_WatchList_Repository.h"
#include "HTML_WatchList_Repository.h"
#include "Errors.h"

#include <Windows.h>
using namespace std;

int main()
{

	
	
	{
		

		while (true) 
		{
			cout << "Plese choose: \n ";
			cout << "\t 1. use CSV file for watch list \n";
			cout << "\t 2. use HTML file for watch list \n";
			int op;
			cout << "choice >>";
			cin >> op;
			cin.ignore();
			if (op == 1)
			{
				std::vector<Tutorial> v{};
				std::vector <Tutorial> watch_list{};
				CSV_Repository repo{ v, "tutorials.csv" };
				CSV_WatchList_Repository watch_list_repo{ watch_list, "watch_list.csv" };
				TutorialValidator validator{};
				Controller ctrl{ repo,watch_list_repo, validator };
				UI ui{ ctrl };
				ui.start();
				break;
			}

			else if (op == 2)
			{
				std::vector<Tutorial> v{};
				std::vector <Tutorial> watch_list{};
				CSV_Repository repo{ v, "tutorials.csv" };
				HTML_WatchList_Repository watch_list_repo{ watch_list, "watch_list.html" };
				TutorialValidator validator{};
				Controller ctrl{ repo,watch_list_repo, validator };
				UI ui{ ctrl };
				ui.start();
				break;
			}

			else
				cout << "please, chose something valid!\n";
		}
		
		

	} 
	_CrtDumpMemoryLeaks();

	return 0;
}



