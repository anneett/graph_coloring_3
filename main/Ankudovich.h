#pragma once
#include <list>

using namespace std;

struct Graph1
{
    int V;
    list<int>* adj;

    Graph1(int V) { this->V = V; adj = new list<int>[V]; }
    ~Graph1() { delete[] adj; }

    void addEdge(int v, int w);
    int* greedyColoring();
};