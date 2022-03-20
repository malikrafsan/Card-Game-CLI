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
    virtual void use() { durability--; }; 

    void describe() const {
        Item::describe();
        cout << "Material : " << material << endl;
        cout << "Durability : " << durability << endl;
    }

    pair<int, int> exportItem() const { return make_pair(id, durability); } // di nontool nggak bisa ngakses quantity

    // kayanya export harus ditanganin di luar class(?) pake getter durability
    int getDurability() const { return durability; }

    virtual Tool *clone() const { 
        Tool *clonedTool = new Tool(*this);
        return clonedTool;
    }
};

class Axe : public Tool {
public:
    Axe() : Tool() {}
    Axe(int _id, string _material) : Tool(_id, _material + "_AXE", _material) {}
    Axe(int _id, string _name, string _material) : Tool(_id, _name, _material) {}
};

class Sword : public Tool {
public:
    Sword() : Tool() {}
    Sword(int _id, string _material) : Tool(_id, _material + "_SWORD", _material) {}
    Sword(int _id, string _name, string _material) : Tool(_id, _name, _material) {}
};

class Pickaxe : public Tool {
public:
    Pickaxe() : Tool() {}
    Pickaxe(int _id, string _material) : Tool(_id, _material + "_PICKAXE", _material) {}
    Pickaxe(int _id, string _name, string _material) : Tool(_id, _name, _material) {}
};


#endif