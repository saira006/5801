#include "multichoice.h"

using namespace std;

string MultiChoice::new_question(int i, int k, string lines[]) {
  string s = "";
  s += "Q" + to_string(i + 1) + ". Select all correct options:" + "\n";
  for (int j = 0; j < 4; j++) {
    int len = lines[k].length();
    int idx = -1;
    while (lines[k][idx = rand() % len] == ' ')
      ;
    string tmp = lines[k];
    tmp[idx] = char(33 + rand() % 222);
    s += to_string(j + 1) + ". " + tmp + "\n";
  }
  return (s);
}

int MultiChoice::generate(string fileName, string fileType, int numQuestions) {

  ifstream file;
  char eol_identifier;

  if (fileType.compare("cpp") == 0 || fileType.compare("java") == 0)
    eol_identifier = ';';
  else if (fileType.compare("py") == 0)
    eol_identifier = '\n';
  else
    return (1);

  file.open(fileName);
  if (file.fail()) {
    return (2);
  }

  if (numQuestions > 30) {
    return (3);
  }

  string line;
  int count = 0;
  int count2 = 0;
  int count3 = 0;
  int size = 500;
  string s[size];
  while (getline(file, line, eol_identifier)) {
    s[count] = line;
    count++;
  }
  ofstream fout("multichoice_questions.txt");
  srand(time(0));
  while (count2 < numQuestions) {
    // If the code has comments, that line is skipped for generating fill in the
    // blanks
    if ((s[count2].length() == 0) ||
        (s[count2].find('#') != std::string::npos) ||
        (s[count2].find('/') != std::string::npos)) {
      count2++;
      numQuestions++;
    }
    // If the code doesn't have any comments, we use that line of the code for
    // question generation
    else {
      string question;
      // This line calls takes in a line and generates the MCQ
      question = new_question(count3, count2, s);
      fout << question << "\n\n";
      count2++;
      count3++;
    }
  }
  fout.close();
  cout << "Successfully Generated Multiple Choice Questions" << endl;
  return (0);
}
