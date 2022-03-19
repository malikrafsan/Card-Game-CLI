#ifndef NONTOOL_HPP
#define NONTOOL_HPP

#include "Item.hpp"

class NonTool : public Item {
public:
    NonTool(int _id, string _name) : Item(_id, _name, false) {}

    pair<int, int> exportItem() const { return make_pair(id, -1); } // nggak bisa ngakses quantity
    // kayanya harus ditanganin di luar class item ?

    virtual NonTool *clone() const { 
        NonTool *clonedNonTool = new NonTool(*this);
        return clonedNonTool;
    }
};

class Stick : public NonTool {
public:
    Stick(int _id) : NonTool(_id, "Stick") {}
};

class IronIngot : public NonTool {
public:
    IronIngot(int _id) : NonTool(_id, "Iron Ingot") {}
};

class IronNugget : public NonTool {
public:
    IronNugget(int _id) : NonTool(_id, "Iron Nugget") {}
};

class Diamond : public NonTool {
public:
    Diamond(int _id) : NonTool(_id, "Diamond") {}
};

#endif