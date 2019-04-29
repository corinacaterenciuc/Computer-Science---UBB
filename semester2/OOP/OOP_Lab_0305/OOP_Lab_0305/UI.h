#pragma once
#include "Controller.h"

typedef struct
{
	Controller* cont;
}UI;

UI* init_ui(Controller* controller);

void destroy_ui(UI* ui);

void add_ui(UI* ui);

void delete_ui(UI* ui);

void update_ui(UI* ui);

void migrateFromTo_ui(UI* ui);

void print_all_ui(UI* ui);

void print_list_ui(UI* ui, TElem list[], int len);

void search_name_ui(UI* ui);

void sort_ascending_name( TElem v[1000], int len_v);

void sort_ascending_name(TElem v[1000], int len_v);

void activity(UI* ui);

//void req_c_ui(UI* ui);

//void print_vector(UI* ui, TElem v[], int len_v);

void existing_values(UI* ui);

void print_menu(UI* ui);



int start_ui(UI* ui);























