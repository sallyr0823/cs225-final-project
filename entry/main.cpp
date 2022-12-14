#include <iostream>
#include <vector>
#include "../src/file_reader.h"
#include "../src/airport.h"
#include "../src/edge.h"
#include "../src/airport_graph.h"
#include "../src/dijikstra.h"
#include "../src/BFS.h"
#include "../src/pagerank.h"

using namespace std;



int main()
{

     cout << "CS225 final project : Open Flights" << endl;
     cout << "-----------------------------------------------" << endl;



    bool dataset_exist = false;
    bool status = true;
    map<unsigned, unsigned> mp;
    vector<Airport> airports;
    vector<Edge> edges;
    while(!dataset_exist && status) {
        string begin_choice;
        cout << endl;
        cout << "We have prepared datasets from OpenFlights.org with information of airports and routes" << endl;
        cout << "If you want to continue, please enter y. It you want to quit, please enter q." << endl;
        cin >> begin_choice;
        if(begin_choice == "y") {
            vector<string> airport = file_to_string("../data/airports.txt");
            cout << airport.size();
            for (unsigned int i = 0; i < airport.size(); i++) {
                double x;
                double y;
                vector<string> out= split_string(airport[i],',');
                try {
            //cout << out[6] << endl;
                    x = stod(out[6]);
                    y = stod(out[7]);
            
                } catch(...) {
                    continue;
                }
                x = stod(out[6]);
                y = stod(out[7]);
                Airport a(stoul(out[0]),out[1],out[2],out[3],out[4],out[5], x,y);
                airports.push_back(a);
            }
   
            
            for (unsigned int i = 0; i < airports.size(); i++) {
                mp[airports[i].AirportID()] = i;
            }

            


            vector<string> edge_data = file_to_string("../data/routes.txt");
            for (unsigned i = 0; i < edge_data.size(); i++) {
                vector<string> out= split_string(edge_data[i],',');
                if(out[3] == "\\N" || out[5] == "\\N") {continue;}
                unsigned x;
                unsigned y;
                try {
                //cout << out[6] << endl;
                x = stoul(out[3]);
                y = stoul(out[5]);
                
                } catch(...) {
                continue;
                }
                x = stoi(out[3]);
                y = stoi(out[5]);
                if(mp.find(x) == mp.end() || mp.find(y) == mp.end()) {
                    continue;
                }
                Airport source = airports[mp[x]];
                Airport dest = airports[mp[y]];
            
                Edge e(source, dest);
                edges.push_back(e);
                
            }
            dataset_exist = true;
        } else if(begin_choice == "q") {
             status = false;
        } else {
            cout << "Invalid input! Please try again." << endl;
        }
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
    cout << endl;
    while(status) {
        string algo_choice;
        cout << "Please enter an algorithm name or enter q to quit" << endl;
        cin >> algo_choice;
        if(algo_choice == "bfs") {
            cout << "Now it's bfs algorithm" << endl;
            cout << endl;
            int source = 0;
            int destination;
            BFS bfs(graph);
            while(true) {
            source = 0;
            destination = 0;
            cout << endl;
            cout << "You can enter two airport id (0-14110 recommended) to see the route path between these two airports" << endl;
            cout << "Enter -1 to end this algorithm" << endl;
            cout << endl;
            cout << "Enter a departure airport id:" << endl;
            cin >> source;
            if(source == -1) {
                break;
            }
            cout << "Enter a destination airport id:" << endl;
            cin >> destination;
            cout << endl;
            cout << "The path is:" << endl;
            vector<unsigned> path = bfs.BFS_path(source,destination);
            if(path.size() == 0) {
                cout << "Sorry, there are no available routes or airport doesn't exist" << endl;
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
            if(path.size() != 0) {
                cout << bfs.print_distance(source,destination) <<endl;
            } else {
                cout << "0.0" << endl;
            }
            }
            
        } else if (algo_choice == "dij") {
            cout << endl;
            cout << "Now it's dijkstra algorithm" << endl;
            int source = 0;
            int destination;
            while(true) {
                //2333,3888
                source = 0;
                destination = 0;
                cout<<endl;
                cout << "You can enter two airport id (0-14110 recommended) to see the route path between these two airports" << endl;
                cout << "Enter -1 to end this algorithm" << endl;
                cout << endl;
                cout << "Enter a departure airport id:" << endl;
                cin >> source;
                if(source == -1) {
                break;
                }
                cout << "Enter a destination airport id:" << endl;
                cin >> destination;
                cout << endl;
                cout << "The path is:" << endl;
            
                Dijisktra dij(graph);
            
            vector<unsigned> path = dij.shortest_path(source, destination);
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
            cout << endl;
            cout << "The distance is: " << endl;
            if(path.size() != 0) {
                cout << dij.print_distance(source,destination) <<endl;
            } else {
                cout << "0.0" << endl;
            }
            }
            
        } else if(algo_choice == "pg") {
            cout << "Now it's pagerank algorithm" << endl;
            double damp = 0.0;
            int iteration = 0;
            int rank = 0;
            cout << endl;
            cout << "Please enter a damp factor(0~1) and an iteration factor(too large may cause slow speed)" << endl;
            while(damp < 0 || damp > 1) {
                cout << "Invalid damp, try again";
            }
            cout << "damp factor:" << endl;
            cin >> damp;
            while(damp < 0 || damp > 1) {
                cout << "Invalid damp, try again" << endl;
                cout << "damp factor:" << endl;
                cin >> damp;
            }
            cout << "iterations:" << endl;
            cin >> iteration;
            while(iteration < 0) {
                cout << "Invalid iterations, try again" << endl;
                cout << "iterations:" << endl;
                cin >> iteration;
            }
            cout << endl;
            cout << "Please wait for a second, we are generating the rankings for you" << endl;
            PageRank pg(graph);
            pg.init_rank(damp,iteration);
            pg.store_pagerank();
            cout << endl;
            cout << "Now you can go to ""pagerank.txt"" to check whole rankings" << endl;
            while(rank != -1) {
                cout<<endl;
                 cout << "Enter a rank(1~7678) to see which airport is at this rank" <<endl;
                 cout << "Enter -1 to end this algorithm" <<endl;
                cin >> rank;
                if(rank == -1) {
                    break;
                }
                cout << pg.print_rank(rank) << endl;
            }
        }   else if(algo_choice == "q") {
            cout << "End" <<endl;
            return 0;
        }
    }

    return 0;
}