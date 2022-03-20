#include <iostream>
#include "Craft.hpp"

Craft::Craft() : Storage(3,3) {}

Craft::Craft(vector<Recipe> recipes, map<int, Item*> mapItem, map<string, int> mapItemName) : Storage(3,3) {
    this->recipes = recipes;
    this->mapItem = mapItem;
    this->mapItemName = mapItemName;
}

void Craft::addItem(Item* item, string CRAFT_SLOT_ID, int quantity) {
    if (CRAFT_SLOT_ID[0] != 'C') {
        throw InvalidIDSlotException();
    } else {
        int idx = stoi(CRAFT_SLOT_ID.substr(1));
        if (idx < 0 || idx >= this->row*this->col) {
            throw InvalidIDSlotException();
        } else {
            this->arr[idx].add(item, quantity);
        }
    }
}

Slot Craft::removeItem(string CRAFT_SLOT_ID, int quantity) {
    if (CRAFT_SLOT_ID[0] != 'C') {
        throw InvalidIDSlotException();
    } else {
        int idx = stoi(CRAFT_SLOT_ID.substr(1));
        if (idx < 0 || idx >= this->row*this->col) {
            throw InvalidIDSlotException();
        } else {
            return this->arr[idx].remove(quantity);
        }
    }
}

bool Craft::isCrfSlotValid(string CRAFT_SLOT_ID, int quantity) {
    if (CRAFT_SLOT_ID[0] != 'C') {
        throw InvalidIDSlotException();
    } else {
        int idx = stoi(CRAFT_SLOT_ID.substr(1));
        if (idx < 0 || idx >= this->row*this->col) {
            throw InvalidIDSlotException();
        } else {
            if (this->arr[idx].getItem() == NULL) {
                return true;
            } else {
                return (this->arr[idx].getItem()->getId() == quantity);
            }
        }
    }
}

bool Craft::canBeAdded(Item* item, string CRAFT_SLOT_ID, int quantity) {
    if (CRAFT_SLOT_ID[0] != 'C') {
        return false;
    } else {
        int idx = stoi(CRAFT_SLOT_ID.substr(1));
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

void Craft::crafting() {
    int rowRecipe, colRecipe, rowCraft, colCraft, ii, jj;
    int i = -1;
    bool found = false;
    bool out = false;
    string itemCrafted;

    while (i < this->recipes.size()) {
        rowRecipe = this->recipes[i].getRow();
        colRecipe = this->recipes[i].getCol();
        rowCraft = 0;
        colCraft = 0;

        while (rowCraft + rowRecipe <= this->row && !found) {
            while (colCraft + colRecipe <= this->col && !found) {
                jj = 0;
                while (jj <= this->row && !found && !out) {
                    ii = 0;
                    while (ii < this->col && !found && !out) {
                        if (ii < rowCraft || ii > rowCraft + rowRecipe || jj < colCraft || jj > colCraft + colRecipe) {
                            if (this->arr[ii*this->col + jj].getItem() != NULL) {
                                out = true;
                            }
                        }
                        else {
                            if (this->arr[ii*this->col + jj].getItem()->getType() != recipes[i].getItems()[(ii-rowCraft)*this->col + (jj-colCraft)]) {
                                out = true;
                            }
                        }
                        
                        if (ii == this->row - 1 && jj == this->col - 1 && !out) {
                            found = true;
                        }
                        ii++;
                    }
                    jj++;
                }
                colCraft++;
            }
            rowCraft++;
        }
        i++;
    }

    i--;
    if (found) {
        for (ii = 0; ii < this->row; ii++) {
            for (jj = 0; jj < this->col; jj++) {
                this->arr[ii*this->col + jj].remove(1);

            }
        }
    }
}

ostream &operator<<( ostream &output, const Craft &craft) {
    for (int i = 0; i < craft.row; i++) {
        for (int j = 0; j < craft.col; j++) {
            if (craft.arr[i*craft.col + j].getItem() == NULL) {
                cout << "\t[C" << i*craft.col + j << "]\t";
            } else {
                cout << "\t[C" << i*craft.col + j << ": " << craft.arr[i*craft.col + j].getItem()->getId();
                cout << "," << craft.arr[i*craft.col + j].getQuantity() << "]";
            }
        }
        cout << endl;
    }
    return output;
}