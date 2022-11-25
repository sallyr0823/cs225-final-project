#include "dijikstra.h"
#include <map>
#include <iostream>
#include <algorithm>


using namespace std;

Dijisktra::Dijisktra(Graph* graph) {
    airports_ = graph -> get_airports();
    edges_ = graph -> get_routes();
    for (unsigned i = 0; i < airports_.size(); i++) {
        mp[airports_[i].AirportID()] = i; 
    }
    this->graph = graph;
    
}
vector<unsigned> Dijisktra::shortest_path(Airport source, Airport destination) {
    unsigned start = source.AirportID();
    unsigned dest = destination.AirportID();
    cout << start << endl;
    
    
    //144110 is the id of the last airport
    vector<unsigned> distances; 
    vector<unsigned> previous; 
    vector<unsigned> que;   
    //que.push_back(start);   

    
    vector<bool> visited;
    for (unsigned i = 0; i < airports_.size(); i++) {
        visited.push_back(false); 
        distances.push_back(999999); 
        previous.push_back(0);  
        que.push_back(i);
    }

    //initialization
    distances[mp[start]] = 0; 
    previous[mp[start]] = mp[start];

    unsigned visitedCount = 0;
    
    unsigned curr; //ID of current airport
    while (visitedCount < airports_.size()) {
        
        //find shortestdistance
        curr = shortest_distance(que, distances, visited);
        //cout << "???" << curr <<endl;

        unsigned currAirportID = airports_[curr].AirportID();
        visited[curr] = true;
        visitedCount++;
         //remove the current airport from the queue
        //cout << airports_[curr].AirportName() << endl;
        if (curr == dest) {
            break;
        }
        //adj_airport
        //cout << graph->get_adj_airport(currAirportID).size() << " ";
        for (unsigned& adj : graph->get_adj_airport(currAirportID)) {
            //cout << currAirportID;  
            if(currAirportID == 3364) {
                //scout<< adj << "???";
            }         
            if(!visited[mp[adj]]) {
                //if(adj == 3393) cout << "#####" << distances[curr];
                unsigned adj_dist = distances[curr] + graph -> getEdge(currAirportID, adj).getWeight(); //  distance of node of current iteration from the start
                if (adj_dist < distances[mp[adj]]) {
                    //if(adj == 3393) cout << "####";
                    distances[mp[adj]] = adj_dist; 
                    previous[mp[adj]] = curr; 
                }
            }
        }
    }

    // //back track to find path
    vector<unsigned> path;
    curr = mp[dest];
    //cout << previous[curr];
    if (previous[curr] != 0) { 
        while (curr != mp[start]) {
            path.push_back(curr); 
            curr = previous[curr]; 
        }
        path.push_back(curr); 
    
    }
    cout << path.size() << endl;
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

