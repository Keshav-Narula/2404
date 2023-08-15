#include <iostream>
using namespace std;

int max(int, int, int);

int max(int, int);

template <typename T>
T max (T, T, T);

int main()
{
  cout<<endl;
  cout<<"max int:   "<<max(33, 22, 44)<<endl;
  cout<<"max float: "<<max(3.14f, 9.99f, 3.45f)<<endl;
  cout<<"max char:  "<<max('Z', 'z', 'c') <<endl;
  cout << endl;

  // cout << "max two ints: " << max(44, 55) <<endl;
  // cout << "max double:   " << max(44.4, 55.5, 77.8) <<endl;

  return 0;
}

int max(int v1, int v2, int v3)
{
  cout<<"In non-templated function"<<endl;
  int maxValue = v1;

  if (v2 > maxValue)
    maxValue = v2;

  if (v3 > maxValue)
    maxValue = v3;

  return maxValue;
}


template <class T>
T max(T v1, T v2, T v3){
  T maxValue = v1;

  if (v2 > maxValue)
    maxValue = v2;

  if (v3 > maxValue)
    maxValue = v3;

  return maxValue;
}