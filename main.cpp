#include <iostream>
#include <vector>
#include "file_reader.h"
#include "airport.h"
#include "edge.h"
#include "airport_graph.h"
#include "dijikstra.h"

using namespace std;

int main()
{
    vector<vector<string >> airport = file_to_vector("data/airports.dat");
    //unsigned ID, std::string name, std::string city,std::string country, std::string IATA, std::string ICAO,double latitude, double longitude
   // Airport a(stoul(out[0]),out[1],out[2],out[3],out[4],out[5],stod(out[6]),stod(out[7]));
    Edge b;
    
    vector<Airport> airports;
    for (unsigned int i = 0; i < airport.size(); i++) {
        vector<string> out= airport[i];
        try {
            //cout << out[6] << endl;
            double x = stod(out[6]);
            double y = stod(out[7]);
            
        } catch(...) {
            continue;
        }
        Airport a(stoul(out[0]),out[1],out[2],out[3],out[4],out[5], stod(out[6], nullptr), stod(out[7], nullptr));
        airports.push_back(a);
        //cout << out[6] << endl;
    }
   
    map<unsigned, unsigned> mp;
    for (unsigned int i = 0; i < airports.size(); i++) {
        mp[airports[i].AirportID()] = i;
    }


    vector<Edge> edges;
    vector<vector<string >> edge_data = file_to_vector("data/routes.dat");
    for (unsigned int i = 0; i < edge_data.size(); i++) {
        vector<string> out= edge_data[i];
        if (out[3] == "\\N" || out[5] == "\\N")  {
            continue;
        }
        int sourceId = stoul(out[3]);
        int destId = stoul(out[5]);
        Airport source = airports[mp[sourceId]];
        Airport dest = airports[mp[destId]];
        Edge e(source, dest);
        edges.push_back(e);
    }

 
    Graph graph (airports, edges);
    

    Dijisktra dij(&graph);

    
    vector<unsigned> path =  dij.shortest_path(airports[mp[3364]], airports[mp[3797]]);
    
    for (unsigned i = 0; i < path.size(); i++) {
        cout<<airports[path[i]].AirportName();
        if(i < path.size() - 1) {
            cout << "->";
        } else {
            cout << endl;
        }
    }
    
    cout << airport.size() << endl;
    return 0;
}