#include <iostream>
using namespace std;
#include <cstdlib>

#include "MapItem.h"

template <class T, class V, int capacity>
class MyMap
{
template <class A, class B, int c>
  friend ostream& operator<<(ostream&, const MyMap<A,B, c>&);
  public:
    MyMap();
    void add(T, V);

  private:
    int size;
    MapItem<T,V>* arr;
};

template <class T, class V, int c>
MyMap<T,V,c>::MyMap()
{ 
  size = 0;
  arr  = new MapItem<T,V>[c];
}

template <class T, class V, int c>
void MyMap<T,V, c>::add(T k, V v) 
{ 
  if (size >= c) {
    cout << "ERROR:  map is full" << endl;
    exit(1);
  }

  arr[size].set(k, v);
  ++size;
}

template <class T, class V, int c>
ostream& operator<<(ostream& output, const MyMap<T,V, c>& m)
{ 
  for (int i=0; i<m.size; ++i)
    output << m.arr[i];

  return output;
}
