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


using namespace std;


//default constructor
Graph::Graph(){

}

Graph::Graph(vector<Airport> & airports, vector<Edge> & edges) {
    airports_ = airports;
    edges_ = edges;
    num_ = airports.size();
    visited_ = vector<bool>(num_, false);
    
    for(int i = 0; i < num_;i++) {
        vector<unsigned> insert;
        adjlist_.insert({airports_[i].AirportID(),insert});
    }
    for(int j = 0; j < edges_.size();j++) {
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
    adjlist_ = other.adjlist_;
    visited_ = visited_;
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
    for (size_t i = 0; i < num_; i++) {
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
//BFS traversal
vector<unsigned> Graph::traversal(Airport & source, Airport & destination) {
    unsigned dest = destination.AirportID();
    queue<unsigned> q;
    vector<unsigned> trav;
    q.push(source.AirportID());
    while(!q.empty() && q.front() != dest) {
        unsigned curr = q.front();
        visited_[curr] = true;
        q.pop();
        trav.push_back(curr);
        for(unsigned& adj: get_adj_airport(curr)) {
            if(!visited_[adj]) {
                q.push(adj);
                trav.push_back(adj);
                visited_[adj] = true;
            }
        }
    }

}