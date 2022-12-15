#ifndef MULTICHOICE_H_
#define MULTICHOICE_H_

// #include "modify.h"
#include "question.h"
/* #include <fstream>
#include <iostream>
#include <vector> */

using namespace std;

class MultiChoice : public Question {

public:
  // Constructor for multichoice class
  MultiChoice(){};

  // virtual functions from base class
  int generate(string fileName, string fileType, int numQuestions);
  string new_question(int i,int j, string lines[]);
  
  // Destructor for multichoice class
  ~MultiChoice(){};
};

#endif