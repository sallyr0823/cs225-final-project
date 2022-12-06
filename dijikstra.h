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
    Dijisktra(Graph* graph);
    vector<unsigned> shortest_path(unsigned source, unsigned destination);
    double print_distance(unsigned source, unsigned destination);
    unsigned shortest_distance(vector<unsigned> que, vector<unsigned> distances, vector<bool> visited);
    private:
    vector<Airport> airports_;
    vector<Edge> edges_;
    Graph* graph;
    map<unsigned, unsigned> mp;
};