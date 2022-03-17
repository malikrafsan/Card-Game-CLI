#include <iostream>
#include "Slot.hpp"
#include "../Item/Tool.hpp"
#include "../Item/NonTool.hpp"
using namespace std;

int main(){
    Slot slot1 = Slot(new Diamond(1), 1);
    Slot slot2 = Slot(new Diamond(1), 3);
    Slot slot3 = Slot(new Stick(2), 1);
    Slot temp;

    try
    {
        slot1.print();
        slot1.add(slot2);
        slot1.print();
        // slot1.add(new Diamond(1), 61);
        temp = slot1.remove(2);
        cout << "slot1:\n";
        slot1.print();
        cout << "temp:\n";
        temp.print();
        slot1.remove(2);
        slot1.print();
        slot1.add(slot3);
        slot1.print();
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
}

// g++ -o main main.cpp Slot.cpp