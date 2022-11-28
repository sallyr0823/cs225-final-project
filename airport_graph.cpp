//Graphs Class

#include "airport_graph.h"
#include "edge.h"
#include <math.h> 
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <stack>


using namespace std;


//default constructor
Graph::Graph(){

}

Graph::Graph(vector<Airport> & airports, vector<Edge> & edges) {
    airports_ = airports;
    edges_ = edges;
    num_ = airports.size();
    
    for(int i = 0; i < num_;i++) {
        vector<unsigned> insert;
        adjlist_.insert({airports_[i].AirportID(),insert});
    }
    for(unsigned j = 0; j < edges_.size();j++) {
        unsigned source = edges_[j].getSourceId();
        unsigned dest = edges_[j].getDestId();
        
        adjlist_[source].push_back(dest);
    }

    // Initialize the rank matrix as all the entries equal to 0

    for (int i = 0; i < num_; i++) {
        vector<double> insert(num_,0);
        rank_matrix.push_back(insert);
    }
    
    // Change the rank matrix value to 1 if two airports at the given index has route between them
    for (size_t t = 0; t < edges_.size(); t++) {
        auto origin = find(airports_.begin(), airports_.end(), edges_[t].getSource());
        auto dest = find(airports_.begin(), airports_.end(), edges_[t].getDest());
        if (origin != airports_.end() && dest != airports_.end()) {
            int origin_index = distance(airports_.begin(), origin);
            int dest_index = distance(airports_.begin(), dest);
            rank_matrix[origin_index][dest_index] = 1;
        }
    }
}

Graph::Graph(const Graph& other) {
    if(this == &other) {
        return;
    }
    num_ = other.num_;
    airports_ = other.airports_;
    edges_ = other.edges_;
    adjlist_ = other.adjlist_;
    rank_matrix = other.rank_matrix;
}


int Graph::get_num_airports() {
    return num_;
}

vector<Airport> & Graph::get_airports() {
    return airports_;
}

vector<Edge> & Graph::get_routes() {
    return edges_;
}

vector<unsigned> Graph::get_adj_airport(unsigned airportId) {
   
    if(exist_airport(airportId)) {
        // check if contains airport
        return adjlist_[airportId];
     }
     return vector<unsigned>();
}


bool Graph::exist_airport(unsigned airportId) {
    for (int i = 0; i < num_; i++) {
        if (airportId == airports_[i].AirportID()) {
            return true;
        }
    }
    return false;
}

Edge Graph::getEdge(unsigned source, unsigned destination) {
    if(!exist_airport(source) || !exist_airport(destination)) {
        return Edge();
    }
    vector<unsigned> adj = get_adj_airport(source);
    if(find(adj.begin(),adj.end(),destination) != adj.end()) { 
        Airport s;
        Airport d;
        for(int i = 0; i < num_; i++) {
            if(source == airports_[i].AirportID()) {
                s = airports_[i];
            }
            if(destination == airports_[i].AirportID()) {
                d = airports_[i];
            }
            if(s.AirportID() != 0 && d.AirportID() != 0) {
                break;
            }
        }
        return Edge(s,d);
    }
    return Edge();
    
}

vector<vector<double >> Graph::get_rank_matrix() const {
    return rank_matrix;
}