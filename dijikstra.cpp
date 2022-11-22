#include "dijikstra.h"
#include <map>
#include <iostream>


using namespace std;

Dijisktra::Dijisktra(Graph graph, Airport source) {
    airports_ = graph.get_airports();
    edges_ = graph.get_routes();
}
vector<unsigned> Dijisktra::shortest_path(Airport source, Airport destination) {
    unsigned start = source.AirportID();
    unsigned dest = destination.AirportID();
    
    //144110 is the id of the last airport
    vector<unsigned> distances(14110); 
    vector<unsigned> previous(14110); 
    vector<unsigned> que;    
    que.push_back(start);   

    vector<bool> visited(14110);
    for (unsigned i = 0; i < 14110; i++) {
        visited[i] = false; 
        distances[i] = numeric_limits<unsigned>::infinity(); 
        previous[i] = -1;  
    }

    //initialization
    visited[start] = true; 
    distances[start] = 0; 
    previous[start] = start; 
    
    unsigned curr; //ID of current airport
    while (!que.empty()) {
        //find shortestdistance
        curr = shortest_distance(que);
        que.erase(remove(que.begin(),que.end(),curr), que.end()); //remove the current airport from the queue
        if (curr == dest) {
            break;
        }
        //adj_airport
        for (unsigned& adj : get_adj_airport(curr)) { 
            if (visited[adj] == false) {  // if next airport has not been visited, then added to the queue and mark visited
                que.push_back(adj);   
                visited[adj] = true;   
            }

            if (visited[adj] == false || find(que.begin(), que.end(), adj) != que.end()) {
                unsigned adj_dist = distances[curr] + getEdge(curr, adj).calculateWeight(); //  distance of node of current iteration from the start
                if (adj_dist < distances[adj]) {
                    distances[adj] = adj_dist; 
                    previous[adj] = curr; 
                }
            }
        }
    }

    //back track to find path
    vector<unsigned> path; 
    curr = dest; 
    if (previous[curr] != -1) { 
        while (curr != start) {
            path.push_back(curr); 
            curr = previous[curr]; 
        }
        path.push_back(curr); 
    }
    reverse(path.begin(), path.end()); //reverse the path 
    return path;
}
unsigned Dijisktra::shortest_distance(vector<unsigned> que) {
    unsigned shortest_dist = numeric_limits<unsigned>::infinity(); 
    unsigned min_index; 
    for (unsigned i = 0; i < que.size(); i++) { 
        if (distances[que[i]] < shortest_dist) { 
            shortest_dist = distances[que[i]]; 
            min_index = i; 
        }
    }
    return que[min_inxdex];
}

