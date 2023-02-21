#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"
#include "Egg.h"

class Chicken : public Animal
{
  public:
    Chicken(string="Chicky", int=0, float=0, int=0, const string& info="mini");
    ~Chicken();
    void print() const;

  private:
    int eggCount;
    Egg myEggInfo;
};

#endif
