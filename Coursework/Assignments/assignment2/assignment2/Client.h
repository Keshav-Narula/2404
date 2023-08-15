#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <iomanip>

#include "PhotoGram.h"

using namespace std;

class Client {

public:
    Client();
    ~Client();

    bool downloadAlbum(const PhotoGram* pg, const string& albumTitle);
    bool displayOnlinePhoto(const PhotoGram* pg, const string& albumTitle,const string& photoTitle ) const;
    bool displayLocalPhoto(const string& albumTitle, const string& photoTitle) const;

    void printLocalAlbums() const;
    void displayLocalAlbums() const;


private:
    AlbumArray* albums;

};
#endif