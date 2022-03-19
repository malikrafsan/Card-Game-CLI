#include <iostream>
#include "Craft.hpp"

Craft::Craft() : Storage(3,3) {}

Craft::Craft(vector<Recipe> recipes) : Storage(3,3) {
    this->recipes = recipes;
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
    int rowRecipe, colRecipe, rowCraft, colCraft;
    int i = 0;
    bool found = false;

    for (i = 0; i < this->recipes.size(); i++) {
        rowRecipe = this->recipes[i].getRow();
        colRecipe = this->recipes[i].getCol();
        rowCraft = 0;
        colCraft = 0;

        cout << rowRecipe << colRecipe << rowCraft << endl;
        while (rowCraft + rowRecipe <= this->row && colCraft + colRecipe <= this->col)
        {
            
        }

    }
}