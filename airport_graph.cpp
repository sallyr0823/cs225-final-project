//Graphs Class

#include "airport_graph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;


//default constructor
Graph::Graph(){

}

Graph::Graph(vector<Airport> & airports, vector<Edge> & edges) {
    airports_ = airports;
    edges_ = edges;
    num_ = airports.size();
    for(int i = 0; i < num_ ; i++) {
        adjmatrix_[i] = new bool[num_];
        for(int j = 0; j < num_;j++) {
            adjmatrix_[i][j] = false;
        }
    }

    for(int j = 0; j < edges_.size(); j++) {
        string source = edges[j].getSourceId();
        string des = edges[j].getDestId();
        // airport class use unsigned
        // edge class use string 
        int s_index = num_;
        int d_index = num_;
        for(int k = 0; k < num_; k++) {
            if(airports[k].AirportID() == source) {
                s_index = k;
            }
            if(airports[k].AirportID() == des) {
                d_index = k;
            }
        }
        if(s_index != num_ && d_index != num_) {
            adjmatrix_[s_index][d_index] = true;
            adjmatrix_[d_index][s_index] = true;
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
    adjmatrix_ = new bool*[num_];

    for (int i = 0; i < num_; i++) {
        adjmatrix_[i] = new bool[num_];
        for (int j = 0; j < num_; j++) {
            adjmatrix_[i][j] = other.adjmatrix_[i][j];
        }
    }
}

Graph::~Graph() {
    for(int i = 0; i < num_; i++) {
        delete adjmatrix_[];
    }
    delete adjmatrix_[];
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




vector<Airport> Graph::get_adj_airport(Airport airport) {
    vector<Airport> adj;
   
    if(exist_airport(airport)) {
        // check if contains airport
        auto index = find(airports_.begin(),airports_.end(),airport);
            for(int i = 0; i < num_; i++) {
                 if (adjmatrix_[index][i]) {
                adj.push_back(airports_[i]);
            }
        }
     }
}


bool Graph::exist_airport(Airport airport) {
    for (size_t i = 0; i < airports_.size(); i++) {
        if (airport == airports_[i]) {
            return true;
        }
    }
    return false;
}

Edge Graph::getEdge(Airport source, Airport destination) {
    if(!exist_airport(source) || !exist_airport(destination)) {
        return Edge();
    }
    vector<Airport> adj = get_adj_airport(source);
    if(find(adj.begin(),adj.end(),destination) != adj.end()) {
        return(Edge(source.AirportID(),destination.AirportID(),calculateWeight(source, destination));
    }
    return Edge();
    
}