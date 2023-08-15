#include <iostream>
using namespace std;
#include <string>
#include <sstream>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(const string& n="") : name(n) { }
    void speak() { cout<< "-- animal "<<name<<" speaks!"<<endl; }

  protected:
    string name;
};

class Cat: public Animal{
  public:
    Cat(const string& name=""):Animal(name){}
    void speak() { cout<< "-- cat "<<name<<" meows!"<<endl; }
};

class Bird : public Animal
{
  public:
    Bird(const string& n="") : Animal(n) { }
    void speak() { cout<< "-- Bird "<<name<<" tweets!"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(const string& n="") : Bird(n) { }
    void speak() { cout<< "-- Chicken "<<name<<" clucks!"<<endl; }
};



int main()
{
  // stringstream ss;

  // ss <<"\033[31m"<<"Hello"<<"\033[0m"<<" there"<<endl;
  // string s = ss.str();
  // cout <<s;

  Animal  al("Al");
  Bird    tweety("Tweety");
  Chicken redHen("Little Red Hen");
  Cat     lily("Lily");

  cout<<"Animals making a racket:"<<endl;

  al.speak();
  tweety.speak();
  redHen.speak();
  lily.speak();

  Animal*  ap;
  Bird*    bp;
  Chicken* cp;

  cout << endl << "base ptr points to base object" << endl;
  ap = &tweety;
  
  ap->speak();

  cout << "derived ptr points to derived object" << endl;
  bp = &tweety;
  cp = &redHen;
 
  bp->speak();
  cp->speak();

  cout << endl << "base ptr points to derived object" << endl;
  //ap = &lily;
  bp = &redHen;

  // ap->speak();
  bp->speak();

  cout << endl << "base reference points to derived object" << endl;
  Animal& ar = redHen;
  ar.speak();


  //cp = &tweety;



  //cout << endl << "base ptr points to derived object" << endl;
  
 


  return 0;
}

