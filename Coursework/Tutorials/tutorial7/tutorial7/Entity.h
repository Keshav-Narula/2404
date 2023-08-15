#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

//#include "Location.h"
#include "Queue.h"
#include "defs.h"

using namespace std;

class Entity {
   public:
    Entity(const char& charParam, const int& intParam, const string& nameParam, const Location& locationParam);
    ~Entity();

    // Location* getLocation() const;
    void setLocation(Location* const locationParam);

    Order* getNextOrder();

    int getNumOrders() const;

    void addOrder(Order* const order);

    void print() const;

    bool equals(const string& idParam);

   protected:
    string id;
    string name;

    Location* location;
    Queue* orders;
};

#endif