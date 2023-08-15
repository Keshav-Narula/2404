#include <iostream>
using namespace std;
#include <string>
#include <vector>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(string n="") : name(n) {cout<<"Animal constructor"<<endl; }
    virtual ~Animal() { cout << "-- animal " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- animal "<<name<<" speaks!"<<endl; }
    
    // abstract function
    virtual void dance() { cout<< "-- animal "<<name<<" dances!"<<endl; };

  protected:
    string name;
};


class Bird : public Animal
{
  public:
    Bird(string n="") : Animal(n) { }
    virtual ~Bird() { cout << "-- bird " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- bird "<<name<<" say tweet-tweet!"<<endl; }
    virtual void dance() { cout<< "-- bird "<<name<<" flies away!"<<endl; }

};

class Chicken : public Bird
{
  public:
    Chicken(string n="") : Bird(n) { }
    virtual ~Chicken() { cout << "-- chicken " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- chicken "<<name<<" say cluck-cluck!"<<endl; }
    virtual void dance() { cout<< "-- chicken "<<name<<" scratches the ground!"<<endl; }

};

class Cat : public Animal
{
  public:
    Cat(string n="") : Animal(n) { }
    virtual ~Cat() { cout << "-- cat " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- cat "<<name<<" say meow!"<<endl; }
    virtual void dance() { cout<< "-- cat "<<name<<" runs up a tree!"<<endl; }

};

class Pig : public Animal
{
  public:
    Pig(string n="") : Animal(n) { }
    virtual ~Pig() { cout << "-- pig " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- pig "<<name<<" say oink!"<<endl; }
    virtual void dance() { cout<< "-- pig "<<name<<" rolls in the mud!"<<endl; }

};


int main()
{
//  Animal*  al      // = new Animal("Al");
  Bird*    tweety   = new Bird("Tweety");
  Chicken* redHen   = new Chicken("Little Red Hen");
  Cat*     lily     = new Cat("Lily");
  Pig*     wilbur   = new Pig("Wilbur");

  Animal* ap = redHen;
  Animal& ar = *redHen;

  vector<Animal> barnyard;

  barnyard.push_back(*tweety);
  barnyard.push_back(*redHen);
  barnyard.push_back(*lily);
  barnyard.push_back(*wilbur);

  cout << endl << "Barnyard noises..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i].speak();

  cout << endl << "Barnyard dance..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i].dance();
  
  cout << endl <<endl << "Barnyard slaughter..." << endl;
  // for (int i=0; i<barnyard.size(); ++i)
  //   delete barnyard[i];

  
  
  return 0;
}

