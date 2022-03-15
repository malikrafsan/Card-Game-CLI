#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
using namespace std;

class Item{
protected:
    const int id;
    const string name;
public:
    Item() : id(0), name("none") {}
    Item(int _id, string _name) : id(_id), name(_name) {}
    Item(const Item& other) : id(other.id), name(other.name) {}
    
    int getId() const { return id; }

    virtual pair<int, int> exportItem() const = 0;    // Masih belum tau mau diimplementasi gimana
                                                // sementara ngereturn pair <int, int>

    virtual string getType() const { return name; }

    virtual void describe() const {
        cout << "Id : " << id << endl;
        cout << "Name : " << name << endl;
    }
};


#endif