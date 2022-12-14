#include "fib.h"

using namespace std;

//This function take in a line of code and generates a fill in the blank 
string FIB::question_creator(string s)
{
    //This code block tokenizes every word in the line to figure ot which 1 to blank out 
    stringstream ss(s);
    string word;
    int counter=0;
    string strings[100];
    while (ss >> word) {
        strings[counter]=word;
        counter++;
    }
  //This code selects one of the words in the sentence at random and turns it into a blank for question generation
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
  
  //Gets the user input for the file name, file type and the number of   questions 
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
  ofstream fout ("fib_questions.txt");
  file.open(fileName);
  string line;
  int count=0;
  int count2=0;
  int count3=0;
  int size=100;
  string s[size];
  //We read in the source code line by line for problem generation 
  while (getline(file, line,c)) {
      s[count]=line;
      count++;
  }
  //We go through the code line by line and generate a question for every line 
  while(count2<num)
    {
      //If the code has comments, that line is skipped for generating fill in the blanks
      if((s[count2].find('#') != std::string::npos) ||(s[count2].find('/') != std::string::npos))
      {
        count2++;
        num++;
      }
      //If the code doesn't have any comments, we use that line of the code for question generation and display the next 2 lines for context as well. 
      else
      {
      fout<<"Question "<<count3+1<<" is"<<"\n";
      string question;
      //This line calls takes in a line and adds a blank 
      question=question_creator(s[count2]);
      fout<<question;
      fout<<s[count2+1]<<s[count2+2]<<"\n\n";
      count2++;
      count3++;
      }
    }
    fout.close();
}
