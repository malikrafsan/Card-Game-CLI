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

        void addItem(Item* item, string CRAFT_SLOT_ID, int quantity);
        Slot removeItem(string CRAFT_SLOT_ID, int quantity);
        friend ostream &operator<<( ostream &output, const Craft &craft);

        bool isCrfSlotValid(string CRAFT_SLOT_ID, int quantity);
        bool canBeAdded(Item* item, string CRAFT_SLOT_ID, int quantity);

        void crafting(); // TODO
};

#endif