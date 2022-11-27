#pragma once
#include "airport_graph.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class PageRank {
    public:
        void init_rank_matrix(Graph & graph);
        std::vector<double> prob_calculation(Graph & graph);
        std::vector<Airport> get_airport_rank(Graph & graph);
};