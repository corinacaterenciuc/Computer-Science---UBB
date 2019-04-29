#include <stdlib.h>
#include <stdio.h>
#include <crtdbg.h> 
#include "Repository.h"
#include "Country.h"
#include <assert.h>
#include <string.h>


Repository* init_repo(int cap)//, destroyFunctionType d)
{
	Repository *countries = (Repository*)malloc(sizeof(Repository));

	// if there is not enough memory then the malloc will give a null, i e we should check for null!

	countries->arr = (TElem*)malloc(cap * sizeof(TElem));
	countries->size = 0;
	countries->cap = cap;
	//countries->destroyFct = d;

	return countries;


}

void destroyArray(Repository* repo)//(*fct)(TElem)
//using free, in reverse order!
{
	
	if (repo != NULL)
	{
		for (int i = 0; i < repo->size; i++)
			//repo->destroyFct(repo->arr[i]);
			//countries->destroyFct(countries->arr[i]);
			destroyCountry(repo->arr[i]);
		free(repo->arr);
	}
		
	free(repo);
}

void reSize(Repository* countries)
{
	countries->cap *= 2;
	TElem* arr2 = (TElem*)malloc(countries->cap * sizeof(TElem));
	for (int i = 0; i < countries->size; i++)
	{
		arr2[i] = countries->arr[i];

	}
	free(countries->arr); // access violation??
	countries->arr = arr2;

}

int addElement(Repository* countries, TElem el)
//trow exception if the country already exists

{
	int found = 0;
	for (int i = 0; i < countries->size; i++)
	{
		if (compareCountry(countries->arr[i], el) == 0)
			found = 1;
	}
	if (found == 0)
	{
		if (countries->size >= countries->cap)
		{
			reSize(countries);
		}
		countries->arr[countries->size++] = copyCountry(el);
		return 1;
	}

	return 0;
	

}

TElem* deleteElement(Repository* countries, TElem el)
// trow exception if the country does not exist
{
	int found = 0;
	for (int i = 0; i < countries->size; i++)
	{
		if (compareCountry(countries->arr[i], el) ==0)
		{
			found = 1;
			countries->size -= 1;
			Country* return_country = copyCountry(countries->arr[i]);
			destroyCountry(countries->arr[i]);
			for (int j = i; j < countries->size; j++)
			{
				
				countries->arr[j] = countries->arr[j + 1];
			}
			return return_country;
		}
	}
	return NULL;
}

Country* updateElement(Repository* countries, TElem old_el, TElem new_el)
{
	
	for (int i = 0; i < countries->size; i++)
		if (compareCountry(countries->arr[i], old_el) == 0)
		{
		
			Country* old_country = countries->arr[i];
			//destroyCountry(countries->arr[i]);
			countries->arr[i] = copyCountry(new_el);
			return old_country;
		}
	return NULL;
}





int getSize(Repository * repo)
{
	return repo->size;
}

TElem* getAll(Repository* countries)
{
	return countries->arr;
}

void searchByName(Repository * repo, char name[], int* len, TElem* result)
{
	//TElem result[1000];
	*len = 0;
	
	for (int i = 0; i < repo->size; i++)
	{
		if (strstr(getName(repo->arr[i]), name) != NULL || strcmp(name, " ") == 0)
		{
			result[(*len)++] = repo->arr[i];

		}

	}
	//return result;
}

void filterPopulationGreater(Repository * repo, int value_greater, TElem * list, int * len)
{
	int i = 0;
	while (i < *len)
	{
		if (getPopulation(list[i]) <= value_greater)
		{
			for (int j = i; j < (*len) - 1; j++)
			{
				list[j] = list[j + 1];
			}
			(*len) -= 1;
		}
			
		else i++;
	}
}

void Test_Repository()
{
	Country *c1 = init("Romania", "Europa", 19);
	Country* c2 = init("Austria", "Europa", 15);
	Country* c2_1 = init("Austria", "Europa", 20);

	Repository* repo = init_repo(100);

	assert(addElement(repo, c1) == 1);
	assert(addElement(repo, c1) == 0);
	assert(addElement(repo, c2) == 1);

	assert(getSize(repo) == 2);
	Country* c3 = deleteElement(repo, c2);
	assert(c3 != NULL);
	assert(getSize(repo) == 1);
	assert(addElement(repo, c3) == 1);
	Country* update_return_c = updateElement(repo, c3, c2_1);
	assert(update_return_c!=NULL);
	assert(repo->arr[1]->population == 20);

	int len = 0;
	int* lenp = &len;
	TElem result[1000];

	searchByName(repo, "o", lenp, result);
	assert(len == 1);
	filterPopulationGreater(repo, 10, result, lenp);
	assert(len == 1);

	destroyCountry(c1);
	destroyCountry(c2_1);
	destroyCountry(c2);
	destroyCountry(c3);
	destroyCountry(update_return_c);
	
	destroyArray(repo);


}



