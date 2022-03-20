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
        Storage();
        Storage(int row, int col);
        Storage(const Storage& storage);
        Storage& operator=(const Storage& storage);
        ~Storage();

        void move(Slot& src, Slot& dst, int quantity);
        Slot& operator[](int index);
        Slot& operator[](string slotId);

        // pure virtual function
        virtual void addItem(Item* item, string SLOT_ID, int quantity) = 0;
        virtual Slot removeItem(string SLOT_ID, int quantity) = 0;
        virtual bool canBeAdded(Item* item, string INV_SLOT_ID, int quantity) = 0;
        
        // TODO : menambahkan validitas untuk command MOVE I0 N C1 C2 ... CN
};

class InvalidIDSlotException : public exception {
    public:
        const char *what() const throw() {
            return "Invalid Slot ID";
        }
};

#endif