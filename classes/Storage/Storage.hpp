#ifndef STORAGE_H
#define STORAGE_H

#include "../Slot/Slot.hpp"
#include <map>

class Storage {
    protected:
        int row;
        int col;
        Slot* arr;

    public:
        //! Constructor
        Storage();
        Storage(int row, int col);
        //! Copy constructor
        Storage(const Storage& storage);
        //! Assignment operator
        Storage& operator=(const Storage& storage);
        //! Destructor
        ~Storage();

        //! Moving one slot to another slot
        void move(Slot& src, Slot& dst, int quantity);
        //! Getter slot depend on index or id
        Slot& operator[](int index);
        Slot& operator[](string slotId);

        //! Adding item to derived class
        virtual void addItem(Item* item, string SLOT_ID, int quantity) = 0;
        //! Removing item from derived class
        virtual Slot removeItem(string SLOT_ID, int quantity) = 0;
        //! Checking if Items can be added
        virtual bool canBeAdded(Item* item, string INV_SLOT_ID, int quantity) = 0;
};

class InvalidIDSlotException : public exception {
    public:
        const char *what() const throw() {
            return "Invalid Slot ID";
        }
};

#endif