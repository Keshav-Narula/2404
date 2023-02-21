#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g, int n, string s, string c, string p): number(s1), name(s2), majorPgm(s3), gpa(g), homeAddr(n,s,c,p)
{ 
  //Cant initialize the homeaddresss inside the brackets, since the address construcotr would be called before the student constructor, so it is made twice, which is ineffficent
  // We put the constructor inside the parameters, so the address constructor is only called once, and the Student is initialized
  //If you dont put it intialize inside the Student constructor then, it will give ERRORS since there is no default constructor to call (doesnt exist) tp call to initialze that memeber variable
  cout<<"-- Student ctor:  "<<name<<endl;}



Student::Student(Student& stu): number(stu.number),  name(stu.name), majorPgm(stu.majorPgm), gpa(stu.gpa), homeAddr(stu.homeAddr){
  //uses the copy construcotr to initialize the homeAddress member
  //This syntax, for cosntuctor parameters could be used for anything and any primatives. Shown above the memeber intializer syntaxes are used 
  //Constructor wiht empty body is common, all memebers initialzed using the member initialzer syntax

  //add code here
  //homeAddr = new Address(*stu.homeAddr);
  cout<<"-- Student copy constructor:  "<<name<<endl;

}

Student::~Student()
{ 
  cout<<"-- Student dtor:  "<<name <<endl;
}

string Student::getName()       { return name; }
void Student::setName(string n) { name = n; }

void Student::print() 
{
  cout<<"Student:  " << number << "  " << left << setw(10) << name << " "        << setw(10) << majorPgm << "   GPA:"
                     <<fixed << setprecision(2)<< setw(5) << right << gpa << endl;
  homeAddr.print();
}

