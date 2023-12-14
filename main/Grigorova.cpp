#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include "grigorova.h"
#include "main_oganesyan.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

string color[] =
{
    "", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
    "BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"
};

unordered_map <int, int> GTS::colorGraph(Graph const& graph, int n)
{
    //auto start = system_clock::now();
    unordered_map<int, int> result1;

    int numberColor = 0;

    for (int u = 0; u < n; u++)
    {
        set<int> assigned;

        for (int i : graph.adjList[u])
        {
            if (result1[i]) {
                assigned.insert(result1[i]);
            }
        }

        int color = 1;
        for (auto& c : assigned)
        {
            if (color != c) {
                break;
            }
            color++;
        }

        result1[u] = color;
        numberColor = max(numberColor, color);
    }
    //auto finish = system_clock::now();

    return result1;

    //cout << "\nExecution duration: " << (finish - start).count() << "seconds." << endl;
}
