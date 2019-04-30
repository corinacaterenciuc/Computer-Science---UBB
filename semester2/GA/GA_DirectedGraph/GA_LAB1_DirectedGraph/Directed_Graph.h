#pragma once
#include <map>
#include <vector>
#include <iterator>


class Directed_Graph
{
private:
	std::map<int, std::vector<int>> inbound;
	std::map<int, std::vector<int>> outbound;
	std::map<std::pair<int, int>, int> edges_cost;
	int nr_vertices;
public:
	Directed_Graph(int nr_ver );

	std::map<int, std::vector<int>> get_inbound();
	std::map<int, std::vector<int>> get_outbound();
	std::map<std::pair<int, int>, int> get_edges_cost();
	int get_nr_vertices();


	bool is_edge(int v1, int v2);
	bool add_edge(int v1, int v2, int c);
	bool remove_edge(int v1, int v2);
	bool is_vertex(int v);
	bool add_vertex(int v);
	bool remove_vertex(int v);

	int get_cost(int v1, int v2);
	bool set_cost(int v1, int v2, int new_c);

	std::vector<int> parce_verteces();
	std::vector<int>::iterator parce_inbound(int v);
	std::vector<int>::iterator parce_outbound(int v);

	~Directed_Graph();
};

