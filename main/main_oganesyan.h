#pragma once

#include <iostream>
#include "amirova.h"
#include "grigorova.h"

using namespace std;

template <typename T>
T GetCorrectInt(T min, T max)
{
	T x;
	while ((cin >> x).fail() || (cin).peek() != '\n' || x < min || x > max)
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nEnter the correct data! Type integer number (" << min << " - " << max << "):";
		cout << "\nEnter: ";
	}
	return x;
}

struct Edge2 {
	int src, dest;
};

class GTS
{
public:
	vector<int> graphcoloring(vector<Edge2>& edges, int& numcolors, int numvertices);

	unordered_map<int, int> Jones_Plassman(int vertex_number, vector<vector<int>> edges_vector);

	pair<vector<int>, int> welsh_powell(vector<Edge2> edges, int V);

	void colorGraph(Graph const& graph, int n);

	//void addEdge(int v, int w);

	//void greedyColoring(vector<vector<int>>& graph, int V);
};
