#include <iostream>
using namespace std;

#include "MyMap.h"


int main()
{
  MyMap<int,string, 10> map;

  MyMap<int,string, 5> map2;

  map.add(10, "Bobby");
  map.add(22, "Mike");
  map.add(99, "Wayne");
  map.add(65, "Joe");
//  map.add(67, "Sue");

  cout<<endl;
  cout<<map;
  cout<<endl;

  return 0;
}


