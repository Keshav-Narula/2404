#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>

// #include "Location.h"
#include "Entity.h"

using namespace std;

class Driver : public Entity {
   public:
   Driver(const string& nameParam = "Unknown Driver", const Location& locationParam = Location(0,0));
   ~Driver();

   bool isFree() const;
   void print() const;
   
   private:
    static const char code;
    static int nextId;
};

#endif