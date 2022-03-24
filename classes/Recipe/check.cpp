// checker file
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream answerFile("./tests/answer/recipe.ans");
  ifstream outputFile("./tests/output/recipe.out");
  string answer, output;
  bool same = true;
  while (getline(answerFile, answer) && getline(outputFile, output)) {
    // remove any trailing whitespaces
    answer.erase(answer.find_last_not_of(" \n\r\t") + 1);
    output.erase(output.find_last_not_of(" \n\r\t") + 1);
    if (answer != output) {
      same = false;
    }
  }
  if (same && !getline(answerFile, answer) &&
      !getline(outputFile, output)) {
    cout << "Test passed." << endl;
  } else {
    cout << "Test failed." << endl;
  }
  

  return 0;
}
