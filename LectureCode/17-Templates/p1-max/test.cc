#include <iostream>

using namespace std;

class Computer{
    public:
    Computer(){cout<<"in comp ctor"<<endl;}
};

class HomeBuild: Computer{
    public:
    HomeBuild(){cout<<"In Homebuild ctor"<<endl;}
};

int main(){
    HomeBuild build;
    return 0;
}