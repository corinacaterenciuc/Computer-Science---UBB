#include "UI.h"
#include <iostream>




UI::UI(Directed_Graph & g_given): g{g_given}
{
}

void UI::print_menu()
{
	std::cout << "\t 1. print graph \n";
	std::cout << "\t 2. get the number of vertices \n";
	std::cout << "\t 3. find if there is an edge between two vertices \n";
	std::cout << "\t 4. get in degree of vertex \n";
	std::cout << "\t 5. get out degree of vertex \n";
	std::cout << "\t 6. get cost of an edge \n";
	std::cout << "\t 7. set cost of an edge \n";
	std::cout << "\t 8. add vertex \n";
	std::cout << "\t 9. remove vertex \n";
	std::cout << "\t 10. add edge \n";
	std::cout << "\t 11. remove edge \n";
}

void UI::start()
{
	bool work = true;
	while (work)
	{
		this->print_menu();
		int op;
		std::cout << "your option >> ";
		std::cin >> op;
		auto inb = this->g.get_inbound();
		auto outb = this->g.get_outbound();
		if (op == 1)
		{
			auto vert = this->g.parce_verteces();
			auto edge_cost = this->g.get_edges_cost();
			auto it = vert.begin();
			while (it != vert.end())
			{
				if (inb[*it].size() == outb[*it].size() && outb[*it].size() == 0)
					std::cout << *it << " - isolated vertex" << "\n";
				else
				{
					auto it_out = outb[*it].begin();
					for (; it_out != outb[*it].end(); ++it_out)
					{
						std::cout << *it << " -> " << *it_out << " cost = " << this->g.get_cost(*it, *it_out) << "\n";

					}
				}
				it++;
			}

		}
		else if (op == 2)
		{
			std::cout << "the number of vertices is: " << this->g.get_nr_vertices() << "\n";
		}
		else if (op == 3)
		{
			int v1, v2;
			std::cout << " give vertex 1 >> ";
			std::cin >> v1;
			std::cout << "give vertex 2 >> ";
			std::cin >> v2;
			if (this->g.is_edge(v1, v2))
				std::cout << "there exists an edge between " << v1 << " and " << v2 << "\n";
			else
				std::cout << "there is no edge between the given vertices!\n";
		}
		else if (op == 4)
		{
			int v;
			std::cout << "give the vertex >> ";
			std::cin >> v;
			std::cout << "the degree is: " << inb[v].size() << "\n";
		}
		else if (op == 5)
		{
			int v;
			std::cout << "give the vertex >> ";
			std::cin >> v;
			std::cout << "the degree is: " << outb[v].size()<< "\n";
		}
		else if (op == 6)
		{
			int v1, v2;
			std::cout << "give the start vertex >> ";
			std::cin >> v1;
			std::cout << "give the end vertex >> ";
			std::cin >> v2;
			if (this->g.is_edge(v1, v2))
				std::cout << "the cost is: " << this->g.get_cost(v1, v2) << "\n";
			else
				std::cout << "there is no edge eith the given vertices\n";
		}
		else if (op == 7)
		{
			int v1, v2,c;
			std::cout << "give the start vertex >> ";
			std::cin >> v1;
			std::cout << "give the end vertex >> ";
			std::cin >> v2;
			std::cout << "give the new cost >> ";
			std::cin >> c;
			if (this->g.set_cost(v1,v2,c))
			{
				std::cout << "the cost was set successfully" << "\n";
			}
			else
				std::cout << "there is no edge eith the given vertices\n";
		}
		else if (op == 8)
		{
			int v;
			std::cout << "give vertex >> ";
			std::cin >> v;
			if (this->g.add_vertex(v))
				std::cout << "vertex added successfully!\n";
			else
				std::cout << "the given vertex already exists!\n";
		}
		else if (op == 9)
		{
			int v;
			std::cout << "give vertex >> ";
			std::cin >> v;
			if (this->g.remove_vertex(v))
				std::cout << "vertex removed successfully!\n";
			else
				std::cout << "the given vertex does not exist!\n";

		}
		else if (op == 10)
		{
			int v1, v2, c;
			std::cout << "give the start vertex >> ";
			std::cin >> v1;
			std::cout << "give the end vertex >> ";
			std::cin >> v2;
			std::cout << "give the cost >> ";
			std::cin >> c;
			if (this->g.add_edge(v1, v2, c))
			{
				std::cout << "the edge was added successfully" << "\n";
			}
			else
				std::cout << "there edge already exists\n";
		}
		else if (op == 11)
		{
			int v1, v2;
			std::cout << "give the start vertex >> ";
			std::cin >> v1;
			std::cout << "give the end vertex >> ";
			std::cin >> v2;
			if (this->g.remove_edge(v1, v2))
			{
				std::cout << "the edge was removed successfully" << "\n";
			}
			else
				std::cout << "there is no edge with the given vertices\n";
		}
		else if (op == 0)
			work = false;
		else 
		std::cout << "Invalid option! Try again..\n";
	}

}

UI::~UI()
{
	//no memory to destroy
}
