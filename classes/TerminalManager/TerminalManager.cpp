#include "TerminalManager.hpp"
#include<iostream>
#include<sstream>

TerminalManager::TerminalManager() {;}

vector<string> TerminalManager::readCommand() {
    cout <<"INSERT COMMAND: ";
    vector<string> ret;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    while(ss >> word) {
        ret.push_back(word);
    }
    return ret;
}