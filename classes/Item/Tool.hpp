#ifndef TOOL_HPP
#define TOOL_HPP

#include "Item.hpp"

class Tool : public Item {
protected:
    string material;
    int durability;
public:
    Tool() : Item(), durability(-1), material("none") {}
    Tool(int _id, string _name, string _material) : Item(_id, _name, true), durability(10), material(_material) {}
    Tool(const Tool& other) : Item(other) { material = other.material; durability = other.durability; }
    void use() { durability--; }; 

    void describe() const {
        Item::describe();
        cout << "Material : " << material << endl;
        cout << "Durability : " << durability << endl;
    }

    int getDurability() const { return durability; }

    Tool *clone() const { 
        Tool *clonedTool = new Tool(*this);
        return clonedTool;
    }
};


#endif