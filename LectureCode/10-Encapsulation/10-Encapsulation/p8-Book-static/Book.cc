#include <iostream>
using namespace std;
#include <string>
#include "Book.h"

int Book::nextId = 1001; //Initilze the static varaible

Book::Book(string t, string a)
{
  id = nextId++;
  title  = t;
  author = a;
  cout<<"-- default ctor:  "<< id <<endl;
}

Book::Book(Book& orig)
{
  cout<<"-- copy ctor:  "<< orig.id <<endl;

  id     = orig.id;
  title  = orig.title;
  author = orig.author;
}

//Dont use the staic keyword in the 
int Book::getNextId(){return nextId;}

Book::~Book()
{
  cout<<"-- dtor:  "<< id <<endl;
}


void Book::print() const
{
  cout<<"Id: " << id << "** "<< title <<" by "<<author<<endl;

  cout<<endl<<"NextId: "<<nextId<<endl;
}

