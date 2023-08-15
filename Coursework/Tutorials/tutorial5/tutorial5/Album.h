#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <iomanip>

#include "PhotoArray.h"

using namespace std;

class Album {

public:
    Album(const string& titleParam,const string& descriptionParam);
    Album(const Album& album);
    ~Album();

    string getTitle() const;
    bool equals(const string& s) const;
    bool lessThan(const Album& alb) const;
    bool addPhoto(Photo* const photo);
    bool addPhoto(const int& index, Photo* const photo);
    Photo* getPhoto(const string& titleParam) const;
    Photo* getPhoto(const int& index) const;
    Photo* removePhoto(const string& titleParam);
    Photo* removePhoto(const int& index);

    void print() const;
    void display() const;
    int size() const;





private:
    string title;
    string description;
    PhotoArray* photos;
};
#endif