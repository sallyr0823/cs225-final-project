#include <iostream>
#include <vector>
#include "file_reader.h"
#include "airport.h"
#include "edge.h"

using namespace std;

int main()
{
    vector<vector<string >> airport = file_to_vector("dataset/airports.dat.txt");
    Airport a;
    Edge b;
    
    cout << airport.size() << endl;
    return 0;
}