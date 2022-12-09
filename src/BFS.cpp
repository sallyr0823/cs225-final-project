#include "BFS.h"
#include "airport.h"
#include "edge.h"
#include <map>

using namespace std;

BFS::BFS(Graph graph) {
    graph_ = graph;
    num_ = graph. get_num_airports();
    airports_ = graph.get_airports();
    edges_ = graph.get_routes();
    for (unsigned i = 0; i < airports_.size(); i++) {
        mp[airports_[i].AirportID()] = i; 
    }
}

vector<unsigned> BFS::BFS_connected(unsigned source) {
    vector<unsigned> trav;
    vector<bool> visited_(num_,false);
    unsigned sour = source;
    queue<unsigned> q;
    q.push(mp[sour]);
    unsigned curr = mp[sour];
    visited_[mp[sour]] = true;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for(unsigned& adj:graph_.get_adj_airport(airports_[curr].AirportID())) {
            if(!visited_[mp[adj]]) {
                q.push(mp[adj]);
                trav.push_back(mp[adj]);
                visited_[mp[adj]] = true;
            }
        }
    }
    return trav;
}
double BFS::print_distance(unsigned source, unsigned destination) {
    vector<unsigned> path = BFS_path(source,destination);
    if(path.size() == 0) {
        return 0.0;
    }
    double dist = 0;
    for(unsigned i = 0; i < path.size() - 1; i++) {
        Edge e = Edge(airports_[path[i]],airports_[path[i+1]]);
        dist += e.getWeight();
    }
    return dist;
}





vector<unsigned> BFS::BFS_path(unsigned source, unsigned destination) {
    if(!graph_.exist_airport(source) || !graph_.exist_airport(destination)) {
        return vector<unsigned>();
    }
    if(find(graph_.get_adj_airport(source).begin(),graph_.get_adj_airport(source).end(),destination) == graph_.get_adj_airport(source).end()) {
        return vector<unsigned>();
    }
    unsigned sour = source;
    unsigned dest = destination;
    vector<unsigned> path;

    vector<unsigned> prev_(num_,-1);
    vector<bool> visited_(num_,false);

    queue<unsigned> q;
    q.push(mp[sour]);
    unsigned curr = mp[sour];
    prev_[mp[sour]]= mp[sour];
    while(!q.empty()) {
        curr = q.front();
        for(unsigned& adj: graph_.get_adj_airport(airports_[curr].AirportID())) {
            if(!visited_[mp[adj]]) {
                q.push(mp[adj]);
                prev_[mp[adj]] = curr;
                visited_[mp[adj]] = true;
            }
        }
        if(curr == mp[dest]) {
            break;
        }
        q.pop();
    }
    if(curr != mp[dest]) {
        return path;
    }
    while(curr != mp[sour]) {
        path.push_back(curr);
        curr = prev_[curr];
    }
    path.push_back(mp[sour]);
    
    reverse(path.begin(),path.end());
    return path;
    
}

