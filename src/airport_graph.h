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
        const Graph& operator=(const Graph& other);
        int get_num_airports();
        vector<Airport> & get_airports();
        vector<Edge> & get_routes();
        map<unsigned, unsigned> get_index_map();
        unordered_map<unsigned, vector<unsigned >>& get_adjList();
        vector<unsigned> get_adj_airport(unsigned airportId);
        double calculateWeight(unsigned source, unsigned destination);
        bool exist_airport(unsigned airportId);

    private:
        size_t num_;
        vector<Airport> airports_;
        vector<Edge> edges_;
        unordered_map<unsigned, vector<unsigned >> adjlist_;
        map<unsigned, unsigned> mp;
};