
#include "Thing.h"

Thing::Thing(int i, string s)
{
  //Initialize member varaibles
  id = i;
  location = s;
  cout<<"-- ctor:  "<< id <<" "<< location <<endl;
}
//Scoped in source file
Thing::~Thing()
{

  cout<<"-- dtor:  "<< id <<" "<< location <<endl;
}

