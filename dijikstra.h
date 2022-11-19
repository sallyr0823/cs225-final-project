#include "airport_graph.h"
#include "airport.h"
#include "edge.h"
#include <map>
#include <queue>
#include <vector>

#pragma once

using namespace std;

class Dijisktra {

    public:
    vector<Airport> shortest_path(Airport destination);
    double shortest_distance(Airport destination);
    private:
    vector<Airport> airports_;
    vector<Edge> edges_;
    
};