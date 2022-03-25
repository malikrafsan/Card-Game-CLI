#include "../classes/FileManager/FileManager.hpp"
#include "../classes/Recipe/Recipe.hpp"
#include <iostream>  
#include <sstream>
#include <map>

int main() {
  FileManager fm;

  try {
    vector<Recipe> recipes2;
    const string recipesPath = "../config/recipe";
    const string itemPath = "../config/item.txt";
    map<string, pair<int, bool>> itemId;
    int counter = 1;

    vector<vector<string>> files = fm.readFiles(recipesPath);
    for (int i = 0; i < files.size(); i++) {
      recipes2.push_back(Recipe(files[i]));
    }

    vector<string> items = fm.readFile(itemPath);
    for (int i = 0; i < items.size(); i++) {
      stringstream ss(items[i]);
      int id;
      string name, type, isTool;
      ss >> id;
      ss >> name;
      ss >> type;
      ss >> isTool;
      itemId[name] = {id, isTool == "TOOL" ? true : false};
      cout << "Item: " << name << " id: " << id << " type: " << type << " isTool: " << isTool << endl;
    }

    for (int i = 0; i < recipes2.size(); i++) {
      Recipe& recipe = recipes2[i];
      vector<string> vStr = recipe.getItems();
      vector<string> vRes;

      int offsetRow = 3 - recipe.getRow();
      int offsetCol = 3 - recipe.getCol();

      for (int row = 0; row < recipe.getRow(); row++) {
        for (int col = 0; col < recipe.getCol(); col++) {
          // string item = vStr[row*recipe.getCol() + col]; regular
          string item = vStr[(row+1) * recipe.getCol() - col - 1]; // flipped
          if (item == "-") {
            continue;
          }
          if (item == "PLANK") {
            item = "OAK_PLANK";
          } else if (item == "STONE") {
            item = "COBBLESTONE";
          }

          vRes.push_back("GIVE " + item + " 1");
          // vRes.push_back("MOVE I0 1 C" + to_string(row*3 + col)); // pojok kiri atas
          vRes.push_back("MOVE I0 1 C" + to_string(row*3 + col + offsetCol + (offsetRow *3))); // pojok kanan bawah
        }
      }

      vRes.push_back("CRAFT");
      vRes.push_back("EXPORT tests/" + to_string(counter) + ".out");
      vRes.push_back("EXIT");
      fm.write("tests/" + to_string(counter) + ".in", vRes);

      vector<string> vAns(9*3);
      pair<int, bool> p = itemId[recipe.getResult()];
      vAns[0] = (to_string(p.first) + ":" + to_string(recipe.getResultQty()) + (p.second ? "0" : ""));
      for (int idx = 1;idx < 9 * 3;idx++) {
        vAns[idx] = "0:0";
      }
      cout << "COUNTER: " << counter << endl;
      cout << recipe << endl;
      cout << vAns[0] << endl;
      fm.write("tests/" + to_string(counter) + ".ans", vAns);
      counter++;
      cout << "========================================" << endl;
    }

  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  return 0;
}
