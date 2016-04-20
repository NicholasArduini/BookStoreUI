#ifndef Shopper_h
#define Shopper_h

#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

#include "defs.h"
#include "Product.h"
#include "DList.h"
#include "AdminAccount.h"

using namespace std;

class Shopper {
public:
    Shopper(string="");
    ~Shopper();
    string  getName();
    void setName(string s);
    string toString();
    bool equalsString(string&);
    void addProduct(Product*);
    DList<Product*>* getCart();
    string _to_string(int value);
    void checkout(int, string, string, AdminAccount&);
    void getPrice(int, string, string, int&);
private:
    string    name;
    int cartPriceBeforeTax;
    string receipt;
    DList<Product*> *productCart;
};

#endif
