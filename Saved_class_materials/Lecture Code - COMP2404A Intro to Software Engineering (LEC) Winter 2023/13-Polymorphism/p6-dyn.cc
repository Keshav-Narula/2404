#include <iostream>
using namespace std;
#include <string>
#include <vector>

// VERY BAD PACKAGING

// Dynamic casting

class Animal
{
  public:
    Animal(string n="") : name(n) { }
    virtual ~Animal() { cout << "-- animal " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- animal "<<name<<" speaks!"<<endl; }
    virtual void dance() = 0;

  protected:
    string name;
};

class Bird : public Animal
{
  public:
    Bird(string n="") : Animal(n) { }
    virtual ~Bird() { cout << "-- bird " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- bird "<<name<<" say tweet-tweet!"<<endl; }
    virtual void dance() { cout<< "-- bird "<<name<<" flies"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(string n="") : Bird(n) { }
    virtual ~Chicken() { cout << "-- chicken " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- chicken "<<name<<" say cluck-cluck!"<<endl; }
    virtual void dance() { cout<< "-- chicken "<<name<<" does the chicken dance" << endl; }
};

class Cat : public Animal
{
  public:
    Cat(string n="") : Animal(n) { }
    virtual ~Cat() { cout << "-- cat " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- cat "<<name<<" say meow!"<<endl; }
    virtual void dance() { cout<< "-- cat "<<name<<" pounces" << endl; }
};

class Pig : public Animal
{
  public:
    Pig(string n="") : Animal(n) { }
    virtual ~Pig() { cout << "-- pig " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- pig "<<name<<" say oink!"<<endl; }
    virtual void dance() { cout<< "-- pig "<<name<<" rolls in the mud"<<endl; }
};


int main()
{
//  Animal*  al = new Animal("Al");
  Bird*    tweety = new Bird("Tweety");
  Chicken* redHen   = new Chicken("Little Red Hen");
  Cat*     lily     = new Cat("Lily");
  Pig*     wilbur   = new Pig("Wilbur");

  vector<Animal*> barnyard;

//  barnyard.push_back(al);
  barnyard.push_back(tweety);
  barnyard.push_back(redHen);
  barnyard.push_back(lily);
  barnyard.push_back(wilbur);

  cout << endl << "Barnyard harmony..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->speak();

  cout << endl << "Barnyard dance..." << endl;
  for (int i=0; i<barnyard.size(); ++i) {
    barnyard[i]->dance();
    // we want to check for the Cat using dynamic casting
    Cat* cat = dynamic_cast<Cat*>(barnyard[i]);
    if (cat != 0){
      cout<<" the cat fell out of the tree and cried"<<endl;
      cat->speak();
    }
  }

  cout << endl << "Barnyard slaughter..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    delete barnyard[i];


  return 0;
}

