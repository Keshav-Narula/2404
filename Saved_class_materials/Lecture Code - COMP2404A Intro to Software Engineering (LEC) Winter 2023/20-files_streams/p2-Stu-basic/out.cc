#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "Student.h"


int main()
{
  string num, name, majorPgm;
  float  gpa;

  ofstream outfile("students.txt");

  if (!outfile) {
    cout << "Error:  could not open file" << endl;
    exit(1);
  }

  cout << "Enter student number, name, major, GPA: " << endl;

  while ( cin >> num >> name >> majorPgm >> gpa) {
    //outfile << num << " " << name << " " << majorPgm << " " << gpa << endl;
    outfile << Student(num, name, majorPgm, gpa)<<endl;
  }

  outfile.close();  //this is called automatically in the destructor

  cout.put('A');

  cout.clear(cout.rdstate() & ~ios::badbit);

  return 0;
}

