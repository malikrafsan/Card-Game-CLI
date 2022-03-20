#ifndef CRAFT_H
#define CRAFT_H

#include "../Storage/Storage.hpp"
#include "../Recipe/Recipe.hpp"

class Craft : public Storage {
    private:
        vector<Recipe> recipes;
        map<int, Item*> mapItem;
        map<string, int> mapItemName;
        Slot* result;

    public:
        Craft();
        Craft(vector<Recipe> recipes, map<int, Item*> mapItem, map<string, int> mapItemName);

        void addItem(Item* item, int row, int col, int quantity);
        Slot removeItem(int row, int col, int quantity);
        void print() const;

        void crafting(); // TODO
};

#endif