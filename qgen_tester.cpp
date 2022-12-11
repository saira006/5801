#include "modify.h"
#include "fib.h"
#include "multichoice.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  //We just create a new object of the test class and run the tests for each class
  cout<<"Choose question type for problem generation:"<<endl;
  cout<<"1. Fill-in-the-blank"<<endl;
  cout<<"2. Multiple choice"<<endl;
  int choice;
  cin>>choice;
  Question *q;
  
  switch(choice) {
    case 1: q = new FIB();
            break;
    case 2: q = new MultiChoice();
            break;
  }
  
  q->generate();
}