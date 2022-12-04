#include "airport_graph.h"
#include "airport.h"
#include "edge.h"
#include <map>
#include <queue>
#include <vector>
#include <cmath>

#pragma once

using namespace std;


class BFS {
    public:
        BFS(Graph graph);
        vector<unsigned> BFS_connected(unsigned source);
        vector<unsigned> BFS_path(unsigned source, unsigned destination);
        double print_distance(unsigned source, unsigned destination);
    
    private:
        Graph graph_;
        int num_;
        vector<Airport> airports_;
        vector<Edge> edges_;
        map<unsigned, unsigned> mp;

};