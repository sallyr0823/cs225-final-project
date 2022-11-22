#include "airport_graph.h"
#include "airport.h"
#include "edge.h"
#include <map>
#include <queue>
#include <vector>
#include <cmath>

#pragma once

using namespace std;

class Dijisktra {

    public:
    Dijisktra(Graph graph, Airport source);
    vector<Airport> shortest_path(Airport source, Airport destination);
    unsigned shortest_distance(vector<unsigned> que);
    private:
    vector<Airport> airports_;
    vector<Edge> edges_;
    
};