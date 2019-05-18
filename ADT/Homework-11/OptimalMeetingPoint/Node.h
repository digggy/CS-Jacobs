
#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <cstdlib>
using namespace std;

#define INF INT8_MAX

class Node
{
public:
    double distance_a, distance_b, distance_c;
    bool status;
    int idx;
    Node()
    {
        // Initially the Node has all the distance properties to infinite and the status to 0
        this->distance_a = INF;
        this->distance_b = INF;
        this->distance_c = INF;
        this->status = false;
        this->idx = 0;
    }

    // Here we set the index (idx) for the Node
    void idxSet(int in)
    {
        idx = in;
    }

    // Comparision method for the comparision of Nodes in priority queue
    friend bool operator<(const Node &srcA, const Node &srcB)
    {
        if (srcA.status)
        {
            return (srcA.distance_b < srcB.distance_b);
        }
        else
        {
            return (srcA.distance_a < srcB.distance_a);
        }
    }
    //Change the statusof the node
    void changeSet()
    {
        this->status = true;
    }
    // Set the distance_c according to the value of the param in
    void set(double in)
    {
        if (status)
        {
            this->distance_b = in;
            if (this->distance_b > this->distance_a)
            {
                this->distance_c = this->distance_b;
            }
            else
            {
                this->distance_c = this->distance_a;
            }
        }
        else
        {
            this->distance_a = in;
        }
    }
};
