#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"

using namespace std;

class Book : public Product {
  public:
    Book(string="", int=0, string="", int=0, string="", string="", int=0);
    string  getAuthors();
    string  getISBN();
    int     getEdition();
    string  toString();
    void checkout(string&, int&, string&);
    void priceAdjust(int&, string&, string&, int&);
  private:
    string    authors;
    string    isbn;
    int       edition;
};

#endif

