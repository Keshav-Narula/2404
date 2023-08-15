#include <iostream>
using namespace std;

#include "MapItem.h"
#define MAX_SIZE  4

int main()
{
  MapItem<int, string> map[MAX_SIZE];

  cout<<endl;

  map[0].set(10, "Bobby");
  map[1].set(22, "Mike");
  map[2].set(99, "Wayne");
  map[3].set(65, "Joe");

  for (int i=0; i<MAX_SIZE; ++i)
    cout<<map[i];

  cout<<endl;


  MapItem<string,float> grades[MAX_SIZE];
  grades[0].set("Timmy", 11.9f);
  grades[1].set("Harold", 6.3f);
  grades[2].set("Matilda", 10.5f);
  grades[3].set("Stanley", 9.9f);

  for (int i=0; i<MAX_SIZE; ++i)
    cout << grades[i];

  cout<<endl;


  return 0;
}

