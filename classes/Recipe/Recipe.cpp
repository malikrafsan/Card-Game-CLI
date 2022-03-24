#include "Recipe.hpp"

Recipe::Recipe() {
  this->row = 0;
  this->col = 0;
  this->items = vector<string>();
  this->result = "";
  this->resultQty = 0;
}

Recipe::Recipe(vector<string> data) {
  try {
    stringstream rowCol(data[0]);
    rowCol >> this->row;
    rowCol >> this->col;
    for (int i = 0; i < this->row; i++) {
      stringstream ss(data[i + 1]);
      for (int j = 0; j < this->col; j++) {
        string item;
        ss >> item;
        this->items.push_back(item);
      }
    }
    stringstream res(data[this->row + 1]);
    res >> this->result;
    res >> this->resultQty;
  } catch (const std::exception &e) {
    throw RecipeWrongFormatException(data);
  }
}

int Recipe::getCol() const {
  return (this->col);
}

int Recipe::getRow() const {
  return (this->row);
}

string Recipe::getResult() const {
  return (this->result);
}

int Recipe::getResultQty() const {
  return (this->resultQty);
}

vector<string> Recipe::getItems() const {
  return (this->items);
}

ostream &operator<<(ostream &os, const Recipe &r) {
  os << "Recipe: " << r.row << "x" << r.col << endl;
  os << "Items: " << endl;
  for (int i = 0; i < r.row; i++) {
    for (int j = 0; j < r.col; j++) {
      os << r.items[i * r.col + j] << " ";
    }
    os << endl;
  }
  os << "Result: " << r.result << " " << r.resultQty << endl;
  return os;
}
