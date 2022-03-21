#include <iostream>
#include "Inventory.hpp"

Inventory::Inventory() : Storage(3,9) {}

void Inventory::give(Item* item, int quantity) {
    if (item == NULL)
        throw SlotEmptyException();

    if (quantity <= 0)
        throw InvalidQuantityException();

    if (item->isTool) {
        int i = 0;
        while (i < this->row*this->col && quantity > 0) {
            if (this->arr[i].getItem() == NULL) {
                this->arr[i].add(item,1);
                quantity--;
            }
            i++;
        }
    } else {
        int idx = -1, i = 0;
        while (i < this->row*this->col && quantity > 0) {
            if (this->arr[i].getItem() == NULL) {
                if (idx == -1)
                    idx = i;
            } else {
                if (this->arr[i].getItem()->getId() == item->getId()) {
                    int quantityAvailable = 64 - this->arr[i].getQuantity();
                    if (quantity <= quantityAvailable) {
                        this->arr[i].add(item, quantity);
                        quantity = 0;
                    } else {
                        this->arr[i].add(item, quantityAvailable);
                        quantity -= quantityAvailable;
                    }
                }
            }
            i++;
        }

        if (quantity >= 0 && idx == -1)
            return;
        
        if (idx == -1)
            return;

        i = 0;
        while (quantity > 0 && i < this->row*this->col) {
            if (this->arr[i].getItem() == NULL) {
                if (quantity > 64) {
                    this->arr[i].add(item, 64);
                    quantity -= 64;
                } else {
                    this->arr[i].add(item, quantity);
                    quantity = 0;
                }
            }
            i++;
        }
    }
}

void Inventory::addItem(Item* item, string INV_SLOT_ID, int quantity) {
    if (INV_SLOT_ID[0] != 'I') {
        throw InvalidIDSlotException();
    } else {
        int idx = stoi(INV_SLOT_ID.substr(1));
        if (idx < 0 || idx >= this->row*this->col) {
            throw InvalidIDSlotException();
        } else {
            this->arr[idx].add(item, quantity);
        }
    }
}

Slot Inventory::removeItem(string INV_SLOT_ID, int quantity) {
    if (INV_SLOT_ID[0] != 'I') {
        throw InvalidIDSlotException();
    } else {
        int idx = stoi(INV_SLOT_ID.substr(1));
        if (idx < 0 || idx >= this->row*this->col) {
            throw InvalidIDSlotException();
        } else {
            return this->arr[idx].remove(quantity);
        }
    }
}

void Inventory::use(string INV_SLOT_ID) {
    if (INV_SLOT_ID[0] != 'I') {
        throw InvalidIDSlotException();
    } else {
        int idx = stoi(INV_SLOT_ID.substr(1));
        if (idx < 0 || idx >= this->row*this->col) {
            throw InvalidIDSlotException();
        } else {
            if (this->arr[idx].getItem() != NULL) {
                Tool &tool = static_cast<Tool&>(*this->arr[idx].getItem());
                tool.use();
                if (tool.getDurability() == 0) {
                    this->arr[idx].remove(1);
                }
            } else {
                throw SlotEmptyException();
            }
        }
    }
}

void Inventory::remove(string INV_SLOT_ID, int quantity) {
    if (INV_SLOT_ID[0] != 'I') {
        throw InvalidIDSlotException();
    } else {
        int idx = stoi(INV_SLOT_ID.substr(1));
        if (idx < 0 || idx >= this->row*this->col) {
            throw InvalidIDSlotException();
        } else {
            this->arr[idx].remove(quantity);
        }
    }
}

vector<string> Inventory::exportInventory() {
    vector<string> result;
    for (int i=0; i< this->row*this->col; i++){
        result.push_back(this->arr[i].exportItem());
        cout << result[i] << endl;
    }
    return result;
}

bool Inventory::isInvSlotValid(string INV_SLOT_ID, int quantity) {
    if (INV_SLOT_ID[0] != 'I') {
        return false;
    } else {
        int idx = stoi(INV_SLOT_ID.substr(1));
        if (idx < 0 || idx >= this->row*this->col) {
            throw InvalidIDSlotException();
        } else {
            if (this->arr[idx].getItem() != NULL) {
                return (this->arr[idx].getQuantity() >= quantity);
            } else {
                return false;
            }
        }
    }
}

bool Inventory::canBeAdded(Item* item, string INV_SLOT_ID, int quantity) {
    if (INV_SLOT_ID[0] != 'I') {
        return false;
    } else {
        int idx = stoi(INV_SLOT_ID.substr(1));
        if (idx >= 0 && idx < this->row*this->col) {
            if (this->arr[idx].getItem() != NULL) {
                if (this->arr[idx].getItem()->getId() == item->getId()) {
                    return (!this->arr[idx].getItem()->isTool && this->arr[idx].getQuantity() + quantity <= 64);
                } else {
                    return false;
                }
            } else {
                return true;
            }
        } else {
            throw InvalidIDSlotException();
        }
    }
}

ostream &operator<<( ostream &output, const Inventory &inventory) {
    output << "Inventory:" << endl;
    for (int i = 0; i < inventory.row; i++) {
        for (int j = 0; j < inventory.col; j++) {
            int idx = i*inventory.col + j;
            Item* temp = inventory.arr[idx].getItem();
            if (temp == NULL) {
                output << "[I" << idx << "]\t\t\t";
            } else {
                if (temp->isTool) {
                    Tool &tool = static_cast<Tool&>(*temp);
                    string out = "\033[31m[I" + to_string(idx) + ": " + tool.getName() + " (" + to_string(tool.getDurability()) + ")" + "]\033[0m\t";

                    if (out.length() < 27)
                        out += "\t";
                    output << out;
                } else {
                    string out = "\033[32m[I" + to_string(idx) + ": " + temp->getName() + " " + to_string(inventory.arr[idx].getQuantity()) + "]\033[0m\t";
                    if (out.length() < 27)
                        out += "\t";
                    output << out;
                }
            }
        }
        output << endl;
    }
    return output;
}