
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "file_reader.h"
using namespace std;


vector<string> file_to_string(const string& filename) {
	ifstream input(filename);
	string currLine;
	vector<string> out;

	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			out.push_back(line);	
		}
	}
	input.close();
	return out;
}

vector<string> split_string(const string& to_split, const char& delim) {
	vector<string> out;
	istringstream input(to_split);
	string add;
	while(getline(input, add, delim)) {
		out.push_back(add);
	}
	return out;
}
