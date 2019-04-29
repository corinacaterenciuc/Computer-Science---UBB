#pragma once

typedef struct
{
	char *name, *continent;
	int population;

}Country;


Country* init(char*, char*, int);
/*
Creates a new country withe the given name, continent and population
Input: char* -  name (the name of the country), continent (the continent of the country)
Output:int  - population (population in millions)
*/


void destroyCountry(Country*);
/*
Dealocates the memory
*/

int compareCountry(Country*, Country*);
/*
Compares two given countries
Input: Country - two countries
Output: 0 if the countries are equal
		1 if the first country is greater 
		and -1 otherwise
*/
void addPopulation(Country*, int );
/*
Adds the given number of population to the existing one
Input: Country - the country that will be modified
		int - the number of people to be added
Output: the modifies country
*/
void toString(Country*, char*);
/*
Trnsforms the given country into a print-able string
Input: Country - the country to be printed
		char - the string to be printed
Output:  the second parameter modified
*/

char* getName(Country* country);

char* getContinent(Country* country);

int getPopulation(Country* country);

Country* copyCountry(Country* country);

void Test_Country();