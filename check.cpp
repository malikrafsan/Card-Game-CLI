// checker file
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int correct = 0, total = 0;

  for (const auto &entry : filesystem::directory_iterator("./generated_tests/tests")) {
    string filename = entry.path().filename().string();
    if (filename.size() >= 3 && filename.substr(filename.size() - 3) == "ans") {
      total++;
      ifstream answerFile(entry.path());
      ifstream outputFile("./tests/" + entry.path().stem().string() + ".out");
      string answer, output;
      bool same = true;
      while (getline(answerFile, answer) && getline(outputFile, output)) {
        // remove any trailing whitespaces
        answer.erase(answer.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);
        if (answer != output) {
          cout << "File: " << filename << " ANSWER: " << answer << endl;
          cout << "File: " << "./tests/" + entry.path().stem().string() + ".out" <<  " OUTPUT: " << output << endl;
          same = false;
        }
      }
      if (same && !getline(answerFile, answer) &&
          !getline(outputFile, output)) {
        correct++;
        cout << "Test " << total << " passed." << endl;
      } else {
        cout << "Test " << total << " failed." << endl;
      }
    }
  }

  cout << correct << " out of " << total << " tests passed." << endl;
  return 0;
}
