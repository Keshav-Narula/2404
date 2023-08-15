#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>

#include "Student.h"


int main()
{
  string num, name, majorPgm, garbage;
  float  gpa;
  vector<Student> stuVect;
  ostream_iterator<Student> outItr(cout);

  ifstream infile("students.txt");

  if (!infile) {
    cout << "Error: could not open file" << endl;
    exit(1);
  }
  infile >>garbage;
  //cout<<garbage;
  while ( infile >> num >> name >> majorPgm >> garbage >> gpa ) {
    Student stu(num, name, majorPgm, gpa);
    stuVect.push_back(stu);
    infile >>garbage;
  }

  cout<<endl<<"List of students:"<<endl;
  copy(stuVect.begin(), stuVect.end(), outItr);


  return 0;
}

