#include <iostream>
#include "Slot.hpp"

Slot::Slot() {
    this->item = NULL;
    this->quantity = 0;
}

Slot::Slot(Item* item, int quantity) {
    this->item = item;
    this->quantity = quantity;
}

Slot::Slot(const Slot& slot) {
    this->item = slot.item;
    this->quantity = slot.quantity;
}

void Slot::operator=(const Slot& slot) {
    this->item = slot.item;
    this->quantity = slot.quantity;
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

Slot* Slot::remove(int qt) {
    if (this->quantity > qt) {
        this->quantity -= qt;
        return new Slot(this->item, qt);
    } else if (this->quantity == qt) {
        this->clear();
        return new Slot(this->item, qt);
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