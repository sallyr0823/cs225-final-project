#include "BFS.h"
#include "airport.h"
#include "edge.h"
#include <map>

using namespace std;

BFS::BFS(Graph* graph) {
    graph_ = graph;
    num_ = graph -> get_num_airports();
    airports_ = graph -> get_airports();
    edges_ = graph -> get_routes();
    for (unsigned i = 0; i < airports_.size(); i++) {
        mp[airports_[i].AirportID()] = i; 
    }
}

vector<unsigned> BFS::BFS_connected(Airport& source) {
    vector<unsigned> trav;
    vector<bool> visited_(num_,false);
    unsigned sour = source.AirportID();
    queue<unsigned> q;
    q.push(mp[sour]);
    unsigned curr = mp[sour];
    visited_[mp[sour]] = true;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for(unsigned& adj: graph_ -> get_adj_airport(airports_[curr].AirportID())) {
            if(!visited_[mp[adj]]) {
                q.push(mp[adj]);
                trav.push_back(mp[adj]);
                visited_[mp[adj]] = true;
            }
        }
    }
    return trav;
}
double BFS::print_distance(Airport& source, Airport& destination) {
    vector<unsigned> path = BFS_path(source,destination);
    if(path.size() == 0) {
        cout << "There are no routes between two airport" << endl;
        return NULL;
    }
    double dist = 0;
    for(int i = 0; i < path.size() - 1; i++) {
        Edge e = Edge(airports_[path[i]],airports_[path[i+1]]);
        dist += e.getWeight();
    }
    return dist;
}





vector<unsigned> BFS::BFS_path(Airport& source, Airport& destination) {
    unsigned sour = source.AirportID();
    unsigned dest = destination.AirportID();
    vector<unsigned> path;

    vector<unsigned> prev_(num_,-1);
    vector<bool> visited_(num_,false);

    queue<unsigned> q;
    q.push(mp[sour]);
    unsigned curr = mp[sour];
    prev_[mp[sour]]= mp[sour];
    while(!q.empty()) {
        curr = q.front();
        for(unsigned& adj: graph_ -> get_adj_airport(airports_[curr].AirportID())) {
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

