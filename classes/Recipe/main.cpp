#include "../FileManager/FileManager.hpp"
#include "Recipe.hpp"

void printDivider() {
  cout << "\n==========================================================\n" << endl;
}

int main() {
  FileManager fm;

  try {
    vector<Recipe> recipes1;
    cout << "READ RECIPE FILES" << endl;
    const string recipesPath = "../../config/recipe/BIRCH_PLANK.txt";

    vector<vector<string>> files = fm.readFiles(recipesPath);

    cout << "Filling" << endl;
    for (int i = 0; i < files.size(); i++) {
      cout << "READING " << i << endl;
      recipes1.push_back(Recipe(files[i]));
      cout << recipes1[i] << endl;
    }
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  printDivider();

  try {
    vector<Recipe> recipes2;
    cout << "READ RECIPE FILES" << endl;
    const string recipesPath = "../../config/recipes";

    vector<vector<string>> files = fm.readFiles(recipesPath);

    cout << "Filling" << endl;
    for (int i = 0; i < files.size(); i++) {
      cout << "READING " << i << endl;
      recipes2.push_back(Recipe(files[i]));
      cout << recipes2[i] << endl;
    }
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  printDivider();

  try {
    vector<Recipe> recipes3;
    cout << "READ RECIPE FILES" << endl;
    const string recipesPath = "../../config/recipe";

    vector<vector<string>> files = fm.readFiles(recipesPath);

    cout << "Filling" << endl;
    for (int i = 0; i < files.size(); i++) {
      cout << "READING " << i << endl;
      recipes3.push_back(Recipe(files[i]));
      cout << recipes3[i] << endl;
    }
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  return 0;
}