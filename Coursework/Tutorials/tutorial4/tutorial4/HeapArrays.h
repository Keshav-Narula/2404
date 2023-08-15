#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include <iostream>
#include <string>

#include "Photo.h"
#include "defs.h"

using namespace std;

class HeapArrays {
   public:
    HeapArrays();
    ~HeapArrays();
    Photo* getObjectArray();
    Photo** getPointerArray();

    void addPhoto(Photo&);

   private:
    Photo* photos = new Photo[ARR_SIZE];
    Photo** photoPointers = new Photo*[ARR_SIZE];

    int numPhotos;
};
#endif