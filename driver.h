#include <iostream>
using namespace std;
#include "map.h"

class driver
{
    private:
    int src, dest;

    public:
    Map personal_map;

    driver(int src, int dest, Map map);
    void fillmap(vector<vector<int>> adjMatrix);
    int getSrc();
    int getDest();
};