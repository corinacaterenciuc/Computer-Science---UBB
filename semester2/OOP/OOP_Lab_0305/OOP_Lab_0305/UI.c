#include "UI.h"
#include <stdio.h>
#include "Country.h"
#include <string.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
//Helpers

void sort_ascending_name(TElem v[], int len_v)
{
	TElem aux;
	for (int i = 0; i < len_v - 1; i++)
	{
		for (int j = i; j < len_v; j++)
		{
			if (compareCountry(v[i], v[j]) == 1)
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}

}

void sort_ascending_population(TElem v[], int len_v)
{
	TElem aux;
	for (int i = 0; i < len_v - 1; i++)
	{
		for (int j = i; j < len_v; j++)
		{
			if (getPopulation(v[i]) > getPopulation(v[i + 1]))
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}

}

//------------------------------------------------------------------

UI* init_ui(Controller * controller)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->cont = controller;
	return ui;
}

void destroy_ui(UI * ui)
{
	free(ui);
}

void add_ui(UI* ui)
{
	char name[100], continent[100];
	int population;
	printf("Name of the country> ");
	scanf("%s",name);
	getchar();
	printf("Continent of the country> ");
	scanf("%s", continent);
	getchar();
	printf("Population of the country> ");
	scanf_s("%d", &population);

	int done = addElem(ui->cont, name, continent, population);

	if (done == 0)
	{
		printf("\nThis country already exists!\n\n");
	}
}

void delete_ui(UI * ui)
{
	char name[100] ;
	
	printf("Name of the country> ");
	scanf("%s", name);
	getchar();
	int done = deleteElem(ui->cont, name);

	if (done == 0)
	{
		printf("\nThis country does not exist!\n\n");
	}
}

void update_ui(UI * ui)
{
	char old_name[100], new_continent[100];
	int new_population;
	printf("Name of the country to be updated> ");
	scanf("%s", old_name);
	getchar();
	printf("New continent of the country> ");
	scanf("%s", new_continent);
	getchar();
	printf("New population of the country> ");
	scanf_s("%d", &new_population);

	int done = updateElem(ui->cont, old_name,new_continent, new_population,0);

	if (done == 0)
	{
		printf("\nThis country does not exist!\n\n");
	}
}

void migrateFromTo_ui(UI * ui)
{
	char from_name[100], to_name[100];
	int nr_population;
	printf("Name of the country people are migrated from> ");
	scanf("%s", from_name);
	getchar();
	printf("Name of the country people are migrating to> ");
	scanf("%s", to_name);
	getchar();
	printf("numberof people who are migrating> ");
	scanf_s("%d", &nr_population);

	int done = migrateFromTo(ui->cont, from_name, to_name, nr_population );

	if (done == 0)
	{
		printf("\nOne of the countries you named does not exist!\n\n");
	}
}

void print_all_ui(UI * ui)
{

	TElem* list = get_all(ui->cont);
	print_list_ui(ui, list, get_repo_size(ui->cont));
	

}


void print_list_ui(UI * ui, TElem list[], int len)
{
	if (len == 0)
		printf("\nNo such elemt has been found!\n\n");
	else
	{
		for (int i = 0; i < len; i++)
		{
			char print_str[1000];
			toString(list[i], print_str);
			printf("%s\n", print_str);
		}
	}
}


void search_name_ui(UI * ui)
{
	char searchName[100];
	int length = 0;
	int *len;
	len= &length;
	TElem result_search[10000];

	printf("What are you searching for? >>  ");
	scanf("%s", searchName);
	getchar();
	search_name(ui->cont, searchName, len, result_search);
	print_list_ui(ui,result_search,*len);

	
}



void activity(UI * ui)
{
	char searchContinent[100];
	TElem search_result[10000];
	int length = 0;
	int *len;
	len= &length;
	
	printf("What are you searching for? >>  ");
	scanf("%s", searchContinent);
	getchar();

	search_continent(ui->cont, searchContinent,len, search_result);
	sort_ascending_name(search_result, *len);

	print_list_ui(ui, search_result, *len);

}



void requirement_c_ui(UI * ui)
{
	char searchContinent[100];
	TElem search_result[1000];
	int length = 0, value;
	int *len;
	len = &length;

	printf("What are you searching for? >>  ");
	scanf("%s", searchContinent);
	getchar();

	printf("You want the population to be greater than >>  ");
	scanf_s("%d", &value);
	getchar();

	search_continent(ui->cont, searchContinent, len, search_result);

	filter_population_greater(ui->cont, value, search_result, len);

	sort_ascending_population(search_result, *len);
	
	print_list_ui(ui, search_result, *len);
}



void existing_values(UI * ui)
{
	addElem(ui->cont, "Romania", "Europa", 19);
	
	addElem(ui->cont, "Ecuador", "America", 67);
	addElem(ui->cont, "Madagascar", "Africa", 78);
	addElem(ui->cont, "Egypt", "Africa", 55);
	addElem(ui->cont, "Canada", "America", 19);
	addElem(ui->cont, "Moldova", "Europa", 9);
	addElem(ui->cont, "Australia", "Australia", 155);
	addElem(ui->cont, "USA", "America", 87);
	addElem(ui->cont, "Franta", "Europa", 25);
	addElem(ui->cont, "India", "Asia", 150);
	deleteElem(ui->cont, "USA");
	migrateFromTo(ui->cont, "Romania", "Ecuador", 3);
	

}

void print_menu(UI * ui)
{
	printf("\nYour options are: \n");
	printf("1. Add country.\n");
	printf("2. Delete country.\n");
	printf("3. Update country.\n");
	printf("4. Migrate from a country to another.\n");
	printf("5. Print all countries.\n");
	printf("6. Search countries by name.\n");
	printf("7. Search countries by continent and sort ascending by name.\n");
	printf("8. Search countries by continent whose population is greater than a given value, sorted ascending by population. \n");
	printf("9. Undo last operation.\n");
	printf("10. Redo last operation.\n");
	printf("0. Exit.\n");
	printf("Enter option >> ");
}

int start_ui(UI * ui)
{
	int option;
	while (1)
	{
		print_menu(ui);
		scanf_s("%d", &option);
		getchar();
		if (option == 1)
			add_ui(ui);
		else if (option == 2)
			delete_ui(ui);
		else if (option == 3)
			update_ui(ui);
		else if (option == 4)
			migrateFromTo_ui(ui);
		else if (option == 5)
			print_all_ui(ui);
		else if (option == 0)
			return 0;
		else if (option == 6)
			search_name_ui(ui);
		else if (option == 7)
			activity(ui);
		else if (option == 8)
			requirement_c_ui(ui);
		else if (option == 9)
		{
			int been_undo = 0;
			int been_here_undo = &been_undo;
			int ok = undo(ui->cont,been_here_undo);
			if (ok == 1)
				printf("\n Undo was successful. \n\n");
			else
				printf("\n No more undos to be made. \n\n");
		}
		else if (option == 10)
		{
			int been_redo = 0;
			int been_here_redo = &been_redo;
			int ok_redo = redo(ui->cont,been_here_redo);
			if(ok_redo)
				printf("\n Redo was successful. \n\n");
			else
				printf("\n No more redos to be made. \n\n");

		}
		else printf("Invalid option!\n");

	}
}

