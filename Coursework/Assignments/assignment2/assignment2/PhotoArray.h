#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Photo.h"
#include "defs.h"

using namespace std;

class PhotoArray {
   public:
    PhotoArray();
    PhotoArray(const PhotoArray& oldArray) ;
    ~PhotoArray();


    bool isFull() const;
    bool add(Photo* const photo);
    bool add(Photo* const photo, const int& index);

    Photo* get(const string& title) const;
    Photo* get(const int& index) const;
    Photo* remove(const string& title);
    Photo* remove(const int& index);
    int size() const;

    void print() const;

   private:
    Photo** elements;
    int numPhotos;
};
#endif