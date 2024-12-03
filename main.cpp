#include "driver.h"
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void measureExecutionTime(Map& map, const string& algorithmName, int start, int end) {
    auto start_time = high_resolution_clock::now();
    vector<int> path;

    // Assuming the Map class has methods for different shortest path algorithms
    if (algorithmName == "Dijkstra") {
        path = map.ShortestPath_Dijkstra(start, end);
    } else if (algorithmName == "Bellman-Ford") {
        path = map.ShortestPath_BellmanFord(start, end);
    } else if (algorithmName == "A-Star") {
        path = map.ShortestPath_A_Star(start, end);
    }

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time).count();
    cout << algorithmName << " algorithm took " << duration << " microseconds." << endl;

    cout << "Path: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main()
{
    //5x5
    vector<vector<int>> adjMatrix1 =
    {
        {0, 2, 3, 0, 0},
        {2, 0, 0, 4, 0},
        {3, 0, 0, 1, 6},
        {0, 4, 1, 0, 5},
        {0, 0, 6, 5, 0}
    };

    //8x8
    vector<vector<int>> adjMatrix2 =
    {
        {0, 2, 3, 0, 0, 0, 0, 0},
        {2, 0, 0, 4, 0, 0, 0, 0},
        {3, 0, 0, 1, 6, 0, 0, 0},
        {0, 4, 1, 0, 5, 0, 0, 0},
        {0, 0, 6, 5, 0, 7, 0, 0},
        {0, 0, 0, 0, 7, 0, 8, 0},
        {0, 0, 0, 0, 0, 8, 0, 9},
        {0, 0, 0, 0, 0, 0, 9, 0}
    };

    //10x10
    vector<vector<int>> adjMatrix3 =
    {
        {0, 2, 3, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 1, 6, 0, 0, 0, 0, 0},
        {0, 4, 1, 0, 5, 0, 0, 0, 0, 0},
        {0, 0, 6, 5, 0, 7, 0, 0, 0, 0},
        {0, 0, 0, 0, 7, 0, 8, 0, 0, 0},
        {0, 0, 0, 0, 0, 8, 0, 9, 0, 0},
        {0, 0, 0, 0, 0, 0, 9, 0, 10, 0},
        {0, 0, 0, 0, 0, 0, 0, 10, 0, 11},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 0} 
    };

    Map map1(adjMatrix1), map2(adjMatrix2), map3(adjMatrix3);
    driver driver1(0, 3, map1);
    driver driver2(4, 0, map2);
    driver driver3(0, 9, map3);


    cout << "Testing on 5x5 matrix:" << endl;
    measureExecutionTime(driver1.personal_map, "Dijkstra", 0, 4);
    measureExecutionTime(driver1.personal_map, "Bellman-Ford", 0, 4);
    measureExecutionTime(driver1.personal_map, "A-Star", 0, 4);

    cout << "\nTesting on 8x8 matrix:" << endl;
    measureExecutionTime(driver2.personal_map, "Dijkstra", 0, 7);
    measureExecutionTime(driver2.personal_map, "Bellman-Ford", 0, 7);
    measureExecutionTime(driver2.personal_map, "A-Star", 0, 7);

    cout << "\nTesting on 10x10 matrix:" << endl;
    measureExecutionTime(driver3.personal_map, "Dijkstra", 0, 9);
    measureExecutionTime(driver3.personal_map, "Bellman-Ford", 0, 9);
    measureExecutionTime(driver3.personal_map, "A-Star", 0, 9);

}