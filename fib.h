#ifndef FIB_H_
#define FIB_H_

// #include "modify.h"
#include "question.h"

/* #include <fstream>
#include <iostream>
#include <vector> */

using namespace std;

class FIB : public Question {

public:
  // Constructor for FIB class
  FIB() {};

  // virtual functions from base class
  int generate(string fileName, string fileType, int numQuestions);
  string question_creator(string s);

  // Destructor for FIB class
  ~FIB() {};
};

#endif