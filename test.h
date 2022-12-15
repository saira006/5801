#ifndef TEST_H_
#define TEST_H_

#include "modify.h"
#include "fib.h"
#include "multichoice.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Test {

public:
  // Constructor for Test class
  Test() {};

  //Tests for the Group Class
  void GroupTest();

  //Tests for the Modify Class
  void ModifyTest();

  //Tests for the FIB Class
  void FIBTest();

  //Tests for the MultiChoice Class
  void MultiChoiceTest();

  // Destructor for Test class
  ~Test(){};

};

#endif