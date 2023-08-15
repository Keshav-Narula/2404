#include "AlbumArray.h"

AlbumArray::AlbumArray()
    : numAlbums(0), albums(new Album*[MAX_ARRAY]) {
}
AlbumArray::AlbumArray(const AlbumArray& oldArray)
    : numAlbums(oldArray.numAlbums), albums(new Album*[MAX_ARRAY]) {
    for (int i = 0; i < oldArray.numAlbums; ++i) {
        albums[i] = new Album(*oldArray.albums[i]);
    }
}
AlbumArray::~AlbumArray() {
    // for (int i = 0; i < numAlbums; ++i) {
    //     delete albums[i];
    // }
    delete[] albums;
}

bool AlbumArray::isFull() const {
    if (numAlbums >= (MAX_ARRAY - 1)) {
        return true;
    } else {
        return false;
    }
}
bool AlbumArray::add(Album* const alb) {
    if (this->isFull() == true) {
        return false;
    }

    for (int i = numAlbums; i > 0; --i) {
        if (alb->lessThan(*albums[i - 1])) {
            // keep making space by copying elements
            // one location to the right
            albums[i] = albums[i - 1];
        } else {
            // we have found where s should go
            albums[i] = alb;
            ++numAlbums;
            return true;
        }
    }

    // we went through every location, and s was less than
    // all of them. Therefore s goes in location 0
    albums[0] = alb;
    ++numAlbums;
    return true;
}

Album* AlbumArray::get(const string& title) const {
    for (int i = 0; i < numAlbums; ++i) {
        if (title == albums[i]->getTitle()) {
            return albums[i];
        }
    }
    return nullptr;
}
Album* AlbumArray::get(const int& index) const {
    if (index >= MAX_ARRAY || index < 0 || index >= numAlbums) {
        return nullptr;
    }

    return albums[index];
}
Album* AlbumArray::remove(const string& title) {
    Album* returnAlbum;
    int index = 0;
    // we want to find the index of the element to remove
    while (title != albums[index]->getTitle() && index < numAlbums) {
        ++index;
    }

    // did we fall off the end of the List?
    if (index == numAlbums) return nullptr;

    // we have found what we wanted to remove,
    // assign the output value
    returnAlbum = albums[index];
    // copy everything after index left one position
    while (index < numAlbums - 1) {
        albums[index] = albums[index + 1];
        ++index;
    }
    albums[numAlbums] = nullptr;

    --numAlbums;
    return returnAlbum;
}
Album* AlbumArray::remove(const int& index) {
    if (index >= MAX_ARRAY || index < 0 || index >= numAlbums) {
        return nullptr;
    }
    Album* returnAlbum = albums[index];
    int counter = index;
    while (counter < numAlbums - 1) {
        albums[counter] = albums[counter + 1];
        ++counter;
    }
    albums[numAlbums] = nullptr;
    --numAlbums;
    return returnAlbum;
}
int AlbumArray::size() const {
    return numAlbums;
}

void AlbumArray::print() const {
    for (int i = 0; i < numAlbums; i++) {
        albums[i]->print();
    }
}

void AlbumArray::display() const {
    for (int i = 0; i < numAlbums; i++) {
        albums[i]->display();
    }
}
