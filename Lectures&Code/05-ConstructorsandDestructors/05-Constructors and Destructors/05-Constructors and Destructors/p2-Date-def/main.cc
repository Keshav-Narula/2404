#include <iostream>
#include <string>
#include "Date.h"
#include "Calendar.h"

using namespace std;

int main()
{
  cout << endl;

  Date d1(2022,9,23); //Created date
  d1.print();
  cout<<endl;

  Date d2; //Used the default constructor
  d2.print();
  cout<<endl;

  Date d3(2022, 10); //Suppying two arguements to the constructor
  d3.print();
  cout<<endl;

  Date d4(2022);
  d4.print();
  cout<<endl;

  //DAte* dates[20] //Array of 20 date pointers

  //Date dates[20] //Array of 20 date objects, each of these have the default constructor called on them since no arguments were supplied

  //Date dates[5] =[2022,01,5]

  //Dynamically allocate memeory
 
  //Date* d1 = new Date;
  //d1->print(); //Pritns Jan 1, 1902


  return 0;
}
