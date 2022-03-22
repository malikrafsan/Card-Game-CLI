#include <iostream>
#include <iomanip>
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
        return false;
    } else {
        int idx = stoi(CRAFT_SLOT_ID.substr(1));
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

Slot* Craft::craft() {
    Slot* craftTool = this->craftTool();

    if (craftTool != NULL) {
        return craftTool;
    }
    return this->craftNonTool();
}

Slot* Craft::craftTool() {
    vector<int> idxCrafted;
    int totalDurability = 0;

    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            Item* curItem = this->arr[(i * this->row) + j].getItem();

            if (curItem != NULL) {
                if (!curItem->isTool) {
                    return NULL;
                }

                Tool& tool = static_cast<Tool&>(*curItem);
                
                if (idxCrafted.empty()) {
                    idxCrafted.push_back((i * this->row) + j);
                    totalDurability += tool.getDurability();
                } else {
                    if (tool.getId() == this->arr[idxCrafted[0]].getItem()->getId()) {
                        idxCrafted.push_back((i * this->row) + j);
                        totalDurability += tool.getDurability();
                    } else {
                        return NULL;
                    }
                }
            }
        }
    }
    Item* item = this->arr[idxCrafted[0]].getItem();
    Tool* newTool = new Tool(item->getId(), item->getName(), totalDurability >= 10 ? 10 : totalDurability);

    Slot* res = new Slot(newTool, 1);

    for (int i = 0; i < idxCrafted.size(); i++) {
        this->arr[idxCrafted[i]].remove(1);
    }

    return res;
}

Slot* Craft::craftNonTool() {
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

    // TODO: create new Object
    if (0) {
        return new Slot();
    }
    throw CannotCraftExceptions();
}

ostream &operator<<( ostream &output, const Craft &craft) {
    output << "Craft:" << endl;
    for (int i = 0; i < craft.row; i++) {
        for (int j = 0; j < craft.col; j++) {
            int idx = i*craft.col + j;
            Item* temp = craft.arr[idx].getItem();
            string out;
            if (temp == NULL) {
                out = "[C" + to_string(idx) + "]";
                output << setw(27) << setfill(' ') << left << out;
            } else {
                if (temp->isTool) {
                    Tool &tool = static_cast<Tool&>(*temp);
                    out = "\033[34m[C" + to_string(idx) + ": " + tool.getName() + " (" + to_string(tool.getDurability()) + ")" + "]\033[0m";
                    output << setw(36) << setfill(' ') << left << out;
                } else {
                    out = "\033[32m[C" + to_string(idx) + ": " + temp->getName() + " " + to_string(craft.arr[idx].getQuantity()) + "]\033[0m";
                    output << setw(36) << setfill(' ') << left << out;
                }
            }
        }
        cout << endl;
    }
    return output;
}