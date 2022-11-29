#include "catch/catch.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "../airport.h"
#include "../edge.h"
#include "../airport_graph.h"
#include "../dijikstra.h"
#include "../file_reader.h"

using namespace std;

TEST_CASE("test Graph" ) {
    
    
    vector<string> airport = file_to_string("data/airports.dat");
    //unsigned ID, std::string name, std::string city,std::string country, std::string IATA, std::string ICAO,double latitude, double longitude
    
    vector<Airport> airports;
    
    for (unsigned int i = 0; i < airport.size(); i++) {
        vector<string> out= split_string(airport[i],',');
        try {
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
  
  REQUIRE(airport.size() == 7698);
  REQUIRE(graph.exist_airport(153));
  REQUIRE(graph.getEdge(4029, 6969).getWeight() > 0.0);
}


TEST_CASE("test dijikstra" ) {
    
    
    vector<string> airport = file_to_string("data/airports.dat");
    //unsigned ID, std::string name, std::string city,std::string country, std::string IATA, std::string ICAO,double latitude, double longitude
    
    vector<Airport> airports;
    
    for (unsigned int i = 0; i < airport.size(); i++) {
        vector<string> out= split_string(airport[i],',');
        try {
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
  Dijisktra dij(&graph);
  

  vector<unsigned> path =  dij.shortest_path(airports[mp[2966]], airports[mp[2975]]);
  
  REQUIRE(airports[path[1]].AirportName() == "\"Pulkovo Airport\"");
  REQUIRE(airports[path[2]].AirportName() == "\"Koltsovo Airport\"");
  
}