#include <iostream>
#include <string>

#define NUMSTUDENTS 3
using namespace std;

class Student{
    public:
        void print(){
            cout<<name<<endl;
            cout<<number<<endl;
            cout<<major<<endl;
            cout<<gpa<<endl<<endl;
        }
        string name;
        string number;
        string major;
        float gpa;
};



int main(){
    Student students[NUMSTUDENTS];
    string names[NUMSTUDENTS] = {"Joe", "Amy", "Barb"};
    string numbers[NUMSTUDENTS] = {"101111111", "101222222", "101333333"};
    string major[NUMSTUDENTS] = {"CS", "Math", "History"};
    float gpa[NUMSTUDENTS] = {10.0f, 11.2f, 5.9f};

    cout<<"Initializing all students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        students[i].name = names[i];
        students[i].number = numbers[i];
        students[i].major = major[i];
        students[i].gpa = gpa[i];
    }

    cout<<"Printing all students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        students[i].print();
    }

    cout<<"Printing all passing students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        if (students[i].gpa < 6.0) continue;
        students[i].print();
    }


}