#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <iostream>
#include <string>

#include "Entity.h"



using namespace std;

class Franchise : public Entity {
   public:
   Franchise(const string& nameParam = "Unknown Franchise", const Location& locationParam = Location(0,0));
   ~Franchise();

   void print() const;
   static void printMenu();
   static string getMenu(const int& index);

   
   private:
    static const char code;
    static int nextId;
    static const string menu[MENU_ITEMS];
};

#endif