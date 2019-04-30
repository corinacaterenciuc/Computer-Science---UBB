#include "Directed_Graph.h"



Directed_Graph::Directed_Graph(int nr_ver )
{
	this->nr_vertices = nr_ver;
	for (int i = 0; i < this->nr_vertices; i++)
	{
		std::vector<int> v_in;
		std::vector<int> v_out;
		this->inbound[i] = v_in;
		this->outbound[i] = v_out;
	}
}

std::map<int, std::vector<int>> Directed_Graph::get_inbound()
{
	return this->inbound;
}

std::map<int, std::vector<int>> Directed_Graph::get_outbound()
{
	return this->outbound;
}

std::map<std::pair<int, int>, int> Directed_Graph::get_edges_cost()
{
	return this->edges_cost;
}

int Directed_Graph::get_nr_vertices()
{
	return this->nr_vertices;
}

bool Directed_Graph::is_edge(int v1, int v2)
{
	for (std::vector<int>::iterator it = this->outbound[v1].begin(); it != this->outbound[v1].end(); ++it)
	{
		if (v2 == *it)
			return true;
	}
	return false;
}

bool Directed_Graph::add_edge(int v1, int v2, int c)
{
	std::pair <int, int> edge;
	edge = std::make_pair(v1, v2);
	if (!this->is_edge(v1, v2))
	{
		this->inbound[v2].push_back(v1);
		this->outbound[v1].push_back(v2);
		this->edges_cost[edge] = c;
		return true;
	}
	return false;
}

bool Directed_Graph::remove_edge(int v1, int v2)
{
	std::pair <int, int> edge;
	edge = std::make_pair(v1, v2);
	if (this->is_edge(v1, v2))
	{
		std::vector<int>::iterator it_in = std::find(this->inbound[v2].begin(), this->inbound[v2].end(), v1);
		this->inbound[v2].erase(it_in);
		std::vector<int>::iterator it_out = std::find(this->outbound[v1].begin(), this->outbound[v1].end(), v2);
		this->outbound[v1].erase(it_out);
		this->edges_cost.erase(edge);
		return true;

	}
	return false;
}

bool Directed_Graph::is_vertex(int v)
{
	std::map<int, std::vector<int>>::iterator it;
	it = this->inbound.find(v);
	if(it == this->inbound.end())
		return false;
	return true;
}

bool Directed_Graph::add_vertex(int v)
{
	if(this->is_vertex(v))
		return false;
	std::vector<int> v_in;
	std::vector<int> v_out;
	this->inbound[v] = v_in;
	this->outbound[v] = v_out;
	this->nr_vertices += 1;
	return true;
}

bool Directed_Graph::remove_vertex(int v)
{
	if (this->is_vertex(v))
	{
		std::vector<int> ins;
		std::vector<int>::iterator it = this->inbound[v].begin();
		for (std::vector<int>::iterator it = this->inbound[v].begin(); it !=  this->inbound[v].end(); ++it) // ERROR: cannot increment past end!
		{
			ins.push_back(*it);
		}
		for (auto v1 : ins)
		{
			this->remove_edge(v1, v);
		}
		std::vector<int> outs;
		for (std::vector<int>::iterator it = this->outbound[v].begin(); it != this->outbound[v].end(); ++it)
		{
			outs.push_back(*it);
		}
		for (auto v2 : outs) {
			this->remove_edge(v,v2);
		}
		this->inbound.erase(v);
		this->outbound.erase(v);
		this->nr_vertices--;
		return true;

	}
	return false;
}

int Directed_Graph::get_cost(int v1, int v2)
{
	std::pair <int, int> edge;
	edge = std::make_pair(v1, v2);
	if (this->is_edge(v1, v2))
		return this->edges_cost[edge];
	return -1;
}

bool Directed_Graph::set_cost(int v1, int v2, int new_c)
{
	std::pair <int, int> edge;
	edge = std::make_pair(v1, v2);
	if (this->is_edge(v1, v2))
	{
		this->edges_cost[edge] = new_c;
		return true;
	}
	return false;
}

std::vector<int> Directed_Graph::parce_verteces()
{
	std::vector<int> verteces;
	for (auto it = this->inbound.begin(); it != this->inbound.end(); ++it)
	{
		verteces.push_back(it->first);
	}
	//return verteces.begin();
	return verteces;
}

std::vector<int>::iterator Directed_Graph::parce_inbound(int v)
{
	return this->inbound[v].begin();
}

std::vector<int>::iterator Directed_Graph::parce_outbound(int v)
{
	return this->outbound[v].begin();
}

Directed_Graph::~Directed_Graph()
{
	//no memory to destroy
}
