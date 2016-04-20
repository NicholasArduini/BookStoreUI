#ifndef Computer_hpp
#define Computer_hpp

#include <stdio.h>
#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"

using namespace std;

class Computer : public Product {
  public:
    Computer(string="", int=0, string="", int=0, string="", int=0);
    string  getBrand();
    int  getDriveSize();
    string toString();
    void checkout(string&, int&, string&);
    void priceAdjust(int&, string&, string&, int&);
  private:
    string  brand;
    int     driveSize;
};
#endif
