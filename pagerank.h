#pragma once
#include "airport_graph.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class PageRank {
    public:
        void init_rank_matrix(Graph & graph);
        std::vector<unsigned> prob_calculation(Graph & graph,unsigned damp);
        std::vector<Airport> get_airport_rank(Graph & graph);
        void store_pagerank(Graph & graph);
    private:
        vector<vector<unsigned >> rank_;
        vector<Airport> airports_;
        vector<Edge> edges_;
        Graph graph_;
        map<unsigned, unsigned> mp;
};