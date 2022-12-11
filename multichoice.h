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
  MultiChoice() {};

  //Function to generate the questions
  void generate();

  // Destructor for multichoice class
  ~MultiChoice() {};

};

#endif