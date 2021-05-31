//
// Created by xogh2 on 2021-05-30.
//
#include "process.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, ' ')) {
        internal.push_back(temp);
    }
    return internal;
}

vector<string> f_get(const string& dir, const string& f_name) {
    vector<string> ret, tmp;
    ifstream readFile;
    readFile.open(dir + f_name);
    string str;
    if(readFile.is_open()) {
        while(!readFile.eof()) {
            getline(readFile, str);
            tmp = split(str);
            for(auto i : tmp)
                ret.push_back(i);
        }
    }
}