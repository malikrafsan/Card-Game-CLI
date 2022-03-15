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

vector<string> FileManager::readFile(string path) {
  ifstream fileStream(path);
  vector<string> lines;

  for (string line; getline(fileStream, line);) {
    lines.push_back(line);
  }
  
  return lines;
}

vector<vector<string>> FileManager::readFiles(string path) {
  vector<vector<string>> data;

  for (const auto &file : filesystem::directory_iterator(path)) {
    data.push_back(this->readFile(file.path()));
  }

  return data;
}