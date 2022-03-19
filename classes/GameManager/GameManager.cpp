#include "GameManager.hpp"

GameManager::GameManager() {
    string configPath = "./config";
    string itemConfigPath = configPath + "/item.txt";
    vector<string> itemConfig = fileManager.readFile(itemConfigPath);
    for(string s : itemConfig) {
        stringstream ss(s);
        string temp[4];
        ss >>temp[0] >>temp[1] >>temp[2] >>temp[3];
        int id = stoi(temp[0]);
        string name = temp[1];
        mpNameId[name] = id;
        // perlu ada exception id bukan int, 1 line kurang dari 4 kata ga?
    }
    // Stick* stick = new Stick(mpNameId["STICK"]);
    // mpIdItem[mpNameId["STICK"]] = stick;
}

void GameManager::play() {
    bool isExit=false;
    while(!isExit) {
        // print CRAFT dan INVENTORY
        vector<string> command = terminalManager.readCommand();
        if(command[0]=="GIVE") {

        } else if(command[0]=="DISCARD") {

        } else if(command[0]=="MOVE") {

        } else if(command[0]=="CRAFT") {

        } else {
            // throw invalid command exception
        }
    }    
}