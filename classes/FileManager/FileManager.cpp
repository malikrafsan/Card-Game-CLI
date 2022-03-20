#include "FileManager.hpp"
#include <filesystem>

void FileManager::write(string filename, vector<string> data) {
  ofstream file;
  file.open(filename);

  if (!file) {
    // string path = "/home/person/dir/file";
    size_t split = filename.find_last_of("/");
    string dir = filename.substr(0, split);
    // string file = path.substr(split, path.length());

    if (!filesystem::exists(dir)) {
      filesystem::create_directories(dir);
    }
    file.close();
    file.open(filename);

    if (!file) {
      throw FileCannotBeWrittenException(filename);
    }
  }

  for (int i = 0; i < data.size(); i++) {
    file << data[i] << endl;
  }
  file.close();
}

vector<string> FileManager::readFile(string path) {
  ifstream fileStream(path);

  if (!fileStream) {
    throw FileNotFoundException(path);
  }

  vector<string> lines;
  for (string line; getline(fileStream, line);) {
    lines.push_back(line);
  }
  
  return lines;
}

vector<vector<string>> FileManager::readFiles(string path) {
  vector<vector<string>> data;

  for (const auto &file : filesystem::directory_iterator(path)) {
    data.push_back(this->readFile(file.path().string()));
  }

  return data;
}