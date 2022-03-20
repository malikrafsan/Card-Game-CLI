#ifndef TYPEDNONTOOL_HPP
#define TYPEDNONTOOL_HPP

#include "NonTool.hpp"

class TypedNonTool : public NonTool {
protected:
    string type;
public:
    TypedNonTool() : NonTool(0, "none"), type("none") {}
    TypedNonTool(int _id, string _name, string _type) : NonTool(_id, _name), type(_type) {}
    TypedNonTool(const TypedNonTool& other) : NonTool(other) { type = other.type; }
    virtual string getType() const = 0;
    virtual void describe() const {
        Item::describe();
        cout << "Type : " << type << endl;
    }
};

class Stone : public TypedNonTool {
protected:
    string material;  // black atau cobble
public:
    Stone() : TypedNonTool(), material("none") {}
    Stone(int _id, string _material) : TypedNonTool(_id, _material + "STONE", "STONE"), material(_material) {}
    Stone(int _id, string _name, string _material) : TypedNonTool(_id, _name, "STONE"), material(_material) {}
    Stone(const Stone& other) : TypedNonTool(other) { material = other.material; }
    virtual string getType() const { return type; }
    void describe() const {
        TypedNonTool::describe();
        cout << "Material : " << material << endl;
    }
};

class Log : public TypedNonTool {
protected:
    string material;
public:
    Log() : TypedNonTool(), material("none") {}
    Log(int _id, string _material) : TypedNonTool(_id, _material + "_LOG", "LOG"), material(_material) {}
    Log(int _id, string _name, string _material) : TypedNonTool(_id, _name, "LOG"), material(_material) {}
    Log(const Log& other) : TypedNonTool(other) { material = other.material; }
    virtual string getType() const { return name; }
    void describe() const {
        TypedNonTool::describe();
        cout << "Material : " << material << endl;
    }
};

class Plank : public TypedNonTool {
protected:
    string material;
public:
    Plank() : TypedNonTool(), material("none") {}
    Plank(int _id, string _material) : TypedNonTool(_id, _material + "_PLANK", "PLANK"), material(_material) {}
    Plank(int _id, string _name, string _material) : TypedNonTool(_id, _name, "PLANK"), material(_material) {}
    Plank(const Plank& other) : TypedNonTool(other) { material = other.material; }
    virtual string getType() const { return type; }
    void describe() const {
        TypedNonTool::describe();
        cout << "Material : " << material << endl;
    }
};

#endif