#include <iostream>
using namespace std;
#include <string>

#include "Animals.h"

Animal::Animal(string n) : name(n) 
{ 
  
}

void Animal::dance(){
    cout<<name<<" ";
    danceB->dance();
    cout<<"!"<<endl;
}

void Animal::setDanceB(DanceBehaviour* db){
    delete danceB;
    danceB=db;
}



// void Animal::setDanceB(DanceBehaviour* b)
// {
  
// }

Bird::Bird(string n) : Animal(n)     {
    danceB = new Fly;
}
Chicken::Chicken(string n) : Bird(n) { 
    danceB = new ChickenDance;
}
Cat::Cat(string n) : Animal(n)       { 
    danceB =new Pounce;
}
Pig::Pig(string n) : Animal(n)       { 
    danceB = new Roll;
}


void Bird::speak()    { cout << "--bird " << name << " says tweet-tweet!" << endl; }
void Chicken::speak() { cout << "--chicken " << name << " says cluck-cluck!" << endl; }
void Cat::speak()     { cout << "--cat " << name << " says meow!" << endl; }
void Pig::speak()     { cout << "--pig " << name << " says oink!" << endl; }



