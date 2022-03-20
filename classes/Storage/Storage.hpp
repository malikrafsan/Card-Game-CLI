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

        // pure virtual function
        virtual void addItem(Item* item, int row, int col, int quantity) = 0;
        virtual Slot removeItem(int row, int col, int quantity) = 0;
        virtual void print() const = 0;
        
        // TODO : menambahkan validitas untuk command MOVE I0 N C1 C2 ... CN
};

#endif