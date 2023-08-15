#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Photo.h"
#include "defs.h"

using namespace std;

class StackArrays {
   public:
    StackArrays();
    ~StackArrays();
    Photo* getObjectArray();
    Photo** getPointerArray();

    void addPhoto(Photo&);

   private:
    Photo photos[ARR_SIZE];
    Photo* photoPointers[ARR_SIZE];
    int numPhotos;
};
#endif