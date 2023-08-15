#ifndef DANCEB_H
#define DANCEB_H

#include <iostream>
using namespace std;

class DanceBehaviour{
    public:
        virtual void dance() = 0;
};

class CantDance: public DanceBehaviour{
    public:
        virtual void dance();
};

class Fly: public DanceBehaviour{
    public:
        virtual void dance();
};

class ChickenDance: public DanceBehaviour{
    public:
        virtual void dance();
};

class Roll: public DanceBehaviour{
    public:
        virtual void dance();
};

class Pounce: public DanceBehaviour{
    public:
        virtual void dance();
};

#endif

