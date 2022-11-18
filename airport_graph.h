#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "Airport.h"
#include "file_reader.h"
#include "edge.h"

using namespace std;

class Graph {
    public:
        Graph();
        Graph(vector<Airport> & airports, vector<Edge> & edges);
        Graph(const Graph& other);
        ~Graph();
        bool** get_adj_matrix() const;
        int get_num_airports();
        vector<Airport> & get_airports();
        vector<Edge> & get_routes();
        vector<Airport> get_adj_airport(Airport airport);
        bool exist_airport(Airport airport);
        void print_adj_matrix();

    private:
    int num_;
    vector<Airport> airports_;
    vector<Edge> edges_;
    bool** adjmatrix_;
  
};