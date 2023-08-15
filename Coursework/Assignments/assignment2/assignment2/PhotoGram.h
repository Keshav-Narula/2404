#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iostream>
#include <string>
#include <iomanip>

#include "AlbumArray.h"

using namespace std;

class PhotoGram {

public:
    PhotoGram();
    ~PhotoGram();

    bool addAlbum(const string& albumTitle, const string& descriptionParam);
    bool addPhoto(const string& albumTitle, const Photo& photoParam);
    bool removePhoto(const string& albumTitle, const string& photoTitle);
    bool removeAlbum(const string& albumTitle);

    //Client Services

    Album* downloadAlbum(const string& albumTitle) const;
    Photo* downloadPhoto(const string& albumTitle, const string& photoTitle) const;

    //print
    void printAlbums() const;
    void displayAlbums() const;



private:
    AlbumArray* albums;

};
#endif