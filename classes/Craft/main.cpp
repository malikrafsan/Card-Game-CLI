#include "Craft.hpp"
#include <iostream>
#include "../Inventory/Inventory.hpp"
#include "../Item/NonTool.hpp"
#include "../Item/Tool.hpp"
#include "../Item/TypedNonTool.hpp"

using namespace std;

void printDivider() {
    cout << "============================================" << endl;
}

void testCraftToolFailedBecauseNonToolExist() {
    Inventory inv;
    Craft craft;

    inv.addItem(new Tool(1, "Pickaxe", 10), "I1", 1);
    inv.addItem(new Tool(1, "Pickaxe", 10), "I2", 1);
    inv.addItem(new Tool(1, "Pickaxe", 10), "I3", 1);
    inv.addItem(new NonTool(2, "IniNonTool"), "I4", 5);

    cout << inv << endl;
    printDivider();

    for (int i = 0; i < 9; i++) {
        inv[1].getItem()->use();
    }
    for (int i=0;i<8;i++) {
        inv[2].getItem()->use();
    }
    for (int i=0;i<8;i++) {
        inv[3].getItem()->use();
    }

    cout << inv << endl;    
    printDivider();

    craft.move(inv[1], craft[1], 1);
    craft.move(inv[2], craft[2], 1);
    craft.move(inv[3], craft[3], 1);
    craft.move(inv[4], craft[4], 3);

    cout << craft << endl;
    cout << inv << endl;
    printDivider();

    Slot* res = craft.craft();
    // inv.move(*res, inv[0], 1);
    inv.addItem(res->getItem(), res->getQuantity());
    delete res;

    cout << craft << endl;
    cout << inv << endl;
    printDivider();
}

void testCraftToolFailedBecauseDifferentTool() {
    Inventory inv;
    Craft craft;

    inv.addItem(new Tool(1, "Pickaxe", 10), "I1", 1);
    inv.addItem(new Tool(2, "Axe", 10), "I2", 1);
    inv.addItem(new Tool(3, "Undefined", 10), "I3", 1);

    cout << inv << endl;
    printDivider();

    craft.move(inv[1], craft[1], 1);
    craft.move(inv[2], craft[2], 1);
    craft.move(inv[3], craft[3], 1);

    cout << inv << endl;
    cout << craft << endl;
    printDivider();

    Slot* res = craft.craft(); // Should throw an exception
    delete res;
    cout << "SHOULDNT BE PRINTED" << endl;
}

void testCraftToolSuccess() {
    Inventory inv;
    Craft craft;

    inv.addItem(new Tool(1, "Pickaxe", 10), "I1", 1);
    inv.addItem(new Tool(1, "Pickaxe", 10), "I2", 1);
    inv.addItem(new Tool(1, "Pickaxe", 10), "I3", 1);

    cout << inv << endl;
    printDivider();

    for (int i = 0; i < 9; i++) {
        inv[1].getItem()->use();
    }
    for (int i=0;i<8;i++) {
        inv[2].getItem()->use();
    }
    for (int i=0;i<8;i++) {
        inv[3].getItem()->use();
    }

    cout << inv << endl;    
    printDivider();

    craft.move(inv[1], craft[1], 1);
    craft.move(inv[2], craft[2], 1);
    craft.move(inv[3], craft[3], 1);

    cout << craft << endl;
    cout << inv << endl;
    printDivider();

    Slot* res = craft.craft();
    // inv.move(*res, inv[0], 1);
    inv.addItem(res->getItem(), res->getQuantity());
    delete res;

    cout << craft << endl;
    cout << inv << endl;
    printDivider();

    inv.addItem(new Tool(1, "Pickaxe", 10), "I1", 1);
    craft.move(inv[1], craft[1], 1);
    craft.move(inv[0], craft[0], 1);

    cout << craft << endl;
    printDivider();

    Slot* res2 = craft.craft();
    inv.addItem(res2->getItem(), res2->getQuantity());
    delete res2;

    cout << craft << endl;
    cout << inv << endl;
    printDivider();
}

int main() {
  try {
    Inventory inv;
    Craft craft;

    cout << craft << endl << inv << endl;

    inv.addItem(new NonTool(1, "Diamond"), "I10", 50);
    inv.addItem(new Tool(2, "Axe"), "I20", 5);
    inv.addItem(new TypedNonTool(3, "Birch Plank", "Plank"), "I26", 1);

    cout << craft << endl << inv << endl;

    craft.move(inv[10], craft[0], 1);

    cout << craft << endl << inv << endl;

    craft.move(inv[20], craft[1], 1);

    cout << craft << endl << inv << endl;

    // craft.crafting();
  } catch (const std::exception &e) {
    cout << e.what() << endl;
  }
  printDivider();
  printDivider();
  try {
    testCraftToolSuccess(); 
  } catch (const std::exception &e) {
    cout << "Exception: " << e.what() << endl;
  }
  try {
    testCraftToolFailedBecauseDifferentTool();
  } catch (const std::exception &e) {
    cout << "Exception: " << e.what() << endl;
  }
  try {
    testCraftToolFailedBecauseNonToolExist();
  } catch (const std::exception &e) {
    cout << "Exception: " << e.what() << endl;
  }
}

// g++ -o main main.cpp Craft.cpp ../Storage/Storage.cpp
// ../Inventory/Inventory.cpp ../Slot/Slot.cpp ../Recipe/Recipe.cpp