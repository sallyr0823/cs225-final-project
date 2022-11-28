#include "PageRank.h"

void PageRank::init_rank_matrix(Graph & graph) {
    size_t num_airports = graph.get_num_airports();
    std::vector<std::vector<double >> rank_matrix = graph.get_rank_matrix();
    for (size_t i = 0; i < num_airports; i++) {
        int number = 0;
        // Check whether two airports has already been recorded in the rank matrix
        for (size_t j = 0; j < num_airports; j++) {
            if (rank_matrix[i][j] != 0) {
                number++;
            }
        }
        // Airports has edges between them, utlize the PageRank algorithm
        if (number != 0) {
            for (size_t t = 0; t < num_airports; t++) {
                if (rank_matrix[i][t] != 0) {
                    rank_matrix[i][t] = rank_matrix[i][t] / number;
                }
            }
        } else {
            // This airport does not appear in the rank matrix
            for (size_t k = 0; k < num_airports; k++) {
                rank_matrix[i][k] = 1.0 / double(num_airports);
            }
        }
    }
}

std::vector<double> PageRank::prob_calculation(Graph & graph) {
    size_t num_airports = graph.get_num_airports();
    // Initialize the rank vector as evenly distributed
    std::vector<double> rank_vector;
    for (size_t k = 0; k < num_airports; i++) {
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
    for (int i = 0; i < num_airports; i++) {
        int max_elem_idx = std::max_element(rank_vector.begin(), rank_vector.end()) - rank_vector.begin();
        rank_vector[max_elem_idx] = -1;
        airport_rank_vector.push_back(airports[max_elem_idx]);
    }
    return airport_rank_vector;
}