#include "driver.h"

driver::driver(int src, int dest)
{
    this->src = src;
    this->dest = dest;
}

int driver::getSrc()
{
    return src;
}

int driver::getDest()
{
    return dest;
}