#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include "Amirova.h"
#include "main_oganesyan.h"

using namespace std;
using namespace std::chrono;


Vertex& find_vertex(vector<Vertex>& vertexes, int id) {
    for (auto& i : vertexes) if (i.id == id) return i;
}


vector<Vertex> get_adjacent(Vertex& vertex, vector<Edge3> edges, vector<Vertex>& vertexes) {
    vector<Vertex> adjacent;
    for (auto& i : edges) if (i.start == vertex.id) adjacent.push_back(find_vertex(vertexes, i.stop));
    for (auto& i : edges) if (i.stop == vertex.id) adjacent.push_back(find_vertex(vertexes, i.start));
    return adjacent;
}


Vertex& max_priority_vertex(vector<Vertex>& vertexes) {
    int mx_priority = 0;
    for (auto& i : vertexes) if (i.colored == false) (mx_priority = max(mx_priority, i.priority));
    for (auto& i : vertexes) if (i.priority == mx_priority && i.colored == false) return i;
}


void pop_from_vector(vector<Vertex>& vertexes, Vertex& vertex) {
    for (int i = 0; i < vertexes.size(); i++) if (vertexes[i].id == vertex.id) {
        vertexes.erase(vertexes.begin() + i);
    }
}

unordered_map <int, int> GTS::Jones_Plassman(int vertex_number, vector<vector<int>> edges_vector) {

    //auto start = system_clock::now();
    int color = 1;

    unordered_map <int, int> colors_of_vertexes;
    vector<Edge3> edges;
    vector<Vertex> vertexes;
    vector<Vertex> uncolored_vertexes;

    //add vertexes
    for (int i = 0; i < vertex_number; i++) {
        Vertex new_vertex;
        new_vertex.id = i;
        vertexes.push_back(new_vertex);
    }

    //create vector of edges
    for (auto i : edges_vector) {
        Edge3 new_edge;
        new_edge.start = i[0];
        new_edge.stop = i[1];
        edges.push_back(new_edge);
    }

    //priority
    for (auto& i : edges) {
        for (auto& j : vertexes) if (i.start == j.id || i.stop == j.id) j.priority++;
    }

    for (auto& i : vertexes) {
        uncolored_vertexes.push_back(i);
    }

    while (uncolored_vertexes.size() > 0) {
        vector<Vertex> unvisited;
        for (auto& i : uncolored_vertexes) unvisited.push_back(i);
        while (unvisited.size() > 0) {
            Vertex vertex_to_color = max_priority_vertex(unvisited);
            vertex_to_color.colored = true;
            vertex_to_color.color = color;
            find_vertex(vertexes, vertex_to_color.id).colored = true;
            find_vertex(vertexes, vertex_to_color.id).color = color;
            pop_from_vector(uncolored_vertexes, vertex_to_color);
            vector<Vertex> adj = get_adjacent(vertex_to_color, edges, vertexes);
            for (auto i : adj) pop_from_vector(unvisited, i);
            pop_from_vector(unvisited, vertex_to_color);
        }
        color++;
    }

    //auto finish = system_clock::now();
    /*for (auto& i : vertexes) cout << "Vertex " << i.id << " is colored with color " << i.color << endl;*/
    /*cout << "number of colors: " << color - 1;*/
    //cout << "\nExecution duration: " << (finish - start).count() << "seconds." << endl;

    for (auto& i : vertexes) colors_of_vertexes.insert({ i.id, i.color });
    return colors_of_vertexes;
}