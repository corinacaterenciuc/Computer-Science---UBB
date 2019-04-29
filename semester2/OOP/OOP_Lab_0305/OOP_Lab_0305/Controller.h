#pragma once
#include "Repository.h"
#include "Country.h"
#include "Operation_OperStack.h"

typedef struct
{
	Repository* repo;
	OperationsStack* undo_stack;
	OperationsStack* redo_stack;
}Controller;

Controller* init_controller(Repository* repo, OperationsStack* undo_stack, OperationsStack* redo_stack);
/*
	Initializes the Controller
*/

void destroy_controller(Controller* controller);
/*
	Dealocated the memory 
*/

int addElem(Controller* controller,char* name, char* continent, int population);
/*
	Adds an element
	Input: Controller* - The controller to which it should be added
			char* - name ,  continent
			int  - population
	Output: 1 if the element was added successfully
			0 otherwise
*/

int deleteElem(Controller* controller, char* name);
/*
Deletes an element
Input : Controller * -The controller from which it should be deleted
		char* -name
Output : 1 if the element was deleted successfully
		 0 otherwise
*/
int updateElem(Controller* controller, char* old_name, char* new_continent, int new_population, int mg);
/*
	Updates an element
	Input: Controller* - The controller 
			char* - old_name , new_continent
			int  - new_population
			int -mg = 1 if the update is comming from migration, 0 otherwise
	Output: 1 if the element was updated successfully
			0 otherwise
*/

int migrateFromTo(Controller* controller, char* from_name, char* to_name, int nr_population);
/*
	Moves the population from one country to another
	Input: Controller* - The controller
			char* - from_name ,  to_name
			int  - nr_population
	Output: 1 if the migration took place successfully
			0 otherwise
*/

TElem* get_all(Controller* controller);
/*
	Returns all elements of the controller
	Input: Controller 
	Output: TElem* - the list of elemenys from the repository
*/

int get_repo_size(Controller* controller);
/*
	Returns the an integer representing the number of elemets in the controller
*/

void search_name(Controller* controller, char name[],int* len, TElem* search_result);
/*
	Selects all countries with the given name, and considers all of them is the name is an empty string
	Input: 
			Controller* controller - The controller
			char name[] - the continentS we are searching for
			int* len - will be the final number of elements that fit the requirement
			TElem* search_result - the list of elements that fit the requirement
*/

void search_continent(Controller* controller, char continent[],int* len, TElem search_result[]);
/*
	Selects all countries with the given name, and considers all of them is the name is an empty string
	Input:
			Controller* controller - The controller
			char name[] - the name we are searching for
			int* len - will be the final number of elements that fit the requirement
			TElem* search_result - the list of elements that fit the requirement
*/

void filter_population_greater(Controller* controller, int value_greater, TElem * list, int* len);
/*
	Selects all countries with the given name, and considers all of them is the name is an empty string
	Input:
			Controller* controller - The controller
			int value_greater - the value wee need the population to be greater than
			TElem * list -  the list of elements that fit the requirement
			int* len - will be the final number of elements that fit the requirement
*/

int undo(Controller* c, int* been_here_undo);
/*
	Reverses the damage done by the last operation
*/

int redo(Controller* c, int* been_here_undo);
/*
	Reverses the damage done by the last undo
*/


void Test_Controller();
