#ifndef __FILE_MANAGER__
#define __FILE_MANAGER__

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FileManager {
public:
  void write(string filename, vector<string> data);
  vector<vector<string>> readFiles(string path);
  vector<string> readFile(string path);
};

#endif // __FILE_MANAGER__