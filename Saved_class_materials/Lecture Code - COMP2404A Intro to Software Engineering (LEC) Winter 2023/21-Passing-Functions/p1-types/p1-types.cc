#include <iostream>
#include <string>

using namespace std;

int add(int x, int y){
    return x+y;
}

int mult(int x, int y){
    return x * y;
}

int subtract(int x, int y){
    return x - y;
}

int main(){
    int x, y, op;
    cout<<"Input 2 integers: ";
    cin >> x >> y;
    cout<<"Input an operation: "<<endl;
    cout<<" 1) addition\n 2) multiplication \n 3) subtraction ";
    cin >> op;

    switch(op){
        case 1: cout<<x<<" + "<<y<<" = "<<add(x,y)<<endl; break;
        case 2: cout<<x<<" * "<<y<<" = "<<mult(x,y)<<endl; break;
        case 3: cout<<x<<" - "<<y<<" = "<<subtract(x,y)<<endl; break;
    }
}