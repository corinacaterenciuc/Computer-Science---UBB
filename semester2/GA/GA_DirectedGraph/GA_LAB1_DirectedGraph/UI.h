#pragma once
#include "Directed_Graph.h"
class UI
{
private:
	Directed_Graph g;
public:
	UI(Directed_Graph &g_given);


	void print_menu();
	void start();


	~UI();
};

