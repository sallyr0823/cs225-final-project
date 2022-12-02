#include "catch/catch.hpp"
#include <vector>
#include <string>
#include <iostream>

#include "../file_reader.h"

using namespace std;

TEST_CASE("file_reader working" ) {
    vector<string> airport = file_to_string("/Users/sallyr/Documents/final_proj/dataset/airports.dat");
    

}
