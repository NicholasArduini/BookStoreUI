#ifndef WaterBottle_hpp
#define WaterBottle_hpp

#include <stdio.h>
#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"

using namespace std;

class WaterBottle : public Product {
  public:
    WaterBottle(string="", int=0, string="", int=0, string="", string="");
    string  getMl();
    string  getLogo();
    string  toString();
    void checkout(string&, int&, string&);
    void priceAdjust(int&, string&, string&, int&);
  private:
    string    ml;
    string    logo;
};

#endif
