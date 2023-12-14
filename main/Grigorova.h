#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

struct Edge1 {
    int src, dest;
};

struct Graph
{
    vector<vector<int>> adjList;

    Graph(vector<Edge1> const& edges, int n)
    {
        adjList.resize(n);

        for (Edge1 edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};
