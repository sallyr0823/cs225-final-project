
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "file_reader.h"
using namespace std;


vector<string> file_to_string(const string& filename) {
    vector<string> out;
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
        	out.push_back(line);	
        }
    }
    file.close();
    return out;
}



vector<string> split_string(string& input) {
    char delim = ',';
    vector<string> out;
    stringstream stream(input);
    string line;
    while(getline(stream,line,delim)) {
        out.push_back(line);
    }
    return out;
}

vector<vector<string > > file_to_vector(const string& filename) {
    vector<string> tmp = file_to_string(filename);
    vector<vector<string > > result;
    for(string s: tmp) {
        result.push_back(split_string(s));
    }
    return result;
}