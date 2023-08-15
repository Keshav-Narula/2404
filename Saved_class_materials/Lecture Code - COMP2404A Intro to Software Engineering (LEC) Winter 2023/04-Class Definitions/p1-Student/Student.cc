#include "Student.h"
#include <iostream>

Student::Student(string name, string number, string major, float gpa){
    this->name = name;
    this->number = number;
    this->major = major;
    this->gpa = gpa;
}
void Student::print(){
    cout<<name<<endl;
    cout<<number<<endl;
    cout<<major<<endl;
    cout<<gpa<<endl<<endl;
}
bool Student::isPassing(){
    return gpa >= 6.0;
}
    