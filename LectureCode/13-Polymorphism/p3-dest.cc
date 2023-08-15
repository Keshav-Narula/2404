#include <iostream>
using namespace std;
#include <string>
#include <vector>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(string n="") : name(n) { } 
    //SAme with the base class ad dvirtaul keyword to the destructoro and thus it destroys all the parts
    virtual ~Animal() { cout << "-- animal " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- animal "<<name<<" speaks!"<<endl; }

  protected:
    string name;
};

class Bird : public Animal
{
  public:
    Bird(string n="") : Animal(n) { }
    virtual ~Bird() { cout << "-- bird " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- bird "<<name<<" says tweet-tweet!"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(string n="") : Bird(n) { }
    virtual ~Chicken() { cout << "-- chicken " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- chicken "<<name<<" says cluck-cluck!"<<endl; }
};

class Cat : public Animal
{
  public:
    Cat(string n="") : Animal(n) { }
    virtual ~Cat() { cout << "-- cat " << name << " is destroyed!" << endl; }
    virtual void speak() { cout<< "-- cat "<<name<<" says meow!"<<endl; }
};


int main()
{
  Animal*  al       = new Animal("Al");
  Bird*    tweety   = new Bird("Tweety");
  Chicken* redHen   = new Chicken("Little Red Hen");
  Cat*     lily     = new Cat("Lily");

  vector<Animal*> vec;
  //Once you push it on to the vector it becoms an animal pointer,

  //SInce they are just animals pointers in the vector, you can tyoe cast back to a Bird pointer and now you have abird object,
  //Animal is a common base handle
  vec.push_back(al);
  vec.push_back(tweety);
  vec.push_back(redHen);
  vec.push_back(lily);


  //vector of Animals
  
  //barnyard sounds

  for(int i = 0; i < vec.size(); ++i){
    vec.at(i)->speak();
  }
  cout<<endl;


  cout<<"barnyard slaughter:"<<endl;

  //Trying to deltet the vector

  for(int i = 0; i < vec.size(); ++i){
    delete vec[i];
    cout<<endl;
  }
  //This eachlayers gets destroyed so it goes up the c=hieracrhy, so a chicken will call the animal destructor and other parts its inherited. 

  // delete al;
  // cout<<endl;
  // delete tweety;
  // cout<<endl;
  // delete redHen;
  // cout<<endl;
  // delete lily;

  return 0;
}

