#include <iostream>
using namespace std;
#include <string>
#include <vector>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(string n="") : name(n) { }
    Animal(const Animal& an):name(an.name){cout<<"--Animal copy ctor of "<<name<<endl;}
    virtual void speak() { cout<< "-- animal "<<name<<" speaks!"<<endl; }

  protected:
    string name;
};

class Bird : public Animal
{
  public:
    Bird(string n="") : Animal(n) { }
    virtual void speak() { cout<< "-- bird "<<name<<" say tweet-tweet!"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(string n="") : Bird(n) { }
    virtual void speak() { cout<< "-- chicken "<<name<<" say cluck-cluck!"<<endl; }
};

class Cat : public Animal
{
  public:
    Cat(string n="") : Animal(n) { }
    virtual void speak() { cout<< "-- cat "<<name<<" say meow!"<<endl; }
};


int main()
{
  Animal  alObj("Al");
  Bird    tweetyObj("Tweety");
  Chicken redHenObj("Little Red Hen");
  Cat     lilyObj("Lily");

  Animal*  al = new Animal("Al");
  Bird*    tweety = new Bird("Tweety");
  Chicken* redHen   = new Chicken("Little Red Hen");
  Cat*     lily     = new Cat("Lily");

  vector<Animal> barnyardObj;

  vector<Animal*> barnyard;

  // Animal ams[3];

  // ams[0] = tweetyObj;

  // cout<<"Two birds speaking!"<<endl;
  // tweetyObj.speak();
  // ams[0].speak();



  barnyardObj.push_back(alObj);
  barnyardObj.push_back(tweetyObj);
  barnyardObj.push_back(redHenObj);
  barnyardObj.push_back(lilyObj);

  barnyard.push_back(al);
  barnyard.push_back(tweety);
  barnyard.push_back(redHen);
  barnyard.push_back(lily);

  // barnyard harmony using objects and pointers

  

  return 0;
}

