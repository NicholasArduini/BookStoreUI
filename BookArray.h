#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include <iostream>
#include <string>

#include "Book.h"

using namespace std;

class BookArray {
  public:
    BookArray();
    ~BookArray();
    void add(Book*);
    Book* getBook(int);
    int  getSize();
  private:
    int  size;
    Book* books[MAX_BOOKS];
};

#endif
