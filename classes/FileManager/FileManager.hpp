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
  //! Write data to file with name as filename
  void write(string filename, vector<string> data);
  //! Read multiple files from directory on path
  vector<vector<string>> readFiles(string path);
  //! Read single file from file path
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

class FolderNotFoundException : public exception {
private:
  string _What;

public:
  FolderNotFoundException(string path) {
    this->_What = "Folder " + path + " not found";
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