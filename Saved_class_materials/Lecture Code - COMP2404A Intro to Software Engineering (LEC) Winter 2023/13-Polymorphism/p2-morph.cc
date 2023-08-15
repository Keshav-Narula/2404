#include <iostream>
using namespace std;
#include <string>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(string n="") : name(n) { }
    Animal(Animal& an):name(an.name){cout<<"--Animal copy ctor"<<endl;}
    virtual void speak() { cout<< "-- animal "<<name<<" speaks!"<<endl; }

  public:
    string name;
};

class Bird : public Animal
{
  public:
    Bird(string n="") : Animal(n) { }
    virtual void speak() { cout<< "-- bird "<<name<<" says tweet-tweet!"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(string n="") : Bird(n) { }
    virtual void speak() { cout<< "-- chicken "<<name<<" says cluck-cluck!"<<endl; }
    
};

void makespeak(Animal a);
//void makespeak(Chicken& c);
void makespeak(Animal* a);
//void makespeak(Chicken* c);


int main()
{
 
  Chicken chicky("Chicky");
  Bird tweety("Tweety");

  makespeak(chicky);
  // chicky.speak();
  
  // Animal*  ap = &chicky;
  // ap->speak();
  // ap=&tweety;
  // ap->speak();
  //Chicken* cp = &chicky;

  Animal& ar = chicky;
  //Chicken& cr = chicky;

  cout<<"Speaking using animal reference"<<endl;
  ar.speak();


  // cout << "Chicken using Animal pointer"<<endl;
  // //makespeak(ap);
  // ap->speak();
  // cout << "Chicken using Animal reference"<<endl;
  // //makespeak(ar);
  // ar.speak();
  // cout << "Chicken using Chicken pointer"<<endl;
  // //makespeak(cp);
  // cp->speak();
  // cout << "Chicken using Chicken reference"<<endl;
  // makespeak(cr);
  // //cr.speak();

  
  return 0;
}

void makespeak(Animal a){
  cout<<"Animal reference speak"<<endl;
  a.speak();
}

void makespeak(Animal* a){
  cout<<"Animal pointer speak"<<endl;
  a->speak();
}





void makespeak(Chicken& c){
  cout<<"Chicken reference speak"<<endl;
  c.speak();
}

void makespeak(Chicken* c){
  cout<<"Chicken pointer speak"<<endl;
  c->speak();
}