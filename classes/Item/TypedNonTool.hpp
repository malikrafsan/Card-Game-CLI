#ifndef TYPEDNONTOOL_HPP
#define TYPEDNONTOOL_HPP

#include "NonTool.hpp"

class TypedNonTool : public NonTool {
protected:
    // type of the typed non tool
    string type;
public:
    // constructor
    TypedNonTool() : NonTool(0, "none"), type("none") {}
    
    // user defined constructor
    TypedNonTool(int _id, string _name, string _type) : NonTool(_id, _name), type(_type) {}
    
    // cctor
    TypedNonTool(const TypedNonTool& other) : NonTool(other) { type = other.type; }
    
    // get type of the typed non tool (for crafting)
    string getType() const { return this->type == "LOG" ? name : type; }

    // clone the typed non tool
    virtual TypedNonTool *clone() const { 
        TypedNonTool *clonedNonTool = new TypedNonTool(*this);
        return clonedNonTool;
    }
};

#endif