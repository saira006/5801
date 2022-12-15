#include "modify.h"

void Modify::runModify(string fileName, int numLines, string fileType) {
  int cmd = 0;
  int x = 0;

  while (cmd != 7) { // Continuously looping until exit command (6) chosen
    // Prompting user with different actions/choices
    cout << "1. Create Group \n";
    cout << "2. Delete Group \n";
    cout << "3. Add Comment \n";
    cout << "4. Remove Comment \n";
    cout << "5. Edit Comment  \n";
    cout << "6. Remove lines \n";
    cout << "7. Exit \n";
    cout << "Enter command: ";
    cin >> cmd;

    int *startEnd = new int[2]; // Keeps track of user inputs
    Group *group;               // Keeps track of the current group
    string junk;                // Keeps track of newlines in input stream
    string cmt;                 // Keeps track of user entered comment
    int groupIndex;     // Keeps track index of a Group object in group vector
    string lineNumbers; // Tracks the lines that need to ommited
    switch (cmd) {
    // Section for creating a group of lines
    case 1:
      startEnd = promptUserGroup(numLines);
      createGroup(startEnd[0], startEnd[1]);
      cout << "Group sucessfully created \n";
      break;

    // Section for deleting a group of lines
    case 2:
      startEnd = promptUserGroup(numLines);
      deleteGroup(startEnd[0], startEnd[1]);
      cout << "Group sucessfully deleted \n";
      break;

    // Section for adding a comment to an existing group of lines
    case 3:
      cout << "New Comment: ";
      getline(cin >> junk, cmt);
      startEnd = promptUserGroup(numLines);
      groupIndex = getGroup(startEnd[0], startEnd[1]);
      x = addComment(cmt, groupIndex);
      cout << "Comment sucessfully added \n";
      break;

    // Section for removing a comment to an existing group of lines
    case 4:
      startEnd = promptUserGroup(numLines);
      groupIndex = getGroup(startEnd[0], startEnd[1]);
      x = removeComment(groupIndex);
      cout << "Comment sucessfully removed \n";
      break;

    // Section for editing an existing comment to an existing group of lines
    case 5:
      cout << "New Comment: ";
      getline(cin >> junk, cmt);
      startEnd = promptUserGroup(numLines);
      groupIndex = getGroup(startEnd[0], startEnd[1]);
      x = editComment(cmt, groupIndex);
      cout << "Comment sucessfully edited \n";
      break;
      // Section for exiting the program

    case 6:
      cout << "Enter line numbers (eg. 1 5 9 8): ";
      cin.ignore(1, '\n');
      getline(cin, lineNumbers);
      x = omitLines(lineNumbers, fileName, fileType);
      break;

    // Section for exiting the program
    case 7:
      cout << "Exited to Main \n";
      return;

    // Section for when the user enters a command not available (not 1-6)
    default:
      cout << "Invalid Command \n";
    }
  }
}

int Modify::addComment(string comment, int groupIndex) {
  if (groupIndex == -1) { // Checking that the group exists in the vector
    cout << "Group does not exist \n";
    return -1;
  } else {
    if (groups[groupIndex]->comment ==
        "") { // Checking that there is no comment associated with the specified
              // group
      groups[groupIndex]->comment = comment;
      return 1;
    } else {
      cout << "Group already contains a comment \n";
      return 0;
    }
  }
}

int Modify::removeComment(int groupIndex) {
  if (groupIndex == -1) { // Checking that the group exists in the vector
    cout << "Group does not exist \n";
    return -1;
  } else {
    groups[groupIndex]->comment = "";
    return 1;
  }
}

int Modify::editComment(string comment, int groupIndex) {
  if (groupIndex == -1) { // Checking that the group exists in the vector
    cout << "Group does not exist \n";
    return -1;
  } else {
    if (groups[groupIndex]->comment !=
        "") { // Checking that there is an existing comment for the group
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
  int index =
      getGroup(startLine, endLine); // Retrieving index of group in the vector
  groups.erase(groups.begin() + index);
}

int *Modify::promptUserGroup(int max) {
  int start = -1;
  int end = max + 1;
  while (start < 0) { // Looping until a valid start line is entered
    if (start < 0 && start >= max) { // Checking bounds for starting line input
      cout << "Invalid start line \n";
    }
    cout << "Enter starting line of group: ";
    cin >> start;
  }
  while (end > max ||
         start > end) {             // Looping until a valid end line is entered
    if (end > max || start > end) { // Checking bounds for ending line input
      cout << "Invalid end line \n";
    }
    cout << "Enter ending line of group: ";
    cin >> end;
  }
  int *startEnd =
      new int[2]; // Initializing temporary array to hold both inputs
  startEnd[0] = start;
  startEnd[1] = end;
  return startEnd;
}

int Modify::getGroup(int startLine, int endLine) {
  int start, end;
  for (int i = 0; i < groups.size();
       i++) { // Looping to check that group exists
    start = groups.at(i)->getStart();
    end = groups.at(i)->getEnd();
    if ((start == startLine) && (end == endLine)) // Checking if group matches
      return i;
  }
  return -1;
}

int Modify::omitLines(const string lineNumber, string fileName,
                      string fileType) {
  string comment;
  vector<int> lines;
  istringstream lineNumbers(lineNumber);
  string line;
  char delim = ' ';
  
  while (getline(lineNumbers, line, delim)) {
    lines.push_back(stoi(line));
  }
  
  sort(lines.begin(), lines.end());
  
  if (fileType.compare("java") == 0 || fileType.compare("cpp") == 0) {
    comment = "//";
  } else if (fileType.compare("py") == 0) {
    comment = "#";
  } else {
    return (1);
  }
  
  ifstream in_file(fileName);
  if (in_file.fail()) {
    return (2);
  }
  
  ofstream out_file("omittedSource.txt");
  int i = 1;
  if (in_file && out_file) {
    while (getline(in_file, line)) {
      if (count(lines.begin(), lines.end(), i)) {
        out_file << comment << line << "\n";
      } else {
        out_file << line << "\n";
      }
      i++;
    }
  }
  in_file.close();
  out_file.close();
  return (0);
}
