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

     cout << "CS225 final project : Open Flights" << endl;
     cout << "-----------------------------------------------" << endl;


    /*for (unsigned i = 0; i < path.size(); i++) {
        cout<<airports[path[i]].AirportName();
        if(i < path.size() - 1) {
            cout << "->";
        } else {
            cout << endl;
        }
    }*/

    bool dataset_exist = false;
    bool status = true;
    while(!dataset_exist && status) {
        vector<Airport> airports;
        vector<Edge> edges;
        string begin_choice;
        cout << endl;
        cout << "We have prepared datasets from OpenFlights.org with information of airports and routes" << endl;
        cout << "If you want to continue, please enter yes. It you want to quit, please enter no." << endl;
        cin >> begin_choice;
        if(begin_choice == "yes") {
            vector<string> airport = file_to_string("data/airports.txt");
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


            vector<string> edge_data = file_to_string("data/routes.txt");
            for (unsigned i = 0; i < edge_data.size(); i++) {
             vector<string> out= split_string(edge_data[i],',');
            if(out[3] == "\N" || out[5] == "\N") {continue;}
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
            dataset_exist = true;
        } else if(begin_choice == "no") {
             status = false;
        } else {
            cout << "Invalid input! Please try again." << endl;
        }
    Graph graph(airports,edges);
    string algo_choice;
        cout << endl;
        cout << "We have prepared several algorithms." << endl;
        cout << "Please choose the algorithm you want to run." << endl;
        cout << "The available algorithms are: " << endl;
        cout << "Find shortest path based on stops bewteen two airports with BFS Algorithm(enter bfs)" << endl;
        cout << "Find shortest path based on distance bewteen two airports with Dijikstra Algorithm(enter dij)" << endl;
        cout << "Find the most important airport with PageRank Algorithm(enter pg)" << endl;
        cout << "If you want to quit, please enter q" << endl;
        cin >> algo_choice;
        if(algo_choice == "bfs") {
            unsigned source;
            unsigned destination;
            BFS bfs(graph);
            cout << "You can enter two airport id (0-14110 recommended) to see the route path between these two airports" << endl;
            cout << "Enter a departure airport id:" << endl;
            cin >> source;
            cout << "Enter a destination airport id:" << endl;
            cin >> destination;
            cout << endl;
            cout << "The path is:" << endl;
            vector<unsigned> path = bfs.BFS_path(source,destination);
            if(path.size() == 0) {
                cout << "Sorry, there are no available routes or airport doesn't exists" << endl;
            } else {
                for (size_t i = 0; i < path.size(); i++) {
                cout<<airports[path[i]].AirportName();
                if(i < path.size() - 1) {
                    cout << "->";
                } else {
                    cout << endl;
                }
            }
            }
            cout << "The distance is: " << endl;
            cout << bfs.print_distance(source,destination) << endl;
        }

    }
    return 0;
}