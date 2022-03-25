#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
using namespace std;

class Item{
protected:
    // id of the item
    const int id;
    // name of the item
    const string name;
public:
    // true if item is a tool
    const bool isTool;  

    // constructor
    Item() : id(0), name("none"), isTool(false) {}

    // user defined constructor
    Item(int _id, string _name, bool _isTool) : id(_id), name(_name), isTool(_isTool) {}
    
    // cctor
    Item(const Item& other) : id(other.id), name(other.name), isTool(other.isTool) {}
    
    // get id of the item
    int getId() const { return id; }

    // get name of the item
    string getName() const { return name; }

    // use the item
    virtual void use() = 0;

    // get type or name of the item (for crafting)
    virtual string getType() const { return name; }

    // clone the item
    virtual Item *clone() const = 0;
};


#endif