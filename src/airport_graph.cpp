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
#include <algorithm>
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
    
    for(size_t i = 0; i < num_;i++) {
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
    for(size_t i = 0; i < num_; i++) {
        vector<unsigned> insert;
        adjlist_.insert({other.airports_[i].AirportID(),insert});
    }
    for(unsigned j = 0; j < edges_.size();j++) {
        unsigned source = edges_[j].getSourceId();
        unsigned dest = edges_[j].getDestId();
         adjlist_[source].push_back(dest);
    }
}
const Graph& Graph::operator=(const Graph& other) {
    if(this == &other) {
        return *this;
    }
    num_ = other.num_;
    airports_ = other.airports_;
    edges_ = other.edges_;
    for(size_t i = 0; i < num_; i++) {
        vector<unsigned> insert;
        adjlist_.insert({other.airports_[i].AirportID(),insert});
    }
    for(unsigned j = 0; j < edges_.size();j++) {
        unsigned source = edges_[j].getSourceId();
        unsigned dest = edges_[j].getDestId();
         adjlist_[source].push_back(dest);
    }
    return *this;

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
    for (size_t i = 0; i < num_; i++) {
        if (airportId == airports_[i].AirportID()) {
            return true;
        }
    }
    return false;
}



double Graph::calculateWeight(unsigned source, unsigned destination) {
    // consider source to be class object
    Airport sour;
    Airport dest;
    for (size_t i = 0; i < num_; i++) {
        if (source == airports_[i].AirportID()) {
            sour = airports_[i];
        }
        if (destination == airports_[i].AirportID()) {
            dest = airports_[i];
        }
    }
    if(sour.AirportID() == 0 || dest.AirportID() == 0) {
        return 0.0;
    }
    
    std::pair<double,double> loc1 = sour.AirportLocation();
    std::pair<double,double> loc2 = dest.AirportLocation();
    //https://www.movable-type.co.uk/scripts/latlong.html
    const double R = 6371;
    double phi1 = loc1.first * M_PI / 180;
    double phi2 = loc2.first * M_PI /180;
    double delta_phi = (loc2.first-loc1.first) * M_PI / 180;
    double delta_lam = (loc2.second - loc1.second) * M_PI / 180;
    double a =  sin(delta_phi / 2) * sin(delta_phi / 2) + cos(phi1)*cos(phi2)*sin(delta_lam/2)*sin(delta_lam/2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    double d = R*c;
    return d;
}
