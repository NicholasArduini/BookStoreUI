#ifndef Sweater_hpp
#define Sweater_hpp

#include <stdio.h>
#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"

using namespace std;

class Sweater : public Product {
  public:
    Sweater(string="", int=0, string="", int=0, string="", string="");
    string  getSize();
    string  getColor();
    string  toString();
    void checkout(string&, int&, string&);
    void priceAdjust(int&, string&, string&, int&);
  private:
    string    size;
    string    color;
};

#endif
