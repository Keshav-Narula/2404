#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//Default operatioin s set to the Add Operation, Specified in the function declaration not in the implementation
//Also the default arguemnts mus tbe placed on the far right of the parameters

void doTheMath(float x=0, float y=0, char op = '+');

int main()
{
  doTheMath(2, 2); //addition by default 
  doTheMath(2, 2, '/');
  doTheMath(1, 2, '/');
  doTheMath(10.5f, 20, '*');
  doTheMath();


  return 0;
}
//Default arguemnts can also be placed 
void doTheMath(float x, float y, char op)
{
  float answer;
  //Checks the 
  if (op == '+') answer = x + y;
  if (op == '-') answer = x - y;
  if (op == '*') answer = x * y;
  if (op == '/') answer = x / y;
  //Fixed precison to 2 decimals
  cout <<fixed<<setprecision(2) << x << " " <<op <<" "<< y <<" = " << answer <<endl;;
}

