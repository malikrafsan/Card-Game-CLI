#ifndef CRAFT_H
#define CRAFT_H

#include "../Storage/Storage.hpp"
#include "../Recipe/Recipe.hpp"

class Craft : public Storage {
    private:
        vector<Recipe> recipes;
        Slot* result;

    public:
        Craft();
        Craft(vector<Recipe> recipes);

        void addItem(Item* item, int row, int col, int quantity);
        Slot removeItem(int row, int col, int quantity);
        void print() const;

        void crafting(); // TODO
};

#endif