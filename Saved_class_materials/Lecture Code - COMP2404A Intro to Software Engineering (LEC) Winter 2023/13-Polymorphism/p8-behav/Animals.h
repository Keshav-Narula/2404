#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>

using namespace std;

#include "DanceBehaviour.h"


class Animal
{
  public:
    Animal(string="");
    //virtual ~Animal();
    virtual void speak()  = 0;
    virtual void dance();

    void setDanceB(DanceBehaviour*);
    
  protected:
    string name;
    DanceBehaviour* danceB;
};

class Bird : public Animal
{
  public:
    Bird(string="");
    virtual void speak();
};

class Chicken : public Bird
{
  public:
    Chicken(string="");
    virtual void speak();
};

class Cat : public Animal
{
  public:
    Cat(string="");
    virtual void speak();
  
};

class Pig : public Animal
{
  public:
    Pig(string="");
    virtual void speak();
};

#endif
