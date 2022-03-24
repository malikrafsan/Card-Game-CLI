#include "../FileManager/FileManager.hpp"
#include "Recipe.hpp"

int main() {
  FileManager fm;

  try {
    vector<Recipe> recipes2;
    const string recipesPath = "./tests/input";

    vector<vector<string>> files = fm.readFiles(recipesPath);

    for (int i = 0; i < files.size(); i++) {
      recipes2.push_back(Recipe(files[i]));
      cout << recipes2[i] << endl;
    }
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  try {
    vector<Recipe> recipes3;
    const string recipesPath = "NOTFOUND";

    vector<vector<string>> files = fm.readFiles(recipesPath);

    for (int i = 0; i < files.size(); i++) {
      recipes3.push_back(Recipe(files[i]));
      cout << recipes3[i] << endl;
    }
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  return 0;
}