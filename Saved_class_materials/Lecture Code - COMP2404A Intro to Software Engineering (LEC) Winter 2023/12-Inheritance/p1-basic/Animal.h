#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal
{
  public:
    Animal(const string& name ="Al", int=0, float=0);
    ~Animal();
    string getName() const;
    int    getAge()  const;
    void   print()   const;
    
  protected:
    float  lifespan;

  private:
    
    string name;
    int    age;
};

#endif
