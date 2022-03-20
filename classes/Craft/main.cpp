#include <iostream>
#include "Craft.hpp"

#include "../Inventory/Inventory.hpp"
#include "../Item/NonTool.hpp"
#include "../Item/TypedNonTool.hpp"
#include "../Item/Tool.hpp"

using namespace std;


int main(){
    try
    {
        Inventory inv;
        Craft craft;

        cout << craft << endl << inv << endl;

        inv.addItem(new NonTool(1, "Diamond"), "I10", 50);
        inv.addItem(new Tool(2, "Axe"), "I20", 1);
        inv.addItem(new TypedNonTool(3, "Birch Plank", "Plank"), "I26", 1);

        cout << craft << endl << inv << endl;

        craft.move(inv[10], craft[0], 1);
        
        cout << craft << endl << inv << endl;


        craft.move(inv[20], craft[1], 1);
        
        cout << craft << endl << inv << endl;

        // craft.crafting();
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
}

// g++ -o main main.cpp Craft.cpp ../Storage/Storage.cpp ../Inventory/Inventory.cpp ../Slot/Slot.cpp ../Recipe/Recipe.cpp