#include "PhotoGram.h"

PhotoGram::PhotoGram() {
}
PhotoGram::~PhotoGram() {
    for (int i = 0; i < albums.size(); ++i) {
        delete albums[i];
    }
    // for (int i = 0; i < photoMasterlist.size(); ++i) {
    //     delete photoMasterlist[i];
    // }
}

void PhotoGram::addAlbum(const string& albumTitle, const string& descriptionParam) {
    albums += factory.createAlbum(albumTitle, descriptionParam);
}

bool PhotoGram::addToAlbum(const int& index, const Array<Photo*>& photosParam) {
    if (index >= 0 && index < albums.size()) {
        for (int i = 0; i < photosParam.size(); i++) {
            albums[index]->addPhoto(photosParam[i]);
            photoMasterlist += photosParam[i];
        }
        return true;
    }
    return false;
}

void PhotoGram::uploadPhoto(const string& titleParam) {
    photoMasterlist += factory.uploadPhoto(titleParam);
}

bool PhotoGram::deleteAlbum(const int& i) {
    if (i >= 0 && i < albums.size()) {
        albums -= albums[i];
        return true;

    } else {
        cout << "DeleteAlbum() FAILED : BAD INDEX - " << i << endl;
        return false;
    }
}

void PhotoGram::getPhotos(const Criteria& c, Array<Photo*>& photosParam) const {
    for (int i = 0; i < photoMasterlist.size(); i++) {
        if (c.matches(*photoMasterlist[i])) {
            photosParam.add(photoMasterlist[i]);
        }
    }
}

void PhotoGram::displayAlbum(int index, View& v) const {
    if (index >= 0 && index < albums.size()) {
        v.displayAlbum(*albums[index]);
    } else {
        cout << "displayAlbum() FAILED : BAD INDEX - " << index << endl;
    }
}
int PhotoGram::printAlbums(View& v) const {
    v.printAlbums(albums);
    return albums.size();
}
void PhotoGram::displayPhoto(int index, View& v) const {
    if (index >= 0 && index < photoMasterlist.size()) {
        v.displayPhoto(*photoMasterlist[index]);
    } else {
        cout << "displayPhoto() FAILED : BAD INDEX - " << index << endl;
    }
}

int PhotoGram::printPhotos(View& v) const {
    v.printPhotos(photoMasterlist);
    return photoMasterlist.size();
}
