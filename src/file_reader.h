/**
 * @file file_reader.h
 *
 *
 * @author Sally Rong
 * @date Fall 2022
 * 
 * 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#pragma once
using namespace std;
//with this file_reader, we convert the original file into a 2d vector


vector<string > file_to_string(const string& filename);
vector<string> split_string(const string& to_split, const char& delim);