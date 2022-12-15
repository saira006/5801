#include "fib.h"
#include "modify.h"
#include "multichoice.h"
#include "test.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

  // Section for uploading file
  string fileName;
  cout << "Enter file name: ";
  cin >> fileName;
  ifstream file;
  file.open(fileName);

  // Section for verifying file
  while (file.fail()) {
    cout << "Invalid Filename\n";
    cout << "Enter file name: ";
    cin >> fileName;
    file.open(fileName);
  }
  cout << "File opened successfully!\n";

  int numLines = 0;
  string line;
  while (getline(file, line)) { // Looping to count the total number of lines
    if (line != "\n")
      numLines++;
  }

  // extract file type information from file name
  string fileType = "";
  int extIdx = fileName.find('.');
  if (extIdx != std::string::npos)
    fileType = fileName.substr(extIdx + 1, fileName.size() - extIdx - 1);

  int cmd = 0;
  int x = 0;
  Modify *modify = new Modify();
  int numQuestions = 0;
  int choice = 0;
  while (cmd != 3) {
    cout << "1. Modify Source Code \n";
    cout << "2. Generate Questions \n";
    cout << "3. Exit \n";
    cout << "Enter command: ";
    cin >> cmd;
    switch (cmd) {
    // Section for modifying source code
    case 1:
      modify->runModify(fileName, numLines, fileType);
      break;

    // Section for generating questions
    case 2:
      cout << "Enter number of questions to generate (1-30): ";
      cin >> numQuestions;
      while ((numQuestions < 1) || (numQuestions > 30)) {
        cout << "Invalid number of questions!\n\n";
        cout << "Enter number of questions to generate (1-30): ";
        cin >> numQuestions;
      }
      cout << "1. Generate Multiple Choice \n";
      cout << "2. Generate Fill in the Blank \n";
      cout << "Enter choice: ";
      cin >> choice;
      while ((choice < 1) || (choice > 2)) {
        cout << "Invalid choice!\n\n";
        cout << "1. Generate Multiple Choice \n";
        cout << "2. Generate Fill in the Blank \n";
        cout << "Enter choice: ";
      }

      Question *q;
      if (choice == 1) {
        q = new MultiChoice();
      } else if (choice == 2) {
        q = new FIB();
      }
      
      x = q->generate(fileName, fileType, numQuestions);
      cout << "Question generation returned code: " << x << "\n";
      break;
    case 3:
      cout << "Exited program \n";
      break;

    // Section for when the user enters a command not available (not 1-6)
    default:
      cout << "Invalid Command \n";
    }
  }
}