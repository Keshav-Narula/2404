#include <iostream>
using namespace std;

#include <string>
#include <cstdlib>

#define MAX_BUF  80

void testExtractOp();
void testEOF();
void testGet();
void testGetLine();


int main()
{

  //testExtractOp();

  //testEOF();


  //testGet();

  testGetLine();

  return 0;
}


void testExtractOp()
{
  string s1, s2;
  int    num;

  cout<<endl<<"*** Testing stream extraction operator: ***"<<endl;

  cout << "Enter <str> <str> <num>:" << endl;

  while ( cin >> s1 >> s2 >> num ) {
    cout<<"you said: "<<s1<<" * "<<s2<<" * "<<num<<endl;
  }

  if (cin.good()){
    cout<<"all is well"<<endl;
  }else{
    cout<<"something wrong"<<endl;
  }
}

void testEOF()
{
  string str;

  cout<<endl<<"*** Testing end of file function: ***"<<endl;

  cout << "Enter <str>:" << endl;
  cin >> str;

  while (!cin.eof()) {
    cout<<"you said: "<<str<<endl;
    cin >> str;
  }

  cout << "all done" << endl;
}

void testGet()
{
  string str;
  char   c;

  cout<<endl<<"*** Testing get function: ***"<<endl;

  cout << "Enter <str>:" << endl;
  c = cin.get();

  //cout<<c;

  while ( c != '\n') { 
    str += c;
    c = cin.get();
  }
  cout<<"you said: "<<str<<endl;
}

void testGetLine()
{
  char str[MAX_BUF];

  cout<<endl<<"*** Testing getline function: ***"<<endl;

  cout << "Enter <str> terminated by <enter>:" << endl;
  
  cin.getline(str, MAX_BUF);
  cout<<"you said: "<<str<<endl;

  cout << "Enter <str> terminated by *:" << endl;
  cin.getline(str, MAX_BUF, '*');
  cout<<"you said: "<<str<<endl;

}

