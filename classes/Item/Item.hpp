#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
using namespace std;

class Item{
protected:
    const int id;
    const string name;
public:
    const bool isTool;  // true if item is a tool

    Item() : id(0), name("none"), isTool(false) {}
    Item(int _id, string _name, bool _isTool) : id(_id), name(_name), isTool(_isTool) {}
    Item(const Item& other) : id(other.id), name(other.name), isTool(other.isTool) {}
    
    int getId() const { return id; }

    virtual pair<int, int> exportItem() const = 0;    // Masih belum tau mau diimplementasi gimana
                                                // sementara ngereturn pair <int, int>

    virtual string getType() const { return name; }

    virtual void describe() const {
        cout << "Id : " << id << endl;
        cout << "Name : " << name << endl;
    }
};


#endif