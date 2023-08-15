#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <iomanip>


//#include "Location.h"
#include "Queue.h"
#include "defs.h"

using namespace std;

class Entity {
   public:
    Entity(const char& charParam, const int& intParam, const string& nameParam, const Location& locationParam);
    ~Entity();

    Location* getLocation() const{return location;};
    string getId() const{return id;};


    void setLocation(const Location* locationParam);

    Order* getNextOrder();

    int getNumOrders() const;

    void addOrder(Order* const order);

    void print() const;

    bool equals(const string& idParam);

   protected:
    const string id;
    const string name;

    Location* location;
    Queue* orders;
};

#endif