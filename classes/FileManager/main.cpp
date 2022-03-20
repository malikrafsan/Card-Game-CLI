#include "FileManager.hpp"

void printDivider() {
  cout << "\n==========================================================\n" << endl;
}

int main(int argc, char **argv) {
  FileManager fm;

  try {
    string outputFile = "out/out.o";
    vector<string> data = {"1:1", "2:2", "3:3"};

    cout << "WRITE FILE " << outputFile << endl;
    fm.write(outputFile, data);
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  try {
    string outFile = "lilight.o";
    vector<string> data2 = {"aaa", "bbbb", "ccccc"};
    cout << "WRITE FILE " << outFile << endl;
    fm.write(outFile, data2);
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  printDivider();

  try {
    cout << "READ FILES CONFIG" << endl;
    vector<vector<string>> files = fm.readFiles("../../config/recipe");

    for (int i = 0; i < files.size(); i++) {
      for (int j = 0; j < files[i].size(); j++) {
        cout << files[i][j] << endl;
      }
    }
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  printDivider();

  try {
    cout << "READ FILE ITEM.TXT" << endl;
    vector<string> file = fm.readFile("../../config/itemNOTFOUND.txt");

    for (int i = 0; i < file.size(); i++) {
      cout << file[i] << endl;
    }
  } catch (const std::exception &e) {
    cout << "EXCEPTION: " << e.what() << endl;
  }

  return 0;
}