#include "multichoice.h"

using namespace std;

void new_question(int i, string lines[]) {
  cout<<"Q"<<(i+1)<<". Select all correct options:"<<endl;
  for (int j=0;j<4;j++) {
    int len = lines[i].length();
    int idx = -1;
    srand(time(0));
    while (lines[i][idx = rand() % len] == ' ');
    string tmp = lines[i];
    tmp[idx] = char(33 + rand() % 222);
    cout<<j<<". "<<tmp<<endl;
  }
}

void MultiChoice::generate() {
  cout<<"In multichoice.cpp"<<endl;
  ifstream file;
  string fileName,type;
  cout<<"Enter a File Name: ";
  cin>>fileName;
  cout<<"Enter a file type: c++, python or java: " ;
  cin>>type;
  char c;
  if(type=="c++" || type =="java")
    c=';';
  else
    c='\n';
  file.open(fileName);
  string line;
  int count=0;
  int size=100;
  string s[size];
  while (getline(file, line,c)) {
      s[count]=line;
      count++;
  }
  for(int i=0;i<count;i++) {
    //cout<<s[i]<<"\n";
    if (s[i].length() == 0) continue;
    new_question(i, s);
    cout<<endl;
  }
}