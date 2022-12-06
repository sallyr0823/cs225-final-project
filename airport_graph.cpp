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
        mp[airports_[i].AirportID()] = i;
    }
    for(unsigned j = 0; j < edges_.size();j++) {
        unsigned source = edges_[j].getSourceId();
        unsigned dest = edges_[j].getDestId();
        
        adjlist_[source].push_back(dest);
    }
    
}

Graph::Graph(const Graph& other) {
    if(this == &other) {
        return;
    }
    num_ = other.num_;
    airports_ = other.airports_;
    edges_ = other.edges_;
    for(int i = 0; i < num_; i++) {
        vector<unsigned> insert;
        adjlist_.insert({other.airports_[i].AirportID(),insert});
    }
    for(unsigned j = 0; j < edges_.size();j++) {
        unsigned source = edges_[j].getSourceId();
        unsigned dest = edges_[j].getDestId();
         adjlist_[source].push_back(dest);
    }
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

map<unsigned, unsigned> Graph::get_index_map() {
    return mp;
}

unordered_map<unsigned, vector<unsigned >>& Graph::get_adjList() {
    return adjlist_;
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
        Airport s = airports_[mp[source]];
        Airport d = airports_[mp[destination]];
        
        return Edge(s,d);
    }
    return Edge();
    
}
