#ifndef BOOKARRAY_H
#define BOOKARRAY_H

#include "Book.h"


class BookArray
{
  friend ostream& operator<<(ostream&, BookArray&);
  public:
    BookArray(int=10);
    ~BookArray();

    Book& operator[](int);
    BookArray& operator=(BookArray&);
    bool operator==(BookArray&);

  private:
    int   capacity;
    Book* elements;
};

#endif

