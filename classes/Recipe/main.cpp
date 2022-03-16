#include "../FileManager/FileManager.hpp"
#include "Recipe.hpp"


int main() {
  FileManager fm;
  vector<Recipe> recipes;

  try {
    cout << "READ RECIPE FILES" << endl;
    const string recipesPath = "../../config/recipe";

    vector<vector<string>> files = fm.readFiles(recipesPath);

    cout << "Filling" << endl;
    for (int i = 0; i < files.size(); i++) {
      cout << "READING " << i << endl;
      recipes.push_back(Recipe(files[i]));
      cout << recipes[i] << endl;
    }
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  return 0;
}