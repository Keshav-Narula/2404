#include <iostream>
#include <string>
using namespace std;

#include "Song.h"


void passByValue(Song);
void passByReference(Song&);

Song returnByValue();


int main()
{
  cout<<endl<<"Declaring and initializing songs 1 to 4..."<<endl;

  Song s1(1, "Lounge Act", "Nirvana");
  Song s2(2, "Pain of Infinity", "The Dirty Nil");
  Song s3(3, "Black Sheep", "Metric");
  Song s4(4, "Merry Go Round", "Motley Crue");

  s1.print();
  s2.print();
  s3.print();
  s4.print();

  cout<<"Calling returnByValue()"<<endl; 
  returnByValue();
  

  cout << endl << "Declaring song 5..." << endl;
  Song s5;
  s5.print();

  //Callign copy constructor
  cout << endl << "Assigning song 4 to 5..." << endl;
  s5 = s4;
  //s5 and s4 occupy different locations in memeory along with different copies of their memory
  //Thus changing one does not change the other
  s5.print();

  cout << endl << "Declaring and initializing song 6 from song 5..." << endl;
  Song s6 = s5;
  s6.print();

  cout << endl << "Explicit call to copy ctor..." << endl;
  Song s7(s6);
  s7.print();

  cout << endl << "Calling passByValue()..." << endl;
  passByValue(s1);
  //Copy construcotr is called here Make a copy of that song, that will be the parameter that is printed here

  cout << endl << "Calling passByReference()..." << endl;
  passByReference(s1);
  //does not call copy constructor,

  

  cout << endl << "End of function" << endl;
  return 0;
}

void passByValue(Song s)
{
  s.print();
}

void passByReference(Song& s)
{
  s.print();
}

/*
* This returns an rvalue which can be used to initialize a local object
*/
Song returnByValue(){
  //Making a song it is statically allocated in that call stack and then its returned
  Song s(20, "H.Y.C.Y.BH", "Tom Cardy");
  return s;
  //Returns song but it gets destroyed, calls destrcutor as soon as functinon ends

  //
}

