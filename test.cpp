#include "test.h"

using namespace std;

void Test::GroupTest() {
  Group *group = new Group();
  ofstream fout ("Group_report.txt");
  fout<<"Report for the Tests of the Group Class\n\n";
  //This just creates a new group and tests the setters and getters for it 
  group->setStart(5);
  if(group->getStart() == 5)
  {
    fout<<"Test for Getter and Setters : P\n";
  }
  else
  {
    fout<<"Test for Getters and Setters : F\n";
  }
  fout.close();
}

void Test::ModifyTest() {
  //This creates a a new modify object
  Modify *modify = new Modify();
  
  ofstream fout ("Modify_report.txt");
  fout<<"Report for the Tests of the Modify Class\n\n";
  
  //We create a new modify object
  modify->createGroup(1,2);

  //We check to see if there the group was actually created by checking the getters and setters at that group index
  if(modify->groups.at(0)->getStart()==1 && modify->groups.at(0)->getEnd()==2)
  {
    fout<<"Test for adding a group is : P\n";
  }
  else
  {
    fout<<"Test for adding a group is : F\n";
  }
  
  //This is a check to see if we get an error message when we type in an incorrect start and end line
  if(modify->getGroup(0,2)==-1)
  {
    fout<<"Test for printing error message when incorrect start and end line are passed in : P\n";
  }
  else
  {
    fout<<"Test for printing error message when incorrect start and end line are passed in : F\n";
  }
  
  //This is a check to see if there is a group at a given start and end   line
  if(modify->getGroup(1,2)==-1)
  {
    fout<<"Test for getting a group with a given start and end line : P\n";
  }
  else
  {
       fout<<"Test for getting a group with a given start and end line : P\n";
  }

  //We check to see if a group is deleted or not
  modify->deleteGroup(1,2);
  if(modify->groups.size()==0)
  {
    fout<<"Test for deleting a group : P\n";
  }
  else
  {
    fout<<"Test for deleting a group : F\n";
  }

  
 //We check to see if we can add a comment successfully or not 
  //We will create a group and then add a comment
  modify->createGroup(1,2);
  int idx=-1;
  if(modify->addComment("This is an important line",idx)==-1)
  {
    fout<<"Test for printing error message for negative index when we add comments to a group : P\n";
  }
  else
  {
    fout<<"Test for printing error message for negative index when we add comments to a group : F\n";
  }

  idx = 0;
  if(modify->addComment("This is an important line",idx)==1)
  {
    fout<<"Test for adding a comment for a group: P\n";
  }
  else
  {
    fout<<"Test for adding a comment for a group : F\n";
  }


  if(modify->addComment("This is an important line",idx) == 0)
  {
    fout<<"Test for printing an error message when adding a comment for a group that already has comments : P\n";
  }
  else
  {
    fout<<"Test for printing an error message when adding a comment for a group that already has comments : F\n";
  }


  
  //We are checking to see if we can remove a comment succesfully 
  if(modify->removeComment(-1) == -1)
  {
    fout<<"Test for printing an error message when group index is invalid when we are removing a comment: P\n";
  }
  else
  {
    fout<<"Test for printing an error message when group index is invalid when we are removing a comment: F\n";
  }

  
  //We are checking to see if we can edit a comment successfully or not 
  if(modify->removeComment(0) == 1)
  {
    fout<<"Test for removing a comment at a given index : P\n";
  }
  else
  {
    fout<<"Test for removing a comment at a given index : F\n";
  }

  idx = modify->addComment("This is an important line",0);
  idx=-1;
  if(modify->editComment("This is an important line",idx)==-1)
  {
    fout<<"Test for printing error message for negative index for a grouping with lines when we are editing comments: P\n";
  }
  else
  {
        fout<<"Test for printing error message for negative index for a grouping with lines when we are editing comments: F\n";
  }

  
  idx = 0;
  if(modify->editComment("This is an important line",idx)==1)
  {
    fout<<"Test for editing a comment for a grouping with lines : P\n";
  }
  else
  {
    fout<<"Test for editing a comment for a grouping with lines : F\n";
  }
  fout.close();
}