#include "catch/catch.hpp"
#include <vector>
#include <string>
#include <iostream>

#include "../file_reader.h"

using namespace std;

TEST_CASE("file_reader working" ) {
    vector<vector<string>> airport = file_to_vector("/Users/sallyr/Documents/final_proj/dataset/airports.dat");
    
    REQUIRE("""Goroka Airport""" == airport[0][1]);

}
