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
    double convergence = 0.1;
    bool stop = false;
    // initialize pi vector
    vector<double> new_rank_;
    double N = (float)1 / num_;
    for(size_t k = 0; k < num_; k++) {
        rank_.push_back(N);
    }
    new_rank_ = rank_;
    // initialize iteration
    double dangling_pr;
    double sum_pr;
    int count= 0;
    // (1-damp)
    double jump_pr = (float)(1-damp)/num_;
    while(stop == false && count < iteration) {
        count++;
        
        dangling_pr = 0.0;
        sum_pr = 0.0;

        // normalize
        for(size_t m = 0; m < num_; m++) {
            sum_pr += rank_[m];
        }

        if (count == 1) {
            continue;
        } else {
            
            for (size_t i = 0; i < num_; i++) {
                rank_[i] = (float)rank_[i] / sum_pr;
            }
        }


        for(size_t k = 0; k < num_; k++) {
            // adj list contains their id
            vector<unsigned> adj_apt = adjList[airports_[k].AirportID()];
            size_t adj_size = adj_apt.size();
            // initialize new_rank with jump factor
            new_rank_[k] += jump_pr;
            if(adj_size > 0) {
                for(size_t i = 0; i < adj_size; i++) {
                    new_rank_[mp[adj_apt[i]]] += damp * (float)(rank_[k] / adj_size);
            }
            } else {
                for(size_t m = 0; m < num_; m++) {
                    new_rank_[m] += rank_[m] * damp * N;
                }
            }
        }
        stop = true;
        for(size_t j = 0; j < num_; j++) {
            //cout<<fabs(new_rank_[j] - rank_[j])<<endl;
            if(fabs(new_rank_[j] - rank_[j]) > convergence) {
                
                stop = false;
                break;
            }
        }
        rank_ = new_rank_;
        
    }

    
}



vector<unsigned> PageRank::get_airport_rank() {
    vector<double> app_rank = rank_;
    // Loop through to get the airport with the maximum rank value
    size_t num_ = airports_.size();
    vector<unsigned> airport_rank_;
    for (unsigned i = 0; i < num_; i++) {
        int max_elem_idx = max_element(app_rank.begin(), app_rank.end()) - app_rank.begin();
        app_rank[max_elem_idx] = -1;
        unsigned id = airports_[max_elem_idx].AirportID();
        airport_rank_.push_back(id);
    }
    return airport_rank_;
}

string PageRank::print_rank(int rank) {
    if(rank <= 0 || rank > (int)num_) {
        return "Invalid input, try again";
    }
    unsigned airportid = get_airport_rank()[rank - 1];
    string output = airports_[mp[airportid]].AirportName() ;
    output += " is ranked ";
    output += to_string(rank);
    return output;
}

void PageRank::store_pagerank() {
    std::ofstream page;
    page.open("/pagerank_output/pagerank.txt");
    vector<double> app_rank = rank_;
    sort(app_rank.begin(),app_rank.end());
    reverse(app_rank.begin(),app_rank.end());
    vector<unsigned> airport_rank_ = get_airport_rank();
    for(unsigned i = 0; i < num_; i++) {
        page << i + 1 << " : " << airports_[mp[airport_rank_[i]]].AirportName() << " : " << app_rank[i]<< endl;
    }
    page.close();
}
