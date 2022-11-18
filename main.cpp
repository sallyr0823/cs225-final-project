#include <iostream>
#include <vector>
#include "file_reader.h"

using namespace std;

int main()
{
    vector<vector<string >> airport = file_to_vector("dataset/airports.dat.txt");
    cout << airport.size() << endl;
    return 0;
}