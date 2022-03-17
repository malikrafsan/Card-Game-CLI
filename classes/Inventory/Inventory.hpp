#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "../Storage/Storage.hpp"

class Inventory : public Storage {
    public:
        Inventory();

        void addItem(Item* item, int row, int col, int quantity);
        Slot removeItem(int row, int col, int quantity);
        void print() const;
};

#endif