#include <iostream>
using namespace std;

#include "Time.h"


template <class T>
T max (T, T, T);

int main()
{
  cout<<endl;
  cout<<"max int:   "<<max(33, 22, 44)<<endl;
  cout<<"max float:   "<<max(33.1f, 22.3f, 44.5f)<<endl;
  
  // cout<<"max float: "<<max(3.14f, 9.99f, 3.45f)<<endl;
  cout<<"max char:  "<<max('Z', 'z', 'c') <<endl;

  Time t1(11,22);
  Time t2(13,17);
  Time t3(16,54);

  cout<<"max Time:  "<<max(t1, t2, t3) <<endl;


  return 0;
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




