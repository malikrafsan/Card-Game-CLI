#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "../Storage/Storage.hpp"

class Inventory : public Storage {
    public:
        Inventory();

        void addItem(Item* item, int quantity);
        void addItem(Item* item, int row, int col, int quantity);
        Slot removeItem(int row, int col, int quantity);
        void print() const;

        void use(string INV_SLOT_ID);
        void remove(string INV_SLOT_ID, int quantity);
        vector<string> exportInventory();
};

class InventoryFullException : public exception {
    public:
        const char *what() const throw() {
            return "This inventory is full";
        }
};

#endif