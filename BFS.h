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
        BFS(Graph* graph);
        vector<unsigned> BFS_connected(Airport& source);
        vector<unsigned> BFS_path(Airport& source, Airport& destination);
        double print_distance(Airport& source, Airport& destination);
    
    private:
        Graph* graph_;
        int num_;
        vector<Airport> airports_;
        vector<Edge> edges_;
        map<unsigned, unsigned> mp;

};