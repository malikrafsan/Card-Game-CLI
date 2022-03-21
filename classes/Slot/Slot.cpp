#include <iostream>
#include "Slot.hpp"

Slot::Slot() {
    this->item = NULL;
    this->quantity = 0;
}

Slot::Slot(Item* item, int quantity) {
    this->item = item->clone();
    this->quantity = quantity;
}

Slot::Slot(const Slot& slot) {
    this->item = slot.item->clone();
    this->quantity = slot.quantity;
}

Slot& Slot::operator=(const Slot& slot) {
    this->item = slot.item->clone();
    this->quantity = slot.quantity;
    return *this;
}

Slot::~Slot() {
    delete item;
}

Item* Slot::getItem() const {
    return item;
}

int Slot::getQuantity() const {
    return quantity;
}

void Slot::add(Item* item, int qt) {
    if (item == NULL){
        throw SlotEmptyException();
    }
    
    if (this->item == NULL) {
        this->item = item->clone();
        this->quantity = qt;
        return;
    }

    if (this->item->getId() == item->getId()) {
        if (this->item->isTool) {
            throw ToolItemStackedException();
        } else {
            if (this->quantity + qt > 64) {
                throw SlotFullException();
            } else {
                this->quantity += qt;
            }
        }
    } else {
        throw ItemMismatchException();
    }
}

void Slot::add(Slot& slot) {
    if (slot.item == NULL)
        throw SlotEmptyException();
    
    if (this->item == NULL) {
        this->item = slot.item->clone();
        this->quantity = slot.getQuantity();
        return;
    }

    if (this->item->getId() == slot.item->getId()) {
        if (this->item->isTool) {
            throw ToolItemStackedException();
        } else {
            if (this->quantity + slot.getQuantity() > 64) {
                throw SlotFullException();
            } else {
                this->quantity += slot.getQuantity();
            }
        }
    } else {
        throw ItemMismatchException();
    }
}

Slot Slot::remove(int qt) {
    if (this->quantity > qt) {
        this->quantity -= qt;
        return Slot(this->item->clone(), qt);
    } else if (this->quantity == qt) {
        Slot res =  Slot(this->item->clone(), qt);
        this->clear();
        return res;
    } else {
        throw ItemNotEnoughException();
    }
}

void Slot::clear() {
    this->item = NULL;
    this->quantity = 0;
}

void Slot::print() const {
    if (this->item != NULL) {
        cout << "Id : " << item->getId() << endl;
        cout << "Quantity : " << quantity << endl;
    } else {
        cout << "Slot is empty" << endl;
    }
}

string Slot::exportItem() const {
    if (this->item != NULL) {
        if (this->item->isTool) {
            Tool &tool = static_cast<Tool&>(*this->item);
            return to_string(this->item->getId()) + ":" + to_string(tool.getDurability());
        } else {
            return to_string(this->item->getId()) + ":" + to_string(this->quantity);
        }
    } else {
        return "0:0";
    }
}