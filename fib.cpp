#include "fib.h"

using namespace std;

// This function takes in a line of code and generates a fill in the blank question
string FIB::question_creator(string s) {
  // This code block tokenizes every word in the line to figure out
  // which one to blank out
  if(s == "")
    return("error");
  
  stringstream ss(s);
  string word;
  int counter = 0;
  string strings[100];
  while (ss >> word) {
    strings[counter] = word;
    counter++;
  }
  // This code selects one of the words in the sentence at random
  // and replaces it with a sequence of blank characters for
  // question generation
  srand(time(0));
  int val;
  if(counter==0)
    val=0;
  else
    val = rand() % counter;
  string x = "";
  for (int i = 0; i < counter; i++) {
    if (i == val)
      x += " _____ ";
    else
      x += strings[i];
  }
  return (x);
}

int FIB::generate(string fileName, string fileType, int numQuestions) {
  // Checks to see if there is a commented line or not
  ifstream file;
  char eol_identifier;
  
  if (fileType.compare("cpp") == 0 || fileType.compare("java") == 0)
    eol_identifier = ';';
  else if(fileType.compare("py") == 0)
    eol_identifier = '\n';
  else
    return(1);
  
  ofstream fout("fib_questions.txt");
  file.open(fileName);
  
  if (file.fail()) {
    return(2);
  }
  
  string line;
  int count = 0;
  int count2 = 0;
  int count3 = 0;
  int size = 500;
  string s[size];
  // We read in the source code line by line for problem generation
  while (getline(file, line, eol_identifier)) {
    s[count] = line;
    count++;
  }
  
  if(numQuestions>30) {
    return(3);
  }
  // We go through the code line by line and generate a question for every line
  while (count2 < numQuestions) {
    // If the code has comments, that line is skipped for generating fill in the
    // blanks
    if ((s[count2].find('#') != std::string::npos) ||
        (s[count2].find('/') != std::string::npos)) {
      count2++;
      numQuestions++;
    }
    // If the code doesn't have any comments, we use that line of the code for
    // question generation and display the next 2 lines for context as well.
    else {
      fout << "Question " << count3 + 1 << " is"
           << "\n";
      string question;
      // This line calls takes in a line and adds a blank
      question = question_creator(s[count2]);
      fout << question;
      fout << s[count2 + 1] << s[count2 + 2] << "\n\n";
      count2++;
      count3++;
    }
  }
  fout.close();
  cout<<"Successfully Generated Fill in the Blank Questions"<<endl;
  return(0);
}