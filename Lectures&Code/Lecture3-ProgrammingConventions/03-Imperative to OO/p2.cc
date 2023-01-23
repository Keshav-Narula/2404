#include <iostream>
#include <string>

#define NUMSTUDENTS 3
using namespace std;

class Student{
    public:
        string name;
        string number;
        string major;
        float gpa;
};

void print(Student& stu);

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

    cout<<"Printing all students:"<<endl<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        print(students[i]);
    }

    cout<<"Printing all passing students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        if (students[i].gpa < 6.0) continue;
        print(students[i]);
    }

}

void print(Student& stu){
    cout<<stu.name<<endl;
    cout<<stu.number<<endl;
    cout<<stu.major<<endl;
    cout<<stu.gpa<<endl<<endl;
}
