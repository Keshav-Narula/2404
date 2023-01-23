#include <string>
using namespace std;

class Student{
    public:
        Student(string name, string number, string major, float gpa);
        
        void print();
        bool isPassing();

    private:
        string name;
        string number;
        string major;
        float gpa;
};