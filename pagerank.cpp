#include "pagerank.h"

void PageRank::init_rank_matrix(Graph& graph) {
    size_t num_ = graph.get_num_airports();
    airports_ = graph.get_airports();
    edges_ = graph.get_routes();
    unordered_map<unsigned, vector<unsigned >>& adjList = graph.get_adjList();
    // initialize transopose of pagerank
    vector<unsigned> insert(num_,0);
    for (size_t i = 0; i < num_; i++) {
        mp[airports_[i].AirportID()] = i; 
        rank_.push_back(insert);
    }
    graph_ = graph;
    for(auto apt : adjList) {
        unsigned ind = mp[apt.first];
        unsigned fac = apt.second.size();
        for(auto adj_apt : apt.second) {
            rank_[mp[adj_apt]][ind] = 1 / fac;
        }
    }
}

std::vector<unsigned> PageRank::prob_calculation(Graph & graph,unsigned damp) {
    size_t num_airports = graph.get_num_airports();
    // Initialize the rank vector as evenly distributed
    std::vector<double> rank_vector;
    for (size_t k = 0; k < num_airports; k++) {
        rank_vector.push_back(1.0 / double(num_airports));
    }
    while (true) {
        // Set x(t) to be the first value of the rank vector as all elements are equal in in the initialization
        double prev_value = rank_vector[0];
        std::vector<double> prev_vector = rank_vector;
        for (size_t i = 0; i < num_airports; i++) {
            double sum = 0;
            for (size_t j = 0; j < num_airports; j++) {
                sum += double(prev_vector[j]) * double(graph.get_rank_matrix()[j][i]);
            }
            rank_vector[i] = sum;
        }
        // Computation ends for some small epsilon (take 0.1 here), convergence is assumed
        if (abs(rank_vector[0] - prev_value) < 0.1) {
            break;
        }
    }
    return rank_vector;
}

std::vector<Airport> PageRank::get_airport_rank(Graph & graph) {
    std::vector<Airport> airport_rank_vector;
    std::vector<double> rank_vector = prob_calculation(graph);
    std::vector<Airport> airports = graph.get_airports();
    size_t num_airports = graph.get_num_airports();
    // Loop through to get the airport with the maximum rank value
    for (unsigned i = 0; i < num_airports; i++) {
        int max_elem_idx = std::max_element(rank_vector.begin(), rank_vector.end()) - rank_vector.begin();
        rank_vector[max_elem_idx] = -1;
        airport_rank_vector.push_back(airports[max_elem_idx]);
    }
    return airport_rank_vector;
}

void PageRank::store_pagerank(Graph& graph) {
    std::ofstream page;
    page.open("pagerank.txt");

    std::vector<Airport> rank_vector = get_airport_rank(graph);
    for(unsigned i = 0; i < rank_vector.size(); i++) {
        page << i << " : " << rank_vector[i].AirportName()<< std::endl;
    }
    page.close();
}
