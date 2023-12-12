#include <iostream>
#include <vector>
#include "amirova.h"
#include "main_oganesyan.h"
#include "grigorova.h"
#include "Ankudoviche.h"
using namespace std;

int main()
{
    GTS gts;
    vector<vector<int>> vecOfVec;
    vector<Edge2> vecOfVec2;
    vector<Edge1> vecOfVec1;


    cout << "Enter the number of vertices: ";
    int V;
    V = GetCorrectInt(1, 100);
    Graph1 minigraph(V);
    vector<vector<int>> graph2(V, vector<int>(V, 0));

    int a;
    cout << "Enter the number of edges: ";
    a = GetCorrectInt(1, 200);

    for (int i = 0; i < a; i++) {
        vector<int> tempVec;
        Edge2 e2;
        Edge1 e1;
        for (int j = 0; j < 2; j++) {
            int num;
            if (j == 0)
            {
                cout << "Enter starting vertice" << " of " << i + 1 << " edge: ";
                int vvod1;
                vvod1 = GetCorrectInt(0, V - 1);
                e2.src = vvod1;
                e1.src = vvod1;
                num = vvod1;
                tempVec.push_back(num);
            }
            if (j == 1)
            {
                cout << "Enter end vertice" << " of " << i + 1 << " edge: ";
                int vvod2;
                vvod2 = GetCorrectInt(0, V - 1);
                e2.dest = vvod2;
                e1.dest = vvod2;
                num = vvod2;
                tempVec.push_back(num);
            }
        }
        vecOfVec.push_back(tempVec);
        vecOfVec2.push_back(e2);
        vecOfVec1.push_back(e1);
        minigraph.addEdge(e2.src, e2.dest);
    }
    //{ {0, 1}, { 1, 2 }, { 2, 3 }, { 2, 4 }, { 3, 4 }, { 4, 5 }, { 3, 5 }, { 6, 7 }, { 6, 8 }, { 7, 8 }, { 4, 8 }, { 7, 5 } };

    vector<vector<int>> edges_vector = vecOfVec;
    unordered_map <int, int> colors_of_vertixes;
    cout << endl << "Jones Plassman (Amirova)" << endl;
    colors_of_vertixes = gts.Jones_Plassman(V, edges_vector);
    for (auto i : colors_of_vertixes) cout << "Vertex " << i.first << " is colored with color " << i.second << endl;

    vector <Edge2> edges = vecOfVec2;
    int numcolors = 0;
    /*vector<int> colors(V, -1);*/
    vector <int> colors;
    int vertex = 0;
    cout << "\ntkacheva" << endl;
    colors = gts.graphcoloring(edges, numcolors, V);
    cout << "Number of colors: " << numcolors << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < colors.size(); i++) {
        cout << "Vertex " << i << " -> Color: " << colors[i] << endl;
    } 
    cout << "\ngerdt" << endl;
    auto result = gts.welsh_powell(edges, V);
 
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i + 1 << " is colored with color " << result.first[i] << endl;
    }
    
    cout << "Number of colors used: " << result.second << endl;

    vector<Edge1> edges1 = vecOfVec1;
    Graph graph(edges1, V);

    cout << "grigorova" << endl;

    cout << "Step-by-step vertex coloring of a graph:" << endl
        << "***********************************" << endl;
    gts.colorGraph(graph, V);
    cout << "***********************************" << endl;

    cout << "ankudovich" << endl;
    cout << "Coloring of graph:" << endl;

    minigraph.greedyColoring();

    return 0;
}