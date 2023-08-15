#ifndef ALBUM_H
#define ALBUM_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Array.h"
#include "Photo.h"

using namespace std;

class Album {
    friend ostream& operator<<(ostream &, const Album&);

   public:
    Album(const string &title, const string &description);
    bool equals(const string &title) const;
    void addPhoto(Photo *);
    Photo *getPhoto(const int index) const;
    int size() const;
    void print(ostream &ost) const;
    void display(ostream &ost) const;



   private:
    string title;
    string description;
    // PhotoArray* photos;
    Array<Photo *> photos;
};
#endif