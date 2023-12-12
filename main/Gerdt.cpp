#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <iostream>
#include "main_oganesyan.h"

using namespace std;

bool compareDegrees(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

pair<vector<int>, int> GTS::welsh_powell(vector<Edge2> edges, int V) {
    vector<pair<int, int>> degrees;
    for (int i = 0; i < V; ++i) {
        int degree = 0;
        for (const Edge2& e : edges) {
            if (e.src == i || e.dest == i) {
                degree++;
            }
        }
        degrees.push_back(make_pair(degree, i));
    }

    sort(degrees.rbegin(), degrees.rend(), compareDegrees);
    reverse(degrees.begin(), degrees.end());

    vector<int> coloring(V, -1);
    int current_color = 0;

    for (const auto& degree_vertex : degrees) {
        int v = degree_vertex.second;
        set<int> used_colors;

        for (const auto& edge : edges) {
            if ((edge.src == v || edge.dest == v) && coloring[edge.src] != -1) {
                used_colors.insert(coloring[edge.src]);
            }
            else if ((edge.src == v || edge.dest == v) && coloring[edge.dest] != -1) {
                used_colors.insert(coloring[edge.dest]);
            }
        }

        int color = 0;
        while (used_colors.count(color) > 0) {
            color++;
        }

        coloring[v] = color;
        current_color = max(current_color, color);
    }

    return make_pair(coloring, current_color + 1);
}


//auto result = welsh_powell(edges, V);
//
//cout << "Step-by-step vertex coloring of a graph:" << endl;
//cout << "----------------------------------------" << endl;
//for (int i = 0; i < V; ++i) {
//    cout << "Vertex " << i + 1 << " is colored with color " << result.first[i] << endl;
//}
//cout << "----------------------------------------" << endl;
//
//cout << "Number of colors used: " << result.second << endl;