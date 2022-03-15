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

class FileNotFoundException: public exception {
private:
  const string filename;
public:
  FileNotFoundException(string filename): filename(filename) {}
  const char* what() const throw() {
    return "File not found";
  }
};

class FileCannotBeWrittenException: public exception {
private:
  const string filename;
public:
  FileCannotBeWrittenException(string filename): filename(filename) {}
  const char* what() const throw() {
    return "File cannot be written";
  }
};

#endif // __FILE_MANAGER__