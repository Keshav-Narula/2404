#include <iostream>
#include <string>
#include <functional>

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

void invoke(int x, int y, int func (int, int)){
        cout<<"The result of your operation is "<<func(x,y)<<endl;
}

void invoke2(int x, int y, const function<int (int, int)> func){
        cout<<"The result of your operation is "<<func(x,y)<<endl;
}

template <typename F>
void invoke3(int x, int y, F func){
        cout<<"invoke 3"<<endl;
        cout<<"The result of your operation is "<<func(x,y)<<endl;
}

template <typename T, typename F>
void invoke4(T x, T y, F func){
        cout<<"invoke 4"<<endl;
        cout<<"The result of your operation is "<<func(x,y)<<endl;
}

int main(){
    int x, y, op;
    cout<<"Input 2 integers: ";
    cin >> x >> y;
    cout<<"Input an operation: "<<endl;
    cout<<" 1) addition\n 2) multiplication \n 3) subtraction ";
    cin >> op;

    switch(op){
        case 1: invoke3(x, y, add); break;
        case 2: invoke3(x, y, mult); break;
        case 3: invoke3(x, y, subtract); break;
    }

    string (*cat)(string, string);
    int (&operation)(int, int)= subtract;


    invoke4("Hello", " there", [x, y](string s1, string s2)->string{
            cout<<"x + y ="<<x + y<<endl;
            return s1 + s2;
    });

}