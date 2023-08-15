#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Album.h"
#include "Array.h"
#include "MediaFactory.h"
#include "Photo.h"
#include "View.h"

using namespace std;

class PhotoGram {
   public:
    PhotoGram();
    ~PhotoGram();

    void addAlbum(const string& albumTitle, const string& descriptionParam);
    bool addToAlbum(const int& index, const Array<Photo*>& photosParam);
    void uploadPhoto(const string& titleParam);
    bool deleteAlbum(const int& index);
    void getPhotos(const Criteria& c, Array<Photo*>& photosParam) const;

    void displayAlbum(int index, View& v) const;
    int printAlbums(View& v) const;
    void displayPhoto(int index, View& v) const;
    int printPhotos(View& v) const;


   private:
    Array<Album*> albums;
    Array<Photo*> photoMasterlist;
    MediaFactory factory;
};
#endif