#ifndef TYPEDNONTOOL_HPP
#define TYPEDNONTOOL_HPP

#include "NonTool.hpp"
// TypedNonTool.hpp
class TypedNonTool : public NonTool {
protected:
    string type;
public:
    TypedNonTool() : NonTool(0, "none"), type("none") {}
    TypedNonTool(int _id, string _name, string _type) : NonTool(_id, _name), type(_type) {}
    TypedNonTool(const TypedNonTool& other) : NonTool(other) { type = other.type; }
    string getType() const { return this->type == "LOG" ? name : type; }


    virtual TypedNonTool *clone() const { 
        TypedNonTool *clonedNonTool = new TypedNonTool(*this);
        return clonedNonTool;
    }
};

#endif