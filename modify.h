/*
 * Class: Modify
 *
 * Description: This class creates and deletes Group objects and updates the
 * vector accordingly. It also handles adding, editing, and removing comments
 * from specified groups of lines.
 *
 * Desgin Element: Section 4.2.1.3 in Desgin Document
 */

#ifndef MODIFY_H
#define MODIFY_H

#include "group.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Modify {

public:
  // Constructor for Modify class
  Modify() {}

  // Destructor for Modify Class
  ~Modify() {}

  // This function provides the interface for the modify commands
  void runModify(string filename, int numlines, string filtType);

  // This variable keeps track of the created Group objects
  vector<Group *> groups;

  // This function prompts the user for inputs for a group of lines
  int *promptUserGroup(int max);

  int getGroup(int startLine, int endLine);

  // This function adds a comment to a Group object
  // Desgin Element: Section 4.2.1.3.1 in Design Document
  int addComment(string comment, int groupIndex);

  // This functions removes comment from a Group object
  // Desgin Element: Section 4.2.1.3.1 in Design Document
  int removeComment(int groupIndex);

  // This function edits the existing comment of a Group object
  // Desgin Element: Section 4.2.1.3.1 in Design Document
  int editComment(string comment, int groupIndex);

  // This function creates a Group object and adds it to a Group vector
  // Desgin Element: Section 4.2.1.3.1 in Design Document
  void createGroup(int start, int end);

  // This function removes a Group object from the groups vector
  // Desgin Element: Section 4.2.1.3.1 in Design Document
  void deleteGroup(int start, int end);

  // This function removes lines from source code
  int omitLines(string lineNumbers, string fileName, string fileType);

private:
  string fileName;
  int numLines;
  string fileType;
};

#endif