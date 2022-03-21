#ifndef TOOL_HPP
#define TOOL_HPP

#include "Item.hpp"
// Tool.hpp
class Tool : public Item {
protected:
    int durability;
public:
    Tool() : Item(), durability(-1) {}
    Tool(int _id, string _name) : Item(_id, _name, true), durability(10) {}
    Tool(int _id, string _name, int durability) : Item(_id, _name, durability), durability(durability) {}
    Tool(const Tool& other) : Item(other) { durability = other.durability; }
    void use() { durability--; }; 

    void describe() const {
        Item::describe();
        cout << "Durability : " << durability << endl;
    }

    int getDurability() const { return durability; }

    Tool *clone() const { 
        Tool *clonedTool = new Tool(*this);
        return clonedTool;
    }
};


#endif