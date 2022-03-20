#ifndef _GAME_MANAGER_
#define _GAME_MANAGER
#include "../Inventory/Inventory.hpp"
#include "../Craft/Craft.hpp"
#include "../FileManager/FileManager.hpp"
#include "../TerminalManager/TerminalManager.hpp"
#include "../Item/NonTool.hpp"
#include "../Item/TypedNonTool.hpp"
#include<map>

class GameManager {
    private:
    Inventory inventory;
    Craft* craft;
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
};

#endif