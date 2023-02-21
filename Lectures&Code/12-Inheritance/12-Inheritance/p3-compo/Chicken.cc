#include <iostream>
using namespace std;
#include <string>

#include "Chicken.h"


Chicken::Chicken(string n, int a, float lf, int ec, const string& info)
    : Animal(n,a,lf), eggCount(ec), myEggInfo(info)
{ 
  cout<<"-- Chicken ctor: "<<getName()<<endl;
}

Chicken::~Chicken()
{ 
  cout<<"-- Chicken dtor: "<<getName()<<endl;
}

void Chicken::print() const  
{
  Animal::print();
  cout<<" and I'm a chicken that can produce "<<eggCount
      <<" " << myEggInfo.getSize() << " eggs daily"<<endl;
}

