#include <iostream>
#include "Inventory.hpp"

Inventory::Inventory() : Storage(3,9) {}

void Inventory::addItem(Item* item, int row, int col, int quantity) {
    this->arr[row*9 + col].add(item, quantity);
}

Slot Inventory::removeItem(int row, int col, int quantity) {
    return this->arr[row*9 + col].remove(quantity);
}

void Inventory::print() const {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            if (this->arr[i*this->col + j].getItem() == NULL) {
                cout << "\t[]";
            } else {
                cout << "\t[" << this->arr[i*this->col + j].getItem()->getId();
                cout << "," << this->arr[i*this->col + j].getQuantity() << "]";
            }
        }
        cout << endl;
    }
}