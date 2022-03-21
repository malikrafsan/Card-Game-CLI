#ifndef CRAFT_H
#define CRAFT_H

#include "../Recipe/Recipe.hpp"
#include "../Storage/Storage.hpp"

class Craft : public Storage {
private:
  vector<Recipe> recipes;
  map<int, Item *> mapItem;
  map<string, int> mapItemName;

public:
  Craft();
  Craft(vector<Recipe> recipes, map<int, Item *> mapItem,
        map<string, int> mapItemName);

  void addItem(Item *item, string CRAFT_SLOT_ID, int quantity);
  Slot removeItem(string CRAFT_SLOT_ID, int quantity);
  friend ostream &operator<<(ostream &output, const Craft &craft);

  bool isCrfSlotValid(string CRAFT_SLOT_ID, int quantity);
  bool canBeAdded(Item *item, string CRAFT_SLOT_ID, int quantity);

  Slot *craftNonTool();
  Slot *craftTool();
  Slot *craft();
};

class CannotCraftExceptions : public exception {
public:
  const char *what() const throw() { return "Cannot Craft"; }
};

#endif