#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;

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