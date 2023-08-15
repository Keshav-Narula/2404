#include "PhotoArray.h"


PhotoArray::PhotoArray()
    : numPhotos(0), elements(new Photo*[MAX_ARRAY]) {
}

PhotoArray::PhotoArray(const PhotoArray& oldArray):
    numPhotos(oldArray.numPhotos), elements(new Photo*[MAX_ARRAY])
{
    for(int i = 0; i < oldArray.numPhotos; ++i){
        elements[i] = new Photo(*oldArray.elements[i]);
    }
}


/*
    Usually bad form to delete elements in a list,
    since they may be stored in more than one list.
    However, we can delete the List.
*/
PhotoArray::~PhotoArray() {
    for (int i = 0; i < numPhotos; ++i) {
        delete elements[i];
    }
    delete[] elements;
    
}

bool PhotoArray::isFull() const {
    if (numPhotos >= (MAX_ARRAY - 1)) {
        return true;
    } else {
        return false;
    }
}
bool PhotoArray::add(Photo* const photo) {
    if (this->isFull() == false) {
        elements[numPhotos] = photo;
        numPhotos++;
        return true;
    } else {
        return false;
    }
    // Photo* newPhoto = new Photo();
    // photo = newPhoto;
}
// Try to pass int by reference
bool PhotoArray::add(Photo* const photo, const int& index) {
    if (index >= MAX_ARRAY || index < 0 || this->isFull() == true) {
        return false;
    }
    if (index >= numPhotos) {
        return (this->add(photo));
    }

    for (int i = numPhotos; i > 0; --i) {
        if (i != index) {
            // keep making space by copying elements
            // one location to the right
            elements[i] = elements[i - 1];
        } else {
            // we have found where s should go
            elements[i] = photo;
            ++numPhotos;
            return true;
        }
    }

    elements[0] = photo;
    ++numPhotos;
    return true;
}

Photo* PhotoArray::get(const string& title) const {
    for (int i = 0; i < numPhotos; ++i) {
        if (title == elements[i]->getTitle()) {
            return elements[i];
        }
    }
    return nullptr;
}

Photo* PhotoArray::get(const int& index) const {
    if (index >= MAX_ARRAY || index < 0 || index >= numPhotos) {
        return nullptr;
    }

    return elements[index];
}
Photo* PhotoArray::remove(const string& title) {
    Photo* returnPhoto;
    int index = 0;
    // we want to find the index of the element to remove
    while (title != elements[index]->getTitle() && index < numPhotos) {
        ++index;
    }

    // did we fall off the end of the List?
    if (index == numPhotos) return nullptr;

    // we have found what we wanted to remove,
    // assign the output value
    returnPhoto = elements[index];
    // copy everything after index left one position
    while (index < numPhotos - 1) {
        elements[index] = elements[index + 1];
        ++index;
    }
    --numPhotos;
    return returnPhoto;
}
Photo* PhotoArray::remove(const int& index) {
    if (index >= MAX_ARRAY || index < 0 || index >= numPhotos) {
        return nullptr;
    }
    Photo* returnPhoto = elements[index];
    int counter = index;
    while (counter < numPhotos - 1) {
        elements[counter] = elements[counter + 1];
        ++counter;
    }
    --numPhotos;
    return returnPhoto;
}

int PhotoArray::size() const {
    return numPhotos;
}

void PhotoArray::print() const{
    for(int i =0; i < numPhotos; i++){
        elements[i]->display();
    }
}

