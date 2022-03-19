#ifndef _GAME_MANAGER_
#define _GAME_MANAGER
#include "../Inventory/Inventory.hpp"
#include "../Craft/Craft.hpp"
#include "../FileManager/FileManager.hpp"
#include "../TerminalManager/TerminalManager.hpp"
#include "../Item/Item.hpp"
#include<map>

class GameManager {
    private:
    Inventory inventory;
    Craft craft;
    map<string,int> mpNameId;
    map<int, Item*> mpIdItem;
    FileManager fileManager;
    TerminalManager terminalManager;

    public:
    GameManager();
    // fitur load/save?
    // ~GameManager();

    void play();

    
};

#endif