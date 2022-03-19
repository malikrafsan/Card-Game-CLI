#include <iostream>
#include "Inventory.hpp"

Inventory::Inventory() : Storage(3,9) {}

void Inventory::addItem(Item* item, int quantity) {
    int idx = -1;

    for (int i = 0; i < this->row*this->col; i++) {
        if (this->arr[i].getItem() != NULL){
            if (this->arr[i].getItem()->getId() == item->getId()) {
                // Menambahkan item nontool
                if (!this->arr[i].getItem()->isTool && this->arr[i].getQuantity() + quantity < 64) {
                    this->arr[i].add(item, quantity);
                    return;
                }
            }
        } else {
            if (idx == -1)
                idx = i;
        }
    }
    
    if (idx == -1){
        throw InventoryFullException();
    } else {
        this->arr[idx].add(item, quantity);
    }
}

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

void Inventory::use(string INV_SLOT_ID) {
    int idx = stoi(INV_SLOT_ID.substr(1));
    if (this->arr[idx].getItem() != NULL) {
        if (this->arr[idx].getItem()->isTool) {
            Tool *tool = static_cast<Tool*>(this->arr[idx].getItem());
            tool->use();
        } else {
            // TODO : bikin exception di item atau di sini?
            // throw NotAToolException();
        }
    } else {
        throw SlotEmptyException();
    }
}

void Inventory::remove(string INV_SLOT_ID, int quantity) {
    int idx = stoi(INV_SLOT_ID.substr(1));
    this->arr[idx].remove(quantity);
}

vector<string> Inventory::exportInventory() {
    vector<string> result;
    for (int i=0; i< this->row*this->col; i++){
        result.push_back(this->arr[i].exportItem());
        cout << result[i] << endl;
    }
    return result;
}