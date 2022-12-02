#include "pagerank.h"
using namespace std;



PageRank::PageRank(Graph& graph) {
    airports_ = graph.get_airports();
    adjList = graph.get_adjList(); 
    num_ = graph.get_num_airports();
    for (size_t i = 0; i < num_; i++) {
        mp[airports_[i].AirportID()] = i; 
    }
}

void PageRank::init_rank(double damp, int iteration) {
    // initialize convergence
    double diff = 1;
    // initialize pi vector
    vector<unsigned> new_rank(num_,0);
    rank_.resize(num_,1/num_);
    int count = 0;
    double convergence = 0.5;
    double sum_pr = 0.0;
    double dangling_pr;
    // (1-damp)
    double jump_pr;
    // damp
    double damp_pr;
    while(diff > convergence && count < iteration) {
        sum_pr = 0.0;
        dangling_pr = 0;
        for (size_t i = 0; i < num_; i++) {
            double cpr = rank_[i];
            size_t adj_size = adjList[airports_[i].AirportID()].size();
            sum_pr += cpr;
            if (adj_size == 0) {
                dangling_pr += cpr;
            }
        }
        // normalize the distribution every time
        if (iteration == 0) {
            continue;
        } else {
            /* Normalize so that we start with sum equal to one */
            for (size_t j = 0; j < num_; j++) {
                rank_[j] = rank_[j] / sum_pr;
            }
        }
    // ref:https://www.ccs.neu.edu/home/daikeshi/notes/PageRank.pdf
        damp_pr = damp * dangling_pr / num_;
        jump_pr = (1-damp)/num_;
        for(size_t k = 0; k < num_; k++) {
            vector<unsigned> adj_apt = adjList[airports_[k].AirportID()];
            size_t adj_size = adj_apt.size();
            if(adj_size == 0) {
                new_rank[k] = damp_pr + jump_pr;
            } else {
                new_rank[k] = jump_pr;
                for(size_t i = 0; i < adj_size; i++) { 
                    double link = adjList[i].size() ? 1.0 / adjList[i].size() : 0.0;
                    new_rank[k] += damp * rank_[i] * link;
                }
            }
            diff += fabs(new_rank[k] - rank_[k]);
        }
        count++;
        rank_ = new_rank;
    }

    
}



vector<unsigned> PageRank::get_airport_rank() {
    vector<unsigned> app_rank = rank_;
    // Loop through to get the airport with the maximum rank value
    size_t num_ = airports_.size();
    vector<unsigned> airport_rank_;
    for (unsigned i = 0; i < num_; i++) {
        int max_elem_idx = std::max_element(app_rank.begin(), app_rank.end()) - app_rank.begin();
        app_rank[max_elem_idx] = -1;
        unsigned id = airports_[i].AirportID();
        airport_rank_.push_back(id);
    }
    return airport_rank_;
}

void PageRank::store_pagerank() {
    std::ofstream page;
    page.open("pagerank.txt");
;
    for(unsigned i = 0; i < num_; i++) {
        page << i << " : " << airports_[rank_[i]].AirportName()<< endl;
    }
    page.close();
}
