#include "map.h"

Map::Map()
{
}

Map::Map(vector<vector<int>> adjMatrix)
{
    this->adjMatrix = adjMatrix;
}

void Map::setAdjMatrix(vector<vector<int>> adjMatrix)
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
    while(dest != -1)
    {
        path.push_back(dest);
        dest = priorV[dest];
    }
    reverse(path.begin(), path.end());
    return path;

}

//DP Approach
vector<int> Map::ShortestPath_BellmanFord(int src, int dest)
{
    //adj matrix implementation.
    int V = adjMatrix.size();
    vector<int>distances(V,INF);
    vector<int>priorV(V, -1);
    distances[src] = 0;

    for(int i=0;i<V-1;i++)
    {
        for(int u=0;u<V;u++)
        {
            for(int v=0;v<V;v++)
            {
                if(adjMatrix[u][v] && distances[u] + adjMatrix[u][v] < distances[v])
                {
                    distances[v] = distances[u] + adjMatrix[u][v];
                    priorV[v] = u;
                }
            }
        }
    }

    //one more iteration to detect negative cycles. (functionality disabled to prevent excessive complexity)
    bool foundnegcycle=false;
    for(int u=0;u<V;u++)
        {
            for(int v=0;v<V;v++)
            {
                if(adjMatrix[u][v] + distances[u] < distances[v])
                {
                    cout << "NEGATIVE CYCLE\n";
                    foundnegcycle=true;
                    break;
                }
            }
            if(foundnegcycle)
            break;
        }
    
    //slice the priorV vector from 0 till dest then return it
    vector<int>path;
    int i=0;
    while(dest != -1)
    {
        path.push_back(dest);
        dest = priorV[dest];
    }
    reverse(path.begin(), path.end());
    return path;
}

//Heuristic Approach
vector<int> Map::ShortestPath_A_Star(int src, int dest)
{
    //A star shortest path
    //f(n) = g(n) + h(n)
    //g(n) = cost from src to n
    //h(n) = heuristic cost from n to dest
    //f(n) = total cost from src to dest through n
    int V = adjMatrix.size();
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
            if(adjMatrix[u][v]) //if edge exists
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
        minheap.pop();
    }

    //slice the priorV vector from 0 till dest then return it
    vector<int>path;
    int i=0;
    while(dest != -1)
    {
        path.push_back(dest);
        dest = priorV[dest];
    }
    reverse(path.begin(), path.end());
    return path;
}