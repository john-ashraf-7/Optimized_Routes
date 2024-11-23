#include <vector>
#include <iostream>
using namespace std;

class Map
{
    private:
    vector<vector<int>> adjMatrix;

    public:
    Map(vector<vector<int>> adjMatrix);
    void addEdge(int u, int v, int edgeWeight);
    void removeEdge(int u, int v);
    vector<int> ShortestPath_Dijkstra(int src, int dest);
    vector<int> ShortestPath_BellmanFord(int src, int dest);
    vector<int> ShortestPath_A_Star(int src, int dest);
};  