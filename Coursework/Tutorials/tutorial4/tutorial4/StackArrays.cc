#include "StackArrays.h"

StackArrays::StackArrays() : numPhotos(0) {
}

StackArrays::~StackArrays() {
    for (int i = 0; i < numPhotos; i++) {
        delete photoPointers[i];
    }
}

void StackArrays::addPhoto(Photo& photoParam){
    photoPointers[numPhotos] = new Photo(photoParam);
    photos[numPhotos] = photoParam;
    numPhotos++;
}

Photo* StackArrays::getObjectArray() {
    return photos;
}

Photo** StackArrays::getPointerArray() {
    return photoPointers;
}
