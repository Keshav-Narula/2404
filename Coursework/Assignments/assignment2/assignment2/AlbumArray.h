#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Album.h"
#include "defs.h"

using namespace std;

class AlbumArray {
   public:
    AlbumArray();
    AlbumArray(const AlbumArray& oldArray) ;
    ~AlbumArray();


    bool isFull() const;
    bool add(Album* const alb);
    
    Album* get(const string& title) const;
    Album* get(const int& index) const;
    Album* remove(const string& title);
    Album* remove(const int& index);
    int size() const;

    void print() const;
    void display() const;

   private:
    Album** albums;
    int numAlbums;
};
#endif