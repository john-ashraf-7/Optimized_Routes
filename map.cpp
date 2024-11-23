#include "map.h"

Map::Map(vector<vector<int>> adjMatrix)
{
    this->adjMatrix = adjMatrix;
}

void Map::addEdge(int u, int v, int edgeWeight)
{
    adjMatrix[u][v] = edgeWeight;
    adjMatrix[v][u] = edgeWeight;
}

void Map::removeEdge(int u, int v)
{
    adjMatrix[u][v] = 0;
    adjMatrix[v][u] = 0;
}

vector<int> Map::ShortestPath_Dijkstra(int src, int dest) //minheap implementation.
{
    //dijkstra repeats a 2 step process.
    //relaxation then choosing next node.

    int n = adjMatrix.size();
    vector<bool>visited(n, false);
    vector<int>distances(n,INF);
    vector<int>path;
    priority_queue<int, vector<int>, greater<int>>minheap;
    distances[src]=0;

    for(int u=0;u<n;u++)
    {
        visited[u] = true;
        for(int v=0;v<n;v++)
        {

            //relaxation
            if(distances[v] > distances[u] + adjMatrix[u][v])
            {
                distances[v] = distances[u] + adjMatrix[u][v];
                
            }
        }
    }


}

vector<int> Map::ShortestPath_BellmanFord(int src, int dest)
{
    //adj matrix implementation.

}

vector<int> Map::ShortestPath_A_Star(int src, int dest)
{

}