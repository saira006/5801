#include "modify.h"

int Modify::addComment(string comment, int groupIndex) {
  if(groupIndex == -1) { // Checking that the group exists in the vector
    cout << "Group does not exist \n";
    return -1;
  } else {
    if (groups[groupIndex]->comment == "") { // Checking that there is no comment associated with the specified group
      groups[groupIndex]->comment = comment;
      return 1;
    }
    else {
      cout << "Group already contains a comment \n";
      return 0;
    }
  }
}

int Modify::removeComment(int groupIndex) { 
  if(groupIndex == -1){ // Checking that the group exists in the vector
    cout << "Group does not exist \n";
    return -1;
  } else {
    groups[groupIndex]->comment = ""; 
    return 1;
  }
}

int Modify::editComment(string comment, int groupIndex) {
  if(groupIndex == -1){ // Checking that the group exists in the vector
    cout << "Group does not exist \n";
    return -1;
  } else {
    if (groups[groupIndex]->comment != "") { // Checking that there is an existing comment for the group
      groups[groupIndex]->comment = comment;
      return 1;
    } else {
      cout << "No existing comment to edit \n";
      return 0;
    }
  }
}

void Modify::createGroup(int start, int end) {
  Group *group = new Group(start, end);
  groups.push_back(group);
}

void Modify::deleteGroup(int startLine, int endLine) {
  int index = getGroup(startLine, endLine); // Retrieving index of group in the vector
  groups.erase(groups.begin() + index);
}

int* Modify::promptUserGroup(int max) {
  int start = -1;
  int end = max+1;
  while (start < 0) { // Looping until a valid start line is entered
    if (start < 0 && start >= max) { // Checking bounds for starting line input
      cout << "Invalid start line \n";
    }
    cout << "Enter starting line of group: ";
    cin >> start;
  }
  while (end > max || start > end) { // Looping until a valid end line is entered
    if (end > max || start > end) { // Checking bounds for ending line input
      cout << "Invalid end line \n";
    }
    cout << "Enter ending line of group: ";
    cin >> end;
  }
  int* startEnd = new int[2]; // Initializing temporary array to hold both inputs
  startEnd[0] = start;
  startEnd[1] = end;
  return startEnd;
}

int Modify::getGroup(int startLine, int endLine) {
  int start, end;
  for (int i = 0; i < groups.size(); i++) { // Looping to check that group exists
    start = groups.at(i)->getStart();
    end = groups.at(i)->getEnd();
    if ((start == startLine) && (end == endLine)) // Checking if group matches
      return i;
  }
  return -1;
}