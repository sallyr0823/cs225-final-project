
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "file_reader.h"
using namespace std;


vector<vector<string >> file_to_vector(const string& filename) {
	ifstream input(filename);
	string currLine;
	vector<vector<string >> out;

	if (input.is_open()) {
		while (getline(input, currLine)) {
			istringstream currLineStream(currLine);
			string add;
			vector<string> line;
			while (getline(currLineStream, add, ',')) {
				line.push_back(add);
			}
			out.push_back(line);
		}
	}
	input.close();
	return out;
}