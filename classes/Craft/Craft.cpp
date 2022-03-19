#include <iostream>
#include "Craft.hpp"

Craft::Craft() : Storage(3,3) {}

Craft::Craft(vector<Recipe> recipes, map<int, Item*> mapItem, map<string, int> mapItemName) : Storage(3,3) {
    this->recipes = recipes;
    this->mapItem = mapItem;
    this->mapItemName = mapItemName;
}

void Craft::addItem(Item* item, int row, int col, int quantity) {
    this->arr[row*3 + col].add(item, quantity);
}

Slot Craft::removeItem(int row, int col, int quantity) {
    return this->arr[row*3 + col].remove(quantity);
}

void Craft::print() const {
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