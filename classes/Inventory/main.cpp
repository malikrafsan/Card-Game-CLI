#include <iostream>
#include "Inventory.hpp"
#include "../Item/NonTool.hpp"
#include "../Item/TypedNonTool.hpp"
#include "../Item/Tool.hpp"
using namespace std;

int main(){
    try
    {
        Inventory inventory;
        cout << inventory << endl;

        inventory.give(new NonTool(1, "Diamond"), 50);
        // cout << inventory << endl;

        inventory.give(new Tool(2, "Axe"), 1);
        // cout << inventory << endl;

        inventory.give(new TypedNonTool(3, "Birch_Plank", "Plank"), 1);
        // cout << inventory << endl;

        // bool cek = inventory.isInvSlotValid("I0", 12);
        // cout << cek << endl;

        // cek = inventory.isInvSlotValid("I0", 60);
        // cout << cek << endl;

        // cek = inventory.canBeAdded(new NonTool(1, "Diamond"), "I0", 14);
        // cout << cek << endl;

        // cek = inventory.canBeAdded(new TypedNonTool(3, "Birch Log", "Log"), "I0", 60);
        // cout << cek << endl;

        // inventory.use("I1");
        // cout << inventory << endl;
        
        // inventory.use("I1");
        // cout << inventory << endl;

        inventory.give(new NonTool(1, "Diamond"), 50);
        inventory.give(new Tool(2, "Axe"), 20);
        cout << inventory << endl;

        inventory.give(new TypedNonTool(3, "Birch_Plank", "Plank"), 150);
        cout << inventory << endl;
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
}

// g++ -o main main.cpp Inventory.cpp ../Storage/Storage.cpp ../Slot/Slot.cpp