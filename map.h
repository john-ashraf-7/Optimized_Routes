#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

class Map
{
    private:
    vector<vector<int>> adjMatrix;

    public:
    Map();
    Map(vector<vector<int>> adjMatrix);
    void setAdjMatrix(vector<vector<int>> adjMatrix);
    void addEdge(int u, int v, int edgeWeight);
    void removeEdge(int u, int v);

    //O(V^2)
    vector<int> ShortestPath_Dijkstra(int src, int dest);

    //O(V^3)
    vector<int> ShortestPath_BellmanFord(int src, int dest);

    //O(V^2) Heuristic
    vector<int> ShortestPath_A_Star(int src, int dest);
};  