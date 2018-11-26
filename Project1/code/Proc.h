#pragma once
#include "JobStream.h"
#include "queue.h"
#include <iostream>
#include <vector>
using namespace::std;
class proc
{
    double procRate;
    int numCores;
    int ticks;
    int tasksDone = 0;
    int tasksLost = 0;
    queue<int> *list;
    vector<JobStream> runTasks;
public:
    proc(double rate, double tasksIntense, int cores, int ticksToBeDone, int size) :
        procRate(rate),numCores(cores), ticks(ticksToBeDone)
    {
        srand(time(NULL));
        list = new queue<int>(size);
        for (int i = 0; i < numCores; i++)
            runTasks.push_back(JobStream(tasksIntense));
    }
    void start()
    {
        int _ticks = ticks;
        while (_ticks)
        {
            if ((rand() / MAX_RANDOM) < procRate)
                if (!list->isFull())
                    list->push_back(0);
                else
                    tasksLost++;
            for (auto& c : runTasks)
                if (c.getState())
                    if (!list->isEmpty())
                    {
                        c.setState();
                        list->pop();
                    }
                    else;
                else
                    if (c.tryToComplete())
                        tasksDone++;
            _ticks--;
        }
    }
    void print()
    {
        int totalTasks = tasksDone + tasksLost;
        double percentage = double(tasksDone) / totalTasks * 100;
        cout << "---STATISTIC---" << endl;
        cout << "CPU rate: " << procRate << endl;
        cout << "Size of the queue: " << list->getSize() << endl;
        cout << "Cores: " << numCores << endl;
        cout << "Ticks: " << ticks << endl;
        cout << "Tasks finished: " << tasksDone << endl;
        cout << "Tasks declined: " << tasksLost << endl;
        cout << "Tasks in total: " << totalTasks << endl;
        cout << "Percentage of finished tasks: " << percentage << endl;
     }
    ~proc()
    {
        delete list;
    }
};
