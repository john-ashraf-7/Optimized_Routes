#include "driver.h"

driver::driver(int src, int dest, Map map)
{
    this->src = src;
    this->dest = dest;
    this->personal_map = map;
}

void driver::fillmap(vector<vector<int>> adjMatrix)
{
    personal_map.setAdjMatrix(adjMatrix);
}

int driver::getSrc()
{
    return src;
}

int driver::getDest()
{
    return dest;
}