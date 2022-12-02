#pragma once
#include "airport_graph.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class PageRank {
    public:
        //PageRank();
        PageRank(Graph& graph);
        void init_rank(double damp, int iteration);
        vector<unsigned> get_airport_rank();
        void store_pagerank();
    private:
        vector<unsigned> rank_;
        vector<Airport> airports_;
        unordered_map<unsigned, vector<unsigned >> adjList;
        map<unsigned, unsigned> mp;
        size_t num_;
};