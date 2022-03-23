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
// NonTool.hpp
class NonTool : public Item {
public:
    NonTool(int _id, string _name) : Item(_id, _name, false) {}
    NonTool(const NonTool &other) : Item(other) {}
    virtual NonTool *clone() const { 
        NonTool *clonedNonTool = new NonTool(*this);
        return clonedNonTool;
    }

    virtual void use (){ throw NonToolUseExeption(); }
};

#endif