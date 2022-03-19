#include <iostream>
#include "Craft.hpp"

#include "../Inventory/Inventory.hpp"
#include "../Item/NonTool.hpp"

using namespace std;


int main(){
    try
    {
        Inventory inv;
        Craft craft;


        craft.print();
        cout << endl;
        inv.print();
        cout << endl;

        inv.addItem(new Diamond(1), 0, 0, 1);
        inv.addItem(new Stick(12), 2, 8, 3);
        
        craft.print();
        cout << endl;
        inv.print();
        cout << endl;

        craft.move(inv[0], craft[0], 1);
        
        craft.print();
        cout << endl;
        inv.print();
        cout << endl;

        craft.move(inv[0], craft[8], 2);
        
        craft.print();
        cout << endl;
        inv.print();
        cout << endl;

        craft.crafting();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// g++ -o main main.cpp Craft.cpp ../Storage/Storage.cpp ../Inventory/Inventory.cpp ../Slot/Slot.cpp ../Recipe/Recipe.cpp