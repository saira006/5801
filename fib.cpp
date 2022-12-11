#include "fib.h"

using namespace std;

string FIB::question_creator(string s)
{
    stringstream ss(s);
    string word;
    int counter=0;
    string strings[100];
    while (ss >> word) {
        strings[counter]=word;
        counter++;
    }
    srand(time(0));
    int val=rand()%counter;
    string x="";
    cout<<endl;
    for(int i=0;i<counter;i++)
      {
        if(i == val) 
          x+=" _____ ";
        else
          x+=strings[i];
      }
      return(x);
}

void FIB::generate() {
  cout<<"In FIB.cpp"<<endl;
  ifstream file;
  string fileName,type;
  int num;
  cout<<"Enter a File Name: ";
  cin>>fileName;
  cout<<"Enter a file type: c++, python or java: " ;
  cin>>type;
  cout<<"Enter the number of questions you need: ";
  cin>>num;
  char c;
  if(type=="c++" || type =="java")
    c=';';
  else
    c='\n';
  ofstream fout ("questions.txt");
  file.open(fileName);
  string line;
  int count=0;
  int count2=0;
  int count3=0;
  int size=100;
  string s[size];
  while (getline(file, line,c)) {
      s[count]=line;
      count++;
  }
  while(count2<num)
    {
      if((s[count2].find('#') != std::string::npos) ||(s[count2].find('/') != std::string::npos))
      {
        count2++;
        num++;
      }
      else
      {
      fout<<"Question "<<count3+1<<" is"<<"\n";
      string question;
      question=question_creator(s[count2]);
      fout<<question;
      fout<<s[count2+1]<<s[count2+2]<<"\n\n";
      count2++;
      count3++;
      }
    }
    fout.close();
}