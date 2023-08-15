#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include "Student.h"

bool compare(Student* s1, Student* s2);

int main()
{
  Student matilda("100567899", "Matilda", "CS", 9.0f);
  Student joe("100234555", "Joe", "Physics", 8.3f);
  Student timmy("100234888", "Timmy", "CS", 11.5f);
  Student jimmy("100234889", "Jimmy", "Math", 10.5f);

  vector<Student*> comp2404;

  comp2404.push_back(&matilda);
  comp2404.push_back(&joe);
  comp2404.push_back(&timmy);
  comp2404.push_back(&jimmy);

  cout << endl << "COMP 2404 students:" << endl;

  for (int i=0; i<comp2404.size(); ++i)
    cout << *comp2404[i];

  cout <<endl<< "Student at 1:  " << *(comp2404.at(1));
  cout <<endl<< "Student at 3:  " << *(comp2404.at(3));
  try{
    cout <<endl<< "Student at 10: " << *(comp2404.at(10));
  }catch(exception& e){
    cout<<"Bad index"<<endl;
  }
  vector<Student*> comp2406(comp2404);

  cout << endl << "Are vectors equal? "<< ( comp2406 == comp2404 ? "yes" : "no" ) << endl;

  comp2406.push_back(&jimmy);
  comp2406.pop_back();

  cout << endl << "Are vectors equal? "<< ( comp2406 == comp2404 ? "yes" : "no" ) << endl;
  

  cout<<"Sorting students"<<endl;

  sort(comp2404.begin(), comp2404.end(), compare);

  cout << endl << "COMP 2404 students:" << endl;

  for (int i=0; i<comp2404.size(); ++i)
    cout << *comp2404[i];

  cout << endl << "Are vectors equal? "<< ( comp2406 == comp2404 ? "yes" : "no" ) << endl;
  

  vector<Student> vect2;
  cout << endl << "Adding students to vect2..." << endl;
  vect2.push_back(matilda);
  vect2.push_back(joe);
  vect2.push_back(timmy);

cout << endl << "So long and thanks for all the fish..." << endl;

return 0; 

} 


bool compare(Student* s1, Student* s2){
  return s1->gpa < s2->gpa;
}


