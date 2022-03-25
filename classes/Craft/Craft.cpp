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

    for (int i = 0; i < idxCrafted.size(    ); i++) {
        this->arr[idxCrafted[i]].remove(1);
    }

    return res;
}

Slot* Craft::craftNonTool() {
    int rowRecipe, colRecipe, rowCraft, colCraft, ii, jj, lowest, id;
    int i = 0;
    bool found = false;
    bool out = false;
    bool flipped = false;
    Item* newItem;
    Slot* newItemSlot;
    string itemCraftedName;

    while (i < this->recipes.size() && !found) {
        rowRecipe = this->recipes[i].getRow()-1;
        colRecipe = this->recipes[i].getCol()-1;
        rowCraft = 0;
        colCraft = 0;

        while (rowCraft + rowRecipe <= this->row-1 && !found) {
            while (colCraft + colRecipe <= this->col-1 && !found) {
                jj = 0;
                while (jj <= this->col-1 && !found && !out) {
                    ii = 0;
                    while (ii <= this->row-1 && !found && !out) {
                        if (ii < rowCraft || ii > rowCraft + rowRecipe || jj < colCraft || jj > colCraft + colRecipe) {
                            if (this->arr[ii*this->col + jj].getItem() != NULL) {
                                out = true;
                            }
                        }
                        else {
                            if (recipes[i].getItems()[(ii-rowCraft)*this->col + (jj-colCraft)] == "-" && this->arr[ii*this->col + jj].getItem() != NULL) {
                                out = true;
                            }
                            else if (this->arr[ii*this->col + jj].getItem() == NULL) {
                                    out = true;
                                }
                            else if (this->arr[ii*this->col + jj].getItem()->getType() != recipes[i].getItems()[(ii-rowCraft)*this->col + (jj-colCraft)]) {
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
                out = false;
                colCraft++;
            }
            rowCraft++;
        }
        i++;
    }

    ii--;
    jj--;
    colCraft--;
    rowCraft--;
    i--;

    if (!found) {
        i = 0;
        while (i < this->recipes.size() && !found) {
            rowRecipe = this->recipes[i].getRow()-1;
            colRecipe = this->recipes[i].getCol()-1;
            rowCraft = 0;
            colCraft = this->col-1;

            while (rowCraft + rowRecipe <= this->row-1 && !found) {
                while (colCraft - colRecipe >= 0 && !found) {
                    jj = this->col-1;
                    while (jj >= 0 && !found && !out) {
                        ii = 0;
                        while (ii <= this->row-1 && !found && !out) {
                            if (ii < rowCraft || ii > rowCraft + rowRecipe || jj > colCraft || jj < colCraft - colRecipe) {
                                if (this->arr[ii*this->col + jj].getItem() != NULL) {
                                    out = true;
                                }
                            }
                            else {
                                if (recipes[i].getItems()[(ii-rowCraft)*this->col + (colCraft-jj)] == "-" && this->arr[ii*this->col + jj].getItem() != NULL) {
                                    out = true;
                                }
                                else if (this->arr[ii*this->col + jj].getItem() == NULL) {
                                    out = true;
                                }
                                else if (this->arr[ii*this->col + jj].getItem()->getType() != recipes[i].getItems()[(ii-rowCraft)*this->col + (colCraft-jj)]) {
                                    out = true;
                                }
                            }
                            
                            if (ii == this->row - 1 && jj == 0 && !out) {
                                found = true;
                                flipped = true;
                            }
                            ii++;
                        }
                        jj--;
                    }
                    colCraft--;
                }
                rowCraft++;
            }
            i++;
        }
    }

    i--;
    if (found) {
        lowest = 65;
        itemCraftedName =  recipes[i].getResult();
        for (ii = 0; ii < this->row; ii++) {
            for (jj = 0; jj < this->col; jj++) {
                if (this->arr[ii*this->col + jj].getItem() != NULL && this->arr[ii*this->col + jj].getQuantity() < lowest) {
                    lowest = this->arr[ii*this->col + jj].getQuantity();
                }
            }
        }

        for (ii = 0; ii < this->row; ii++) {
            for (jj = 0; jj < this->col; jj++) {
                if (this->arr[ii*this->col + jj].getItem() != NULL) {
                    this->arr[ii*this->col + jj].remove(lowest);
                }
            }
        }

        id = mapItemName[itemCraftedName];
        newItem = mapItem[id]->clone();
        newItemSlot = new Slot(newItem, lowest*recipes[i].getResultQty());

        return newItemSlot;
    }
    else{
        throw CannotCraftExceptions();
    }
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