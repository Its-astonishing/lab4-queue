#pragma once
#include <time.h>
#include <cstdlib>
const double MAX_RANDOM = 1000.0;
class JobStream
{
    double intense;
    bool state = true; 
public:
    JobStream(double _intense) :
        intense(_intense) { }
    void setState()
    {
        state = false;
    }
    bool tryToComplete()
    {
        return state = (rand() / MAX_RANDOM) < intense;
    }
    bool getState()
    {
        return state;
    }
};