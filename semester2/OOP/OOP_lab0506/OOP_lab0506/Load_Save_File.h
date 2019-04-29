#pragma once
#include <fstream>
#include "Tutorial.h"
#include <vector>
#include <iostream>

using namespace std;

void load_tutorials(std::vector<Tutorial>& vect)
{
	ifstream f("tutorials.csv");
	if (!f.is_open())
		return;

	Tutorial t{};
	while (f >> t)
	{
		vect.push_back(t);
	}
	f.close();
}

void save_tutorials(std::vector<Tutorial> vect)
{
	ofstream f("tutorials.csv", ios::app);
	if (!f.is_open())
		return;

	for (auto t : vect)
	{
		f << t;
	}

	f.close();
}