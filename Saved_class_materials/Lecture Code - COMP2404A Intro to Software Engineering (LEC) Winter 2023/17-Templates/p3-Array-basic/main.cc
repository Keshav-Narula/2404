#include <iostream>
using namespace std;

#include "List.h"
#include "Book.h"


int main()
{
  List<Book*> listBooks;
  List<int>  arrInts;


  Book b1("Ender's Game", "Orson Scott Card");
  Book b2("Dune", "Frank Herbert");
  Book b3("Foundation", "Isaac Asimov");
  Book b4("Hitch Hiker's Guide to the Galaxy", "Douglas Adams");

  listBooks.add(&b1);
  listBooks.add(&b2);
  listBooks.add(&b3);
  listBooks.add(&b4);
  
  cout<<"List of Books:"<<endl<<endl;

  for (int i = 0; i < 4; ++i){
    cout<<*listBooks[i]<<endl;
  }
  

  for(int i = 0; i <5; ++i){
    arrInts.add(i);
  }

  cout<<"List of ints:"<<endl<<endl;
  cout<<arrInts;
  return 0;
}

