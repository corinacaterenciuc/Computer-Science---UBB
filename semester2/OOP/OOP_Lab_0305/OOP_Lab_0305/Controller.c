#include "Controller.h"
#include <stdlib.h>
#include "Repository.h"
#include <assert.h>
#include <string.h>
#include "Operation_OperStack.h"


Controller * init_controller(Repository * repo, OperationsStack* undo_stack, OperationsStack* redo_stack)
{
	Controller* controller = (Controller*)malloc(sizeof(Controller));
	controller->repo = repo;
	controller->undo_stack = undo_stack;
	controller->redo_stack = redo_stack;
	return controller;
}

void destroy_controller(Controller* controller)
{
	free(controller);
}

int addElem(Controller* controller, char * name, char * continent, int population)
{
	Country* country = init(name, continent, population);
	int ok= addElement(controller->repo, country);

	if (ok == 1)
	{
		Operation* o = createOperation(country, "add");
		push(controller->undo_stack, o);

		destroyOperation(o);
	}
	destroyCountry(country);
	return ok;
	
}

int deleteElem(Controller * controller, char * name)
{
	Country* country = init(name, " ", 0);
	Country* ok_country = deleteElement(controller->repo, country);

	if (ok_country != NULL)
	{
		Operation* o = createOperation(ok_country, "delete");
		push(controller->undo_stack, o);

		destroyOperation(o);
	}

	destroyCountry(country);
	destroyCountry(ok_country);

	if(ok_country!=NULL)
		return 1;

	return 0;
}

int updateElem(Controller * controller, char * old_name, char * new_continent, int new_population, int mg )
{
	Country *c_old = init(old_name, " ", 0);
	Country *c_new = init(old_name, new_continent, new_population);

	Country* old_ver_c =  updateElement(controller->repo, c_old, c_new);
	if (old_ver_c != NULL)
		if (mg == 0)
		{
			Operation* o = createOperation(old_ver_c, "update");
			push(controller->undo_stack, o);
			destroyOperation(o);
		}
		else
		{
			Operation* om = createOperation(old_ver_c, "migrate");
			push(controller->undo_stack, om);
			destroyOperation(om);
		}
	destroyCountry(c_old);
	destroyCountry(c_new);

	if (old_ver_c != NULL)
		destroyCountry(old_ver_c);
		return 1;
		destroyCountry(old_ver_c);
	return 0;
}

int migrateFromTo(Controller * controller, char * from_name, char * to_name, int nr_population)
{
	int ok = 0;
	int from_pos = 0, to_pos = 0;
	TElem* list = get_all(controller);
	Country* from_country = init(from_name, " ", 0);
	Country* to_country = init(to_name, " ",0);

	for (int i = 0; i < get_repo_size(controller); i++)
	{
		if (compareCountry(list[i], from_country) == 0)
		{
			from_pos = i;
			ok++;
		}
		if (compareCountry(list[i], to_country) == 0)
		{
			to_pos = i;
			ok++;
		}

	}
	if (ok == 2)
	{
		Country* update_from_c = init(list[from_pos]->name, list[from_pos]->continent, list[from_pos]->population - nr_population);
		updateElem(controller, from_name, update_from_c->continent, update_from_c->population,1);
		destroyCountry(update_from_c);

		Country* update_to_c = init(list[to_pos]->name, list[to_pos]->continent, list[to_pos]->population + nr_population);
		updateElem(controller, to_name, update_to_c->continent, update_to_c->population,1);
		destroyCountry(update_to_c);

		destroyCountry(from_country);
		destroyCountry(to_country);

		return 1;
	}
	destroyCountry(from_country);
	destroyCountry(to_country);
	return 0;
}

TElem * get_all(Controller * controller)
{
	return getAll(controller->repo);
}

int get_repo_size(Controller * controller)
{
	return getSize(controller->repo);
}

 void search_name(Controller * controller, char name[], int* len, TElem* search_result)
{

	searchByName(controller->repo, name, len, search_result);
}

void search_continent(Controller * controller, char continent[],int *len, TElem search_result[])
{
	TElem* list = getAll(controller->repo);
	*len = 0;

	int count = 1;

	for (int i = 0; i < getSize(controller->repo); i++)
	{
		if (strstr(list[i]->continent, continent) != NULL || strcmp(continent, " ") == 0)
			search_result[(*len)++] = list[i];
	}

}

void filter_population_greater(Controller * controller, int value_greater, TElem * list, int * len)
{
	filterPopulationGreater(controller->repo, value_greater, list, len);
}

