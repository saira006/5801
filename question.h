#ifndef QUESTION_H_
#define QUESTION_H_

#include "modify.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class Question {

public:
  // Constructor for question class
  Question(){};

  // Function to generate the questions
  virtual int generate(string fileName, string fileType, int numQuestions) = 0;

  // Destructor for question class
  ~Question(){};
};

#endif