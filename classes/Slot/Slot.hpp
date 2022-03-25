#ifndef SLOT_H
#define SLOT_H

#include "../Item/Item.hpp"
#include "../Item/Tool.hpp"

class Slot {
    private:
        Item* item;
        int quantity;

    public:
        //! Constructor
        Slot();
        Slot(Item* item, int quantity);
        //! Copy constructor
        Slot(const Slot& slot);
        //! Assignment operator
        Slot& operator=(const Slot& slot);
        //! Destructor
        ~Slot();

        //! Getter
        Item* getItem() const;
        int getQuantity() const;

        //! Adding item to slot
        void add(Item* item, int qt);
        void add(Slot& slot);
        //! Removing item from slot
        Slot remove(int qt);
        //! Clearing slot
        void clear();
        //! Export slot
        string exportItem() const;
};

class ItemMismatchException : public exception {
    public:
        const char *what() const throw() {
            return "This item has different id";
        }
};

class ItemNotEnoughException : public exception {
    public:
        const char *what() const throw() {
            return "This item has not enough quantity";
        }
};

class SlotEmptyException : public exception {
    public:
        const char *what() const throw() {
            return "This slot is empty";
        }
};

class SlotFullException : public exception {
    public:
        const char *what() const throw() {
            return "This item can't be stacked more than 64";
        }
};

class ToolItemStackedException : public exception {
    public:
        const char *what() const throw() {
            return "Tool item can't be stacked";
        }
};

class InvalidQuantityException : public exception {
    public:
        const char *what() const throw() {
            return "Quantity must be greater than 0";
        }
};

#endif