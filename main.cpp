#include <iostream>
#include <vector>
#include "file_reader.h"
#include "airport.h"
#include "edge.h"

using namespace std;

int main()
{
    vector<vector<string >> airport = file_to_vector("data/airports.dat");
    vector<string> out= airport[0];
    //unsigned ID, std::string name, std::string city,std::string country, std::string IATA, std::string ICAO,double latitude, double longitude
    Airport a(stoul(out[0]),out[1],out[2],out[3],out[4],out[5],stod(out[6]),stod(out[7]));
    Edge b;
    
    cout << airport.size() << endl;
    return 0;
}