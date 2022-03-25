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
  //! Constructor
  Craft();
  Craft(vector<Recipe> recipes, map<int, Item *> mapItem,
        map<string, int> mapItemName);

  //! Adding item to Craft
  void addItem(Item *item, string CRAFT_SLOT_ID, int quantity);
  //! Removing item from craft
  Slot removeItem(string CRAFT_SLOT_ID, int quantity);
  //! Showing items in Craft
  friend ostream &operator<<(ostream &output, const Craft &craft);

  //! Checking if Craft Slot valid
  bool isCrfSlotValid(string CRAFT_SLOT_ID, int quantity);
  //! Checking if Items can be added
  bool canBeAdded(Item *item, string CRAFT_SLOT_ID, int quantity);

  //! Method for crafting
  Slot *craftNonTool();
  Slot *craftTool();
  Slot *craft();
};

class CannotCraftExceptions : public exception {
public:
  const char *what() const throw() { return "Cannot Craft"; }
};

#endif