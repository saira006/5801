#ifndef QUESTION_H_
#define QUESTION_H_

#include "modify.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include<string>
#include<time.h>

using namespace std;

class Question {

public:
  // Constructor for question class
  Question() {};

  //Function to generate the questions
  virtual void generate() = 0;

  // Destructor for question class
  ~Question() {};

};

#endif