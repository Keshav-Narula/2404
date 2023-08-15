#include <iostream>
using namespace std;
#include <string>
#include <vector>

#include "Animals.h"

int main()
{
  Bird*     tweety = new Bird("Tweety");
  Chicken*  redHen   = new Chicken("Little Red Hen");
  Cat*      lily     = new Cat("Lily");
  Pig*      wilbur   = new Pig("Wilbur");

  vector<Animal*> barnyard;

  barnyard.push_back(tweety);
  barnyard.push_back(redHen);
  barnyard.push_back(lily);
  barnyard.push_back(wilbur);

  cout<<endl<<"Barnyard harmony:"<<endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->speak();

  cout<<endl<<"Barnyard dance:"<<endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->dance();

  cout<<"Wilbur breaks a leg"<<endl<<endl;

  wilbur->setDanceB(new CantDance);

  cout<<endl<<"Barnyard dance:"<<endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->dance();

  cout<<endl<<"Barnyard slaughter:"<<endl;
  for (int i=0; i<barnyard.size(); ++i)
    delete barnyard[i];


  return 0;
}

