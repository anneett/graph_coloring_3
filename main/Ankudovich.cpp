#include <iostream>
#include <list>
#include "Ankudovich.h"

using namespace std;

void Graph1::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int* Graph1::greedyColoring()
{
    int* result2 = new int[V];

    result2[0] = 0;

    for (int u = 1; u < V; u++)
        result2[u] = -1;

    bool* available = new bool[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;

    for (int u = 1; u < V; u++)
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result2[*i] != -1)
                available[result2[*i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;

        result2[u] = cr;

        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result2[*i] != -1)
                available[result2[*i]] = false;
    }

    //for (int u = 0; u < V; u++)
    //    cout << "Vertex " << u << " ---> Color "
    //    << result[u] << endl;
    delete[] available;
    return result2;
}