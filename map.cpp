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

//Greedy Approach
//Dijkstra is a single src to many destinations shortest path algorithm.
//However in this project we want to measure the path between a specified src and destination for different shortest path algos
vector<int> Map::ShortestPath_Dijkstra(int src, int dest) //minheap implementation.
{
    //dijkstra repeats a 2 step process.
    //relaxation then choosing next node.
    int V = adjMatrix.size();
    vector<bool>visited(V, false);
    vector<int>distances(V,INF);
    vector<int>priorV(V, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

    distances[src]=0;
    minheap.push(make_pair(0,src));

    while(!minheap.empty())
    {
        int u = minheap.top().second; //src vertex
        for(int v=0;v<adjMatrix.size();v++)
        {
            if(adjMatrix[u][v] && !visited[v]) //if edge exists
            {
                //check for possible relax
                if(distances[u] + adjMatrix[u][v] < distances[v])
                {
                    distances[v] = distances[u] + adjMatrix[u][v];
                    minheap.push(make_pair(distances[v],v));
                    priorV[v] = u;
                }
            }
        }
        visited[u] = true;
        minheap.pop();
    }

    //slice the priorV vector from 0 till dest then return it
    vector<int>path;
    int i=0;
    while()
    path.push_back(priorV[dest]);
    return path;

}

//DP Approach
vector<int> Map::ShortestPath_BellmanFord(int src, int dest)
{
    //adj matrix implementation.

}

//Heuristic Approach
vector<int> Map::ShortestPath_A_Star(int src, int dest)
{

}