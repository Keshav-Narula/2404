#include "HeapArrays.h"

HeapArrays::HeapArrays() : numPhotos(0) {
}

HeapArrays::~HeapArrays() {
    for(int i = 0; i< ARR_SIZE; i++) {
        delete photoPointers[i];
    } 
    delete [] photoPointers;
    delete [] photos;
}

void HeapArrays::addPhoto(Photo& photoParam){
    photoPointers[numPhotos] = new Photo(photoParam);
    photos[numPhotos] = photoParam;
    numPhotos++;
}


Photo* HeapArrays::getObjectArray() {
    return photos;
}

Photo** HeapArrays::getPointerArray() {
    return photoPointers;
}