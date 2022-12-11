#include "modify.h"
#include "test.h"
#include <fstream>
#include <iostream>

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

  int cmd = 0;
  int x = 0;
  Modify *modify = new Modify();
  while (cmd != 6) { // Continuously looping until exit command (6) chosen
    // Prompting user with different actions/choices
    cout << "1. Create Group \n";
    cout << "2. Delete Group \n";
    cout << "3. Add Comment \n";
    cout << "4. Remove Comment \n";
    cout << "5. Edit Comment  \n";
    cout << "6. Exit \n";
    cout << "Enter command: ";
    cin >> cmd;

    int *startEnd = new int[2]; // Keeps track of user inputs
    Group *group; // Keeps track of the current group
    string junk; // Keeps track of newlines in input stream
    string cmt; // Keeps track of user entered comment
    int groupIndex; // Keeps track index of a Group object in group vector

    switch (cmd) {
    // Section for creating a group of lines
    case 1:
      startEnd = modify->promptUserGroup(numLines);
      modify->createGroup(startEnd[0], startEnd[1]);
      cout << "Group sucessfully created \n";
      break;

    // Section for deleting a group of lines
    case 2:
      startEnd = modify->promptUserGroup(numLines);
      modify->deleteGroup(startEnd[0], startEnd[1]);
      cout << "Group sucessfully deleted \n";
      break;

    // Section for adding a comment to an existing group of lines
    case 3:
      cout << "New Comment: ";
      getline(cin >> junk, cmt);
      startEnd = modify->promptUserGroup(numLines);
      groupIndex = modify->getGroup(startEnd[0], startEnd[1]);
      x = modify->addComment(cmt, groupIndex);
      cout << "Comment sucessfully added \n";
      break;

    // Section for removing a comment to an existing group of lines
    case 4:
      startEnd = modify->promptUserGroup(numLines);
      groupIndex = modify->getGroup(startEnd[0], startEnd[1]);
      x = modify->removeComment(groupIndex);
      cout << "Comment sucessfully removed \n";
      break;

    // Section for editing an existing comment to an existing group of lines
    case 5:
      cout << "New Comment: ";
      getline(cin >> junk, cmt);
      startEnd = modify->promptUserGroup(numLines);
      groupIndex = modify->getGroup(startEnd[0], startEnd[1]);
      x = modify->editComment(cmt, groupIndex);
      cout << "Comment sucessfully edited \n";
      break;

    // Section for exiting the program
    case 6:
      cout << "Exited program \n";
      break;

    // Section for when the user enters a command not available (not 1-6)
    default:
      cout << "Invalid Command \n";
    }
  }
}