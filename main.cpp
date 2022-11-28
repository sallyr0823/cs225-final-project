#include <iostream>
#include <vector>
#include "file_reader.h"
#include "airport.h"
#include "edge.h"
#include "airport_graph.h"
#include "dijikstra.h"
#include "BFS.h"
#include "pagerank.h"

using namespace std;


int main()
{
    vector<string> airport = file_to_string("data/airports.dat");
    //unsigned ID, std::string name, std::string city,std::string country, std::string IATA, std::string ICAO,double latitude, double longitude
    
    vector<Airport> airports;
    for (unsigned int i = 0; i < airport.size(); i++) {
        vector<string> out= split_string(airport[i],',');
        try {
            //cout << out[6] << endl;
            double x = stod(out[6]);
            double y = stod(out[7]);
            
        } catch(...) {
            continue;
        }
        Airport a(stoul(out[0]),out[1],out[2],out[3],out[4],out[5], stod(out[6]),stod(out[7]));
        airports.push_back(a);
    }
   
    map<unsigned, unsigned> mp;
    for (unsigned int i = 0; i < airports.size(); i++) {
        mp[airports[i].AirportID()] = i;
    }


    vector<Edge> edges;
    vector<string> edge_data = file_to_string("data/routes.dat");
    for (unsigned i = 0; i < edge_data.size(); i++) {
        vector<string> out= split_string(edge_data[i],',');
        try{
            int s = stoul(out[3]);
            int d = stoul(out[5]);
        } catch(...) {
            continue;
        }
        Airport source = airports[mp[stoul(out[3])]];
        Airport dest = airports[mp[stoul(out[5])]];
        Edge e(source, dest);
        edges.push_back(e);
    }

 
    Graph graph (airports, edges);
    
    BFS bfs(&graph);

    Dijisktra dij(&graph);

    
    vector<unsigned> path =  dij.shortest_path(airports[mp[2966]], airports[mp[2975]]);
    vector<unsigned> path_2 = bfs.BFS_path(airports[mp[2966]],airports[mp[2975]]);

    
    for (unsigned i = 0; i < path.size(); i++) {
        cout<<airports[path[i]].AirportName();
        if(i < path.size() - 1) {
            cout << "->";
        } else {
            cout << endl;
        }
    }
    cout << dij.print_distance(airports[mp[2966]],airports[mp[2975]])<<endl;
    
    for (unsigned i = 0; i < path_2.size(); i++) {
        cout<<airports[path_2[i]].AirportName();
        if(i < path_2.size() - 1) {
            cout << "->";
        } else {
            cout << endl;
    }
    }
    cout << bfs.print_distance(airports[mp[2966]],airports[mp[2975]])<<endl;
    

    cout << airport.size() << endl;
    return 0;
}