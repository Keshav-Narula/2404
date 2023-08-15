#include <iostream>
#include <string>

#define NUMSTUDENTS 3
using namespace std;

int main(){
    string names[NUMSTUDENTS] = {"Joe", "Amy", "Barb"};
    string numbers[NUMSTUDENTS] = {"101111111", "101222222", "101333333"};
    string major[NUMSTUDENTS] = {"CS", "Math", "History"};
    float gpa[NUMSTUDENTS] = {10.0f, 11.2f, 5.9f};

    cout<<"Printing all students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        cout<<names[i]<<endl;
        cout<<numbers[i]<<endl;
        cout<<major[i]<<endl;
        cout<<gpa[i]<<endl<<endl;
    }

    cout<<"Printing all passing students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        if (gpa[i] < 6.0) continue;
        cout<<names[i]<<endl;
        cout<<numbers[i]<<endl;
        cout<<major[i]<<endl;
        cout<<gpa[i]<<endl<<endl;
    }


}