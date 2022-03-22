#ifndef _GAME_MANAGER_
#define _GAME_MANAGER
#include "../Inventory/Inventory.hpp"
#include "../Craft/Craft.hpp"
#include "../FileManager/FileManager.hpp"
#include "../TerminalManager/TerminalManager.hpp"
#include "../Item/NonTool.hpp"
#include "../Item/TypedNonTool.hpp"
#include<map>
#include<set>

class GameManager {
    private:
    Inventory inventory;
    Craft* craft;
    set<string> tools;
    set<string> nonTools;
    set<array<string,2>> typedNonTools;
    map<string,int> mpNameId;
    map<int, Item*> mpIdItem;
    FileManager fileManager;
    TerminalManager terminalManager;

    public:
    GameManager();
    // fitur load/save?
    ~GameManager();

    void play();
    void giveCommand(vector<string> command);
    void discardCommand(vector<string> command);
    void moveCommand(vector<string> command);
    void craftCommand(vector<string> command);
    void useCommand(vector<string> command);
    void exportCommand(vector<string> command);
    void helpCommand(vector<string> command);
};

class InvalidCommandException : public exception {
    private:
    string _What;
    public:
    InvalidCommandException(string command) {
        _What = "INVALID COMMAND "+command;
    }
    const char *what() const throw() { return _What.c_str();}
};

class ItemNotFoundException: public exception {
    private:
    string _What;
    public:
    ItemNotFoundException(string name) {
        _What = "Item " + name + " not found";
    }
    const char *what() const throw() { return _What.c_str();}
};

#endif