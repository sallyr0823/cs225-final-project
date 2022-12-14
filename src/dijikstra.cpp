#include "dijikstra.h"
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
Dijisktra::Dijisktra(Graph& graph_) {
    airports_ = graph_.get_airports();
    edges_ = graph_.get_routes();
    for (unsigned i = 0; i < airports_.size(); i++) {
        mp[airports_[i].AirportID()] = i; 
    }
    graph = graph_;
    
}
bool Dijisktra::exist_route(vector<Edge> edges_, unsigned dest) {
    for (unsigned i = 0; i < edges_.size(); i++) {
        if (dest == edges_[i].getDestId()) {
            return true;
        }
    }
    return false;
}
double Dijisktra::print_distance(unsigned source, unsigned destination) {
    vector<unsigned> path = shortest_path(source,destination);
    if(path.size() == 0) {
        return 0.0;
    }
    double dist = 0.0;
    for(unsigned i = 0; i < path.size() - 1; i++) {
        Edge e = Edge(airports_[path[i]],airports_[path[i+1]]);
        dist += e.getWeight();
    }
    return dist;
}
vector<unsigned> Dijisktra::shortest_path(unsigned source, unsigned destination) {
    if(!graph.exist_airport(source) || !graph.exist_airport(destination)) {
        return vector<unsigned>();
    }
    
    
    if (!exist_route(edges_, destination)) {
        return vector<unsigned>();
    }
    
    unsigned start = source ;
    unsigned dest = destination;
    
    
    //144110 is the id of the last airport
    vector<unsigned> distances; 
    vector<unsigned> previous; 
    vector<unsigned> que;   
    //que.push_back(start);   
    
    vector<bool> visited;
    for (unsigned i = 0; i < airports_.size(); i++) {
        visited.push_back(false); 
        distances.push_back(9999999); 
        previous.push_back(-1);  
        que.push_back(i);
    }
    //initialization
    distances[mp[start]] = 0; 
    previous[mp[start]] = mp[start];
    unsigned visitedCount = 0;
    
    unsigned curr = mp[start]; //index of current airport
    unsigned currAirportID = start; // id of current airport
    while (visitedCount < airports_.size()) {
        
        curr = shortest_distance(que, distances, visited);
        currAirportID = airports_[curr].AirportID();
        visited[curr] = true;
        visitedCount++;
        if (curr == mp[dest]) {
            break;
        }
        for (unsigned& adj : graph.get_adj_airport(currAirportID)) {
            if(!visited[mp[adj]]) {
                unsigned adj_dist = distances[curr] + graph.calculateWeight(currAirportID, adj);
                 //  distance of node of current iteration from the start
                if (adj_dist < distances[mp[adj]]) {  
                    distances[mp[adj]] = adj_dist; 
                    previous[mp[adj]] = curr; //index
                }

            }
        }
    }
    vector<unsigned> path;
    if(curr != mp[dest]) {
        return path;
    }
    while (curr != mp[start]) {
        path.push_back(curr); 
        curr = previous[curr]; 
    }
    path.push_back(curr);
    
    reverse(path.begin(), path.end()); //reverse the path 
    return path;
}
unsigned Dijisktra::shortest_distance(vector<unsigned> que, vector<unsigned> distances, vector<bool> visited) {
    unsigned shortest_dist = distances[que[0]]; 
    unsigned min_index = 0;
    for(unsigned i = 0; i < que.size(); i++) {
        if (!visited[i]) {
            shortest_dist = distances[que[i]];
            min_index = i;
            break;
        }
    }
    
    for (unsigned i = 0; i < que.size(); i++) { 
    
        if (!visited[i] && distances[que[i]] < shortest_dist) { 
            
            shortest_dist = distances[que[i]]; 
            min_index = i; 
        }
    }
    return min_index;
}