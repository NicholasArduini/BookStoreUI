#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include <iostream>

#include "defs.h"
#include "UImanager.h"
#include "Shopper.h"
#include "DList.h"
#include "AdminAccount.h"

using namespace std;

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
  private:
    UImanager* view;
    DList<Course*> *courses;
    Product* products[MAX_PRODUCTS];
    int numProducts;
    DList<Shopper*> *shoppers;
    AdminAccount account;
};

#endif

