#ifndef NONTOOL_HPP
#define NONTOOL_HPP

#include "Item.hpp"

class NonToolUseExeption : public exception {
private:
    string _What;
public:
    NonToolUseExeption() : _What("Non-tool item cannot be used") {}
    const char *what() const throw() { return _What.c_str(); }
};

class NonTool : public Item {
public:
    // user defined constructor
    NonTool(int _id, string _name) : Item(_id, _name, false) {}
    
    // cctor
    NonTool(const NonTool &other) : Item(other) {}
    
    // clone the non tool
    virtual NonTool *clone() const { 
        NonTool *clonedNonTool = new NonTool(*this);
        return clonedNonTool;
    }

    // use the non tool (throw exception)
    virtual void use (){ throw NonToolUseExeption(); }
};

#endif