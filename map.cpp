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

