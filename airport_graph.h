#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include "airport.h"
#include "file_reader.h"
#include "edge.h"

using namespace std;

class Graph {
    public:
        Graph();
        Graph(vector<Airport> & airports, vector<Edge> & edges);
        Graph(const Graph& other);
        int get_num_airports();
        vector<Airport> & get_airports();
        vector<Edge> & get_routes();
        unordered_map<unsigned, vector<unsigned >>& get_adjList();
        vector<unsigned> get_adj_airport(unsigned airportId);
        Edge getEdge(unsigned source, unsigned destination);
        bool exist_airport(unsigned airportId);

    private:
        int num_;
        vector<Airport> airports_;
        vector<Edge> edges_;
        unordered_map<unsigned, vector<unsigned >> adjlist_;
};