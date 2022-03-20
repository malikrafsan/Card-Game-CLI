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

class FileNotFoundException : public exception {
private:
  string _What;

public:
  FileNotFoundException(string filename) {
    this->_What = "File " + filename + " not found";
  }
  const char *what() const throw() { return _What.c_str(); }
};

class FileCannotBeWrittenException : public exception {
private:
  string _What;

public:
  FileCannotBeWrittenException(string filename) {
    this->_What = "File " + filename + " cannot be written";
  }
  const char *what() const throw() { return _What.c_str(); }
};

#endif // __FILE_MANAGER__