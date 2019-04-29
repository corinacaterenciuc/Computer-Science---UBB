#include "Country.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
Country* init(char* name, char* continent, int population)
{
	Country *country = (Country*)malloc(sizeof(Country));

	country->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	strcpy(country->name, name);

	country->continent = (char*)malloc((strlen(continent) + 1) * sizeof(char));
	strcpy(country->continent,continent);

	country->population = population;

	return country;
}


void destroyCountry(Country* country)
{
	if (country != NULL)
	{
		free(country->continent);
		free(country->name);
		
	}

	free(country);
}


int compareCountry(Country* c1, Country* c2)
{
	return strcmp(c1->name, c2->name);
}

//void addPopulation(Country* country, int new_population)
//{
//	country->population += new_population;
//	
//}

void toString(Country* country, char* string_country)
{
	
	char  population_string[1000];
	strcpy(string_country, country->name);
	strcat(string_country, " ");
	strcat(string_country,country->continent);
	_itoa(country->population, population_string, 10);
	strcat(string_country, " ");
	strcat(string_country, population_string);
	strcat(string_country,  "mil");
}


char * getName(Country * country)
{
	return country->name;
}

char * getContinent(Country * country)
{
	return country->continent;
}

int getPopulation(Country * country)
{
	return country->population;
}

Country * copyCountry(Country * country)
{
	if (country == NULL)
	{
		return NULL;
	}
	Country* new_country = init(getName(country), getContinent(country), getPopulation(country));
	return new_country;
}

void Test_Country()
{
	Country *c1 = init("Romania", "Europa", 19);
	Country* c2 = init("Austria", "Europa", 15);

	char prt_str[1000];

	assert(strcmp(c1->continent, "Europa") == 0);
	assert(strcmp(c2->name, "Austria") == 0);
	assert(compareCountry(c1, c2) != 0);



	toString(c1, prt_str);
	assert(strcmp(prt_str, "Romania Europa 19mil") == 0);

	destroyCountry(c1);
	destroyCountry(c2);
}

