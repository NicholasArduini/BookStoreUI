#ifndef Product_hpp
#define Product_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

#include "defs.h"

using namespace std;

class Product {
  public:
    Product(string="", int=0, string="", int=0);
    virtual ~Product();
    string  getName();
    int  getPrice();
    string  getUPC();
    int     getYear();
    string virtual toString();
    string _to_string(int value);
    virtual void checkout(string&, int&, string&) = 0;
    virtual void priceAdjust(int&, string&, string&, int&) = 0;
  protected:
    string    name;
    int       price;
    string    upc;
    int       year;
    float     coupon;
    float     discountOnCredit;
    float     canadianDollar;
};

#endif
