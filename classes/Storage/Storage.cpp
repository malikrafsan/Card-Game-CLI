#include <iostream>
#include "Storage.hpp"
using namespace std;

Storage::Storage(){
    this->row = 0;
    this->col = 0;
    this->arr = new Slot[0];
}

Storage::Storage(int row, int col){
    this->row = row;
    this->col = col;
    this->arr = new Slot[row*col];
}

Storage::Storage(const Storage& storage){
    this->row = storage.row;
    this->col = storage.col;
    this->arr = new Slot[row*col];
    for (int i = 0; i < row*col; i++) {
        this->arr[i] = storage.arr[i];
    }
}

Storage& Storage::operator=(const Storage& storage){
    this->row = storage.row;
    this->col = storage.col;
    this->arr = new Slot[row*col];
    for (int i = 0; i < row*col; i++) {
        this->arr[i] = storage.arr[i];
    }
    return *this;
}

Storage::~Storage(){
    delete[] arr;
}

void Storage::move(Slot& src, Slot& dst, int quantity){
    Slot temp = src.remove(quantity);
    dst.add(temp);
}

Slot& Storage::operator[](int index){
    return this->arr[index];
}

Slot& Storage::operator[](string slotId){
    int idx = stoi(slotId.substr(1));
    return this->arr[idx];
}