int undo(Controller * c,int* been_here_undo)
{
	if (isEmpty(c->undo_stack))
		return 0;
	Operation* oper = pop(c->undo_stack);

	if (strcmp(getOperationType(oper), "add") == 0)
	{
		Country* country = getCountry(oper);
		char name[100];
		strcpy(name, getName(country));
		Country* ret_delete_c_add =deleteElement(c->repo, country);
		push(c->redo_stack, oper);
		destroyCountry(ret_delete_c_add);
	}
	else if (strcmp(getOperationType(oper), "delete") == 0)
	{
		Country* country_del = getCountry(oper);
		addElement(c->repo, country_del);
		push(c->redo_stack, oper);
		

	}
	else if (strcmp(getOperationType(oper), "migrate") == 0)
	{
		Country* country_old1 = getCountry(oper);
		Country* name_country1 = init(getName(country_old1), " ", 0);
		Country* country_new1 = updateElement(c->repo, name_country1, country_old1);
		Operation* redo_oper1 = createOperation(country_new1, "migrate");
		push(c->redo_stack, redo_oper1);
		if ((*been_here_undo) == 0)
		{
			(*been_here_undo)++;
			undo(c,been_here_undo);
		}

		destroyCountry(name_country1);
		destroyCountry(country_new1);
		destroyOperation(redo_oper1);
			
		
	}
	else if(strcmp(getOperationType(oper), "update") == 0)
	{
		Country* country_old2 = getCountry(oper);
		Country* name_country2 = init(getName(country_old2), " ", 0);
		Country* country_new2 = updateElement(c->repo, name_country2, country_old2);
		Operation* redo_oper2 = createOperation(country_new2, "update");
		push(c->redo_stack, redo_oper2);

		destroyCountry(name_country2);
		destroyCountry(country_new2);
		destroyOperation(redo_oper2);
		
	}
	destroyOperation(oper);
	return 1;
}

int redo(Controller * c,int* been_here_redo)
{
	if(isEmpty(c->redo_stack))
		return 0;
	Operation* r_oper = pop(c->redo_stack);
	if (strcmp(getOperationType(r_oper), "add") == 0)
	{
		Country* country_add = getCountry(r_oper);
		addElement(c->repo, country_add);

	}
	else if (strcmp(getOperationType(r_oper), "delete") == 0)
	{
		
		Country* country_del = getCountry(r_oper);
		char name[100];
		strcpy(name, getName(country_del));
		Country* ret_del = deleteElement(c->repo, country_del);
		destroyCountry(ret_del);
	}
	else if (strcmp(getOperationType(r_oper), "migrate") == 0)
	{
		
		Country* country_new = getCountry(r_oper);
		Country* name_country = init(getName(country_new), " ", 0);
		Country* ret_update = updateElement(c->repo, name_country, country_new);

		destroyCountry(ret_update);
		destroyCountry(name_country);
		
		if ((*been_here_redo)== 0)
		{
			(*been_here_redo)++;
			redo(c,been_here_redo);

		}
		
	}
	else if (strcmp(getOperationType(r_oper), "update") == 0)
	{
		Country* country_new1 = getCountry(r_oper);
		Country* name_country1 = init(getName(country_new1), " ", 0);
		Country* ret_update1 = updateElement(c->repo, name_country1, country_new1);

		destroyCountry(ret_update1);
		destroyCountry(name_country1);
	}
	destroyOperation(r_oper);
	return 1;
}





void Test_Controller()
{
	Repository* repo = init_repo(100);
	OperationsStack* operationsstack_undo = createStack();
	OperationsStack* operationsstack_redo = createStack();

	Controller* cont = init_controller(repo, operationsstack_undo, operationsstack_redo);


	assert(addElem(cont, "romania", "europa", 19) == 1);
	assert(addElem(cont, "franta", "europa", 25) == 1);
	assert(updateElem(cont, "franta", "evest", 23,0) == 1);
	assert(addElem(cont, "chile", "america", 45) == 1);
	assert(addElem(cont, "romania", "europa", 19) == 0);

	assert(get_repo_size(cont) == 3);
	assert(deleteElem(cont, "romania") == 1);
	assert(get_repo_size(cont) == 2);

	
	TElem* list = getAll(cont->repo);
	assert(strcmp(getContinent(list[0]), "evest") == 0);

	assert(migrateFromTo(cont, "chile", "franta", 2) == 1); // befor : chile 45; franta - 23 |after:chile 43; franta - 25
	assert(migrateFromTo(cont, "chile", "malta", 2) == 0);

	//Testing the functionalities: search_name, search_continent, filter_population_greater
	TElem result[10];
	int len = 0;
	int* lenp = &len;

	search_name(cont, " ", lenp, result);
	assert(len == 2);
	filter_population_greater(cont, 10,result, lenp);
	assert(len == 2);
	len = 0;
	search_name(cont, "ta", lenp, result);
	assert(len == 1);
	len = 0;
	search_continent(cont, " ", lenp, result);
	assert(len == 2);
	filter_population_greater(cont, 30,result, lenp);
	assert(len == 1);
	len = 0;
	search_continent(cont, "america", lenp, result);
	assert(len == 1);
	//----------------------------------------------------------------------------------------

	//Testing Undo - Redo

	assert(getPopulation(list[0]) == 25);
	assert(getPopulation(list[1]) == 43);

	int been_here = 0;
	int* been_here_p = &been_here;
	undo(cont, been_here_p);
	assert(getPopulation(list[0]) == 23);
	assert(getPopulation(list[1]) == 45);

	undo(cont, been_here_p);
	assert(get_repo_size(cont) == 3);

	undo(cont, been_here_p);
	assert(get_repo_size(cont) == 2);

	//---

	redo(cont, been_here_p);
	assert(get_repo_size(cont) == 3);

	redo(cont, been_here_p);
	assert(get_repo_size(cont) == 2);

	been_here = 0;
	redo(cont, been_here_p);
	assert(getPopulation(list[0]) == 25);
	assert(getPopulation(list[1]) == 43);


	destroyArray(repo);
	destroyStack(operationsstack_redo);
	destroyStack(operationsstack_undo);
	destroy_controller(cont);
}
