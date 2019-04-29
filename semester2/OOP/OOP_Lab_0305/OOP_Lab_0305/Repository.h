#pragma once
#include "Country.h"


typedef  Country*  TElem; // you can have any data structure inseead of int!

//typedef void(*destroyFunctionType)(TElem);


typedef struct
{
	TElem* arr;
	int size, cap;
	//destroyFunctionType destroyFct;
}Repository;

Repository* init_repo(int cap);//, destroyFunctionType d);
/*
	Initializes the dynamic vector with the given capacity
*/

void destroyArray(Repository*);
/*
	Dealocated the memory of the dynamic array
*/

int addElement(Repository*, TElem);
/*
	Adds an element to the repository
	Input: Repository - the repository to which it should be added
			TElem - the element to be added
	Output: 1 if the element was added successfully
			0 otherwise
*/

TElem* deleteElement(Repository*, TElem);
/*
	Deletes an element from the repository
	Input: Repository - the repository from which it should be deleted
			TElem - the element to be deleted
	Output: 1 if the element was deleted successfully
			0 otherwise
*/

Country* updateElement(Repository*, TElem, TElem);
/*
	Updates an element by replacing it with the updated version
	Input: Repository - the repository where the element will be updated
			TElem - the element to be updated
			TElem - the updated version of the element
	Output: 1 if the element was updated successfully
			0 otherwise
*/


int getSize(Repository* repo);
/*
	Gives the size of the repository
	Input: Repository - the repository whose size is of interest
	Output: int - the size of the given repository
*/

TElem* getAll(Repository*);
/*
	Gives the list of elements from the given repository
	Input: Repository - the repository whose elemets are of interest
	Output: all elements in the given repository
*/

void searchByName(Repository * repo, char name[],int *len, TElem* result);
/*
	Gives all countries with the given name
	Input: Repository * repo - the repository whose elemets are of interest
		  char name[] - the name we search for
		  int *len  - the number of elements that meet the requirements
		  TElem* result - the list of elemets that meet the requirement 

*/

void filterPopulationGreater(Repository* repo, int value_greater, TElem* list, int *len);
/*
	Gives all countries with population greater than the given value
	Input: Repository * repo - the repository whose elemets are of interest
		  cint value_greater - the lower limit of the population
		  int *len  - the number of elements that meet the requirements
		  TElem* list - the list of elemets that meet the requirement 
*/

void Test_Repository();
