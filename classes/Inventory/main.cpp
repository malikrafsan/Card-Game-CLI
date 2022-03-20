#include <iostream>
#include "Inventory.hpp"
#include "../Item/NonTool.hpp"
#include "../Item/Tool.hpp"
using namespace std;

int main(){
    try
    {
        Inventory inventory;
        inventory.print();
        cout << endl;
        // Slot temp = inventory.removeItem(0, 0, 1);
        inventory.addItem(new Diamond(1), 0, 0, 1);
        inventory.print();
        cout << endl;
        inventory.addItem(new Stick(2), 2, 7, 5);
        inventory.print();
        cout << endl;
        inventory.addItem(new IronIngot(3), 1, 1, 1);
        inventory.print();
        cout << endl;

        
        inventory.addItem(new Axe(4, "Wood"), 1);
        inventory.print();
        cout << endl;

        inventory.addItem(new Sword(5, "Wood"), 1);
        inventory.print();
        cout << endl;

        inventory.use("I2");
        inventory.remove("I1", 1);
        inventory.print();
        cout << endl;

    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
}

// g++ -o main main.cpp Inventory.cpp ../Storage/Storage.cpp ../Slot/Slot.cpp