#ifndef __RECIPE__
#define __RECIPE__

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Recipe {
private:
  int row;
  int col;
  vector<string> items;
  string result;
  int resultQty;

public:
  Recipe();
  Recipe(vector<string> data);
  int getRow() const;
  int getCol() const;
  string getResult() const;
  friend ostream& operator<<(ostream &os, const Recipe &r);
  vector<string> getItems() const;
};

class RecipeWrongFormatException: public exception {
private:
  const vector<string> data;
public:
  RecipeWrongFormatException(vector<string> data): data(data) {}
  const char* what() const throw() {
    string out = "Recipe has wrong format\n";
    for (int i = 0; i < this->data.size(); i++) {
      out += this->data[i] + "\n";
    }
    const char* res = out.c_str();
    return res;
  }
};

#endif