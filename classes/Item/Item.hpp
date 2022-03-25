#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
using namespace std;
// Item.hpp
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
    string getName() const { return name; }

    virtual void use() = 0;

    virtual string getType() const { return name; }

    virtual Item *clone() const = 0;
};


#endif