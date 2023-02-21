#ifndef BOOK_H
#define BOOK_H

class Book
{
  public:
    Book(string="", string="");
    Book(Book&);
    ~Book();
    void print() const;
    //
    static int getNextId();

  private: 
  //Global variable  accesible by all the book classes (Initialzed in file scope), Bad form to make it public, so give it a static getter
    static int nextId; //Must be initialzed, cant wait for the constructor to intialize it, since its technically not part of the object 
    int id;
    string title;
    string author;
};

#endif
