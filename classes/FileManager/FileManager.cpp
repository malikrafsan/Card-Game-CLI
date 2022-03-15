#include "FileManager.hpp"
#include <filesystem>

void FileManager::write(string filename, vector<string> data) {
  ofstream file;
  file.open(filename);
  for (int i = 0; i < data.size(); i++) {
    file << data[i] << endl;
  }
  file.close();
}

vector<vector<string>> FileManager::read(string path) {
  vector<vector<string>> data;

  for (const auto & file : filesystem::directory_iterator(path)) {
    ifstream fileStream(file.path());
    vector<string> lines;
    for (string line; getline(fileStream, line);) {
      lines.push_back(line);
    }
    data.push_back(lines);
  }

  return data;
}