#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include "main_oganesyan.h"
using namespace std;
using namespace std::chrono;

bool graphcoloringutil(vector<Edge2>& edges, int vertex, vector<int>& colors, int& numcolors) {
    if (vertex == colors.size()) {
        /*cout << "Number of colors: " << numcolors << endl;
        cout << "----------------------" << endl;
        for (int i = 0; i < colors.size(); i++) {
            cout << "Vertex " << i << " -> Color: " << colors[i] << endl;
        }*/
        return true;
    }
    unordered_set<int> usedcolors;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].src == vertex) {
            int neighbor = edges[i].dest;
            if (colors[neighbor] != -1) {
                usedcolors.insert(colors[neighbor]);
            }
        }
        else if (edges[i].dest == vertex) {
            int neighbor = edges[i].src;
            if (colors[neighbor] != -1) {
                usedcolors.insert(colors[neighbor]);
            }
        }
    }
    for (int color = 0; color < numcolors; color++) {
        if (usedcolors.find(color) == usedcolors.end()) {
            colors[vertex] = color;
            if (graphcoloringutil(edges, vertex + 1, colors, numcolors)) {
                return true;
            }
            colors[vertex] = -1;
        }
    }
    return false;
}
vector<int> GTS::graphcoloring(vector<Edge2>& edges, int& numcolors, int numvertices) {
    vector<int> colors(numvertices, -1);
    while (!graphcoloringutil(edges, 0, colors, numcolors)) {
        numcolors++;
        colors.assign(numvertices, -1);
    }
    return colors;
}
