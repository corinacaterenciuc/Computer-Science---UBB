#include <iostream>
#include "Directed_Graph.h"
#include "UI.h"

#include <fstream>

using namespace std;

int main()
{
	ifstream f("input.txt");
	int n, m;
	int v1, v2, c;
	if (f.is_open())
	{
		f >> n;
		f >> m;
		Directed_Graph g{ n };
		for (int i = 0; i < m; i++)
		{
			f >> v1;
			f >> v2;
			f >> c;
			g.add_edge(v1, v2, c);
		}
		UI ui{ g };
		ui.start();
	}
	else
		f.close();
	

	return 0;

}