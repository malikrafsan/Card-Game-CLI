#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "../Storage/Storage.hpp"

class Inventory : public Storage {
    public:
        //! Constructor
        Inventory();

        //! Adding item to Inventory
        void give(Item* item, int quantity);
        void addItem(Item* item, string INV_SLOT_ID, int quantity);
        //! Removing item from Inventory
        Slot removeItem(string INV_SLOT_ID, int quantity);
        //! Showing items in Inventory
        friend ostream &operator<<( ostream &output, const Inventory &inventory);

        //! Use a tool item
        void use(string INV_SLOT_ID);
        //! Remove item from Inventory
        void remove(string INV_SLOT_ID, int quantity);

        //! Checking if Inventory Slot valid
        bool isInvSlotValid(string INV_SLOT_ID, int quantity);
        //! Checking if Items can be added
        bool canBeAdded(Item* item, string INV_SLOT_ID, int quantity);
        //! Export inventory
        vector<string> exportInventory();
};

#endif