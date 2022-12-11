#include "catch/catch.hpp"
 #include <vector>
 #include <string>
 #include <iostream>
 #include "../src/airport.h"
 #include "src/edge.h"
 #include "src/airport_graph.h"
 #include "src/dijikstra.h"
 #include "src/file_reader.h"
 #include "src/pagerank.h"
 #include "src/BFS.h"

 using namespace std;


TEST_CASE("test file_reader") {
    vector<string> test_string = file_to_string("data/test_data.txt");
    REQUIRE(test_string[0] == "monday,is,1");
    REQUIRE(test_string[1] == "tuesday,is,2");
    REQUIRE(test_string[2] == "wednesday,is,3");
    REQUIRE(test_string[3] == "thursday,is,4");
    vector<string> test_split = split_string(test_string[1],',');
    REQUIRE(test_split[2] == "2");

}
TEST_CASE("test airport") {
    unsigned int id = 1234;
    unsigned int id_2 = 2345;
	Airport sample(id, "test","Champaign","USA","1111","2222",1.0, 1.0);
	REQUIRE(sample.AirportID() == 1234);
	REQUIRE(sample.AirportName() == "test");
	REQUIRE(sample.AirportIATA() == "1111");
	pair<double, double> loc = make_pair(1.0, 1.0);
	REQUIRE(sample.AirportLocation() == loc);
    Airport sample_2(id_2, "test","Champaign","USA","1111","2222",1.0, 1.0);
	REQUIRE(!(sample == sample_2));
}


TEST_CASE("test edge and airport_graph") {

     vector<string> airport = file_to_string("data/airports.txt");
     //unsigned ID, std::string name, std::string city,std::string country, std::string IATA, std::string ICAO,double latitude, double longitude
     vector<string> fake_airport = file_to_string("data/test_airports.txt");
     vector<Airport> airports;
     vector<Airport> fake_airports;

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
     for (unsigned int i = 0; i < fake_airport.size(); i++) {
         vector<string> out= split_string(fake_airport[i],',');
         Airport a(stoul(out[0]),out[1],out[2],out[3],out[4],out[5], stod(out[6]),stod(out[7]));
         if(i >= 1 && i < fake_airport.size() - 1) {
            Airport b = fake_airports[i-1];
            REQUIRE(!(a==b));
         }
         fake_airports.push_back(a);
     }

     map<unsigned, unsigned> mp;
     for (unsigned int i = 0; i < airports.size(); i++) {
         mp[airports[i].AirportID()] = i;
     }

     vector<Edge> edges;
     vector<Edge> fake_edges;
     vector<string> edge_data = file_to_string("data/routes.txt");
     vector<string> fake_edge_data = file_to_string("data/test_routes.txt");

    for (unsigned i = 0; i < edge_data.size(); i++) {
        vector<string> out= split_string(edge_data[i],',');
        if(out[3] == "\\N" || out[5] == "\\N") {continue;}
        try {
            //cout << out[6] << endl;
            int x = stoi(out[3]);
            int y = stoi(out[5]);
            
        } catch(...) {
            continue;
        }
        if(mp.find(stoi(out[3])) == mp.end() || mp.find(stoi(out[5])) == mp.end()) {
            continue;
        }
        Airport source = airports[mp[stoi(out[3])]];
        Airport dest = airports[mp[stoi(out[5])]];
        
        Edge e(source, dest);
        edges.push_back(e);
    }

    for (unsigned i = 0; i < fake_edge_data.size(); i++) {
        vector<string> out= split_string(fake_edge_data[i],',');
        if(out[3] == "\\N" || out[5] == "\\N") {continue;}
        Airport source = airports[mp[stoi(out[3])]];
        Airport dest = airports[mp[stoi(out[5])]];
        
        Edge e(source, dest);
        REQUIRE(e.getSourceId() == stoi(out[3]));
        REQUIRE(e.getDestId() == stoi(out[5]));
        fake_edges.push_back(e);
    }


   Graph graph (airports, edges);   
   Graph fake_graph(fake_airports, fake_edges);
   REQUIRE(graph.get_airports().size() == 7678 );
   REQUIRE(graph.exist_airport(2290));
   REQUIRE(!graph.exist_airport(413434234));
   Edge e;
   Edge to_test = fake_graph.getEdge(3,4);
   REQUIRE(fake_graph.get_adj_airport(3).size() == 1);
   REQUIRE(fake_graph.get_adj_airport(-1).size() == 0);
   REQUIRE(to_test.getSourceId() == 3);
 }

 TEST_CASE("test_bfs") {
    vector<string> fake_airport = file_to_string("data/test_airports.txt");
    vector<Airport> fake_airports;
    for (unsigned int i = 0; i < fake_airport.size(); i++) {
         vector<string> out= split_string(fake_airport[i],',');
         Airport a(stoul(out[0]),out[1],out[2],out[3],out[4],out[5], stod(out[6]),stod(out[7]));
         fake_airports.push_back(a);
     }
     map<unsigned, unsigned> mp;
     for (unsigned int i = 0; i < fake_airport.size(); i++) {
         mp[fake_airports[i].AirportID()] = i;
     }
     vector<string> fake_edge_data = file_to_string("data/test_routes.txt");
     vector<Edge> fake_edges;
     for (unsigned i = 0; i < fake_edge_data.size(); i++) {
        vector<string> out= split_string(fake_edge_data[i],',');
        if(out[3] == "\\N" || out[5] == "\\N") {continue;}
        Airport source = fake_airports[mp[stoi(out[3])]];
        Airport dest = fake_airports[mp[stoi(out[5])]];
        
        Edge e(source, dest);
        fake_edges.push_back(e);
    }
    Graph fake_graph(fake_airports, fake_edges);
    BFS bfs(fake_graph);
    REQUIRE(bfs.BFS_connected(2).size() == 3);
    vector<unsigned> path = bfs.BFS_path(2,4);
    REQUIRE(path[0] == 1);
    REQUIRE(path[1] == 0);
    REQUIRE(path[2] == 3);
 }

 TEST_CASE("test dijikstra" ) {
    
    
    vector<string> airport = file_to_string("data/test_airports.txt");
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
    vector<string> edge_data = file_to_string("data/test_routes.txt");
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
  Dijisktra dij(graph);
  vector<unsigned> path ;
  path =  dij.shortest_path(2, 4);
  
  REQUIRE(path.size() == 3);

  REQUIRE(airports[path[0]].AirportID() == 2);
  REQUIRE(airports[path[1]].AirportID() == 1);
  REQUIRE(airports[path[2]].AirportID() == 4);

  path =  dij.shortest_path(1, 4);
  
  REQUIRE(path.size() == 2);

  REQUIRE(airports[path[0]].AirportID() == 1);
  REQUIRE(airports[path[1]].AirportID() == 4);
}
TEST_CASE("test pagerank" ) {
    
    
    vector<string> airport = file_to_string("data/test_airports.txt");
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
    vector<string> edge_data = file_to_string("data/test_routes.txt");
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
  PageRank pg(graph);
  pg.init_rank(0.85,100);


  REQUIRE(pg.get_airport_rank()[0] == 4);
}

