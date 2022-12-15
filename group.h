/*
 * Class: Group
 *
 * Description: This class keeps track of the information of groups of lines
 * such as the starting and ending line numbers.
 *  
 * Design Element: Section 4.2.2.2 in Design Document
 */

#ifndef GROUP_H_
#define GROUP_H_

#include <fstream>
#include <iostream>
using namespace std;

class Group {

public:
  // Constructor for Group class
  Group();

  // Explicit constructor for Group class
  Group(int start, int end);

  // Destructor for Group class
  ~Group(){};

  // This variable keeps track of the comment associated with the lines of code
  // Design Element: Section 4.2.2.2.1 in Design Document
  string comment;

  // This function sets the starting line number of the group
  // Design Element: Section 4.2.2.2.2 in Design Document
  void setStart(int lineNum);

  // This function gets the starting line number of the group
  // Design Element: Section 4.2.2.2.2 in Design Document
  int getStart();

  // This function sets the ending line number of the group
  // Design Element: Section 4.2.2.2.2 in Design Document
  void setEnd(int lineNum);

  // This function gets the ending line number of the group
  int getEnd();

private:
  // This variable represents the starting line of the group
  // Design Element: Section 4.2.2.2.1 in Design Document
  int startLine;

  // This variable represents the ending line of the group
  // Design Element: Section 4.2.2.2.1 in Design Document
  int endLine;
};

#endif