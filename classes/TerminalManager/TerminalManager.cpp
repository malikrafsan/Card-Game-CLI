#include "TerminalManager.hpp"
#include<iostream>
#include<sstream>

TerminalManager::TerminalManager() {;}

vector<string> TerminalManager::readCommand() {
    vector<string> ret;
    while((int)ret.size()==0) {
        cout <<"INSERT COMMAND: ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        while(ss >> word) {
            ret.push_back(word);
        }
    }
    return ret;
}