#ifndef TOOL_HPP
#define TOOL_HPP

#include "Item.hpp"
// Tool.hpp
class Tool : public Item {
protected:
    //! durability of the tool
    int durability;
public:
    //! constructor
    Tool() : Item(), durability(-1) {}
    //! user defined constructor
    Tool(int _id, string _name) : Item(_id, _name, true), durability(10) {}
    //! cctor
    Tool(int _id, string _name, int durability) : Item(_id, _name, durability), durability(durability) {}
    //! cctor
    Tool(const Tool& other) : Item(other) { durability = other.durability; }
    
    //! use the tool
    void use() { durability--; }; 

    //! get durability of the tool
    int getDurability() const { return durability; }

    //! clone the tool
    Tool *clone() const { 
        Tool *clonedTool = new Tool(*this);
        return clonedTool;
    }
};


#endif