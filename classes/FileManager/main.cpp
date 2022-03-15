#include "FileManager.hpp"

int main(int argc, char **argv) {
  string outputFile = "out.o";
  vector<string> data = {"1:1", "2:2", "3:3"};

  FileManager fm;
  fm.write(outputFile, data);

  vector<vector<string>> files = fm.read("../../config/recipe");

  for (int i=0;i<files.size();i++) {
    for (int j=0;j<files[i].size();j++) {
      cout << files[i][j] << endl;
    }
  }

  return 0;
}