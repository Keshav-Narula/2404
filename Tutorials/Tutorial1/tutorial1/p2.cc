#include <iostream>
using namespace std;

int main()
{
  int x, y;

  cout << "Please enter two integers: ";
  cin >> x >> y; //Takes whatever is coming from the standard input and puts it into the variable

  cout << "The product of "<<x<<" and "<<y<< " is " << (x * y) << endl;

  return 0;
}
