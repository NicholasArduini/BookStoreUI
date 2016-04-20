#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "DList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

#include "UImanager.h"
#include "Computer.h"
#include "Sweater.h"
#include "WaterBottle.h"
#include "Shopper.h"

using namespace std;

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Course**);
    void getBookData(DList<Course*>*);
    void getDeleteData(string*);
    void printCourses(DList<Course*>*);
    void printCourseBooks(DList<Course*>*);
    void pause();
    void courseNotFound();
    void addCoursesMenu(int*);
    void deleteCoursesMenu(int*);
    void addProductMenu(int*);
    void shoppingCartMenu(int*);
    void continueToPayMenu(int*, int);
    void checkoutMenu(int&, string&, string&);
    void exitORcontinue(int* choice);
    void getComputerData(Product*[], int&);
    void getWaterBottleData(Product*[], int&);
    void getSweaterData(Product*[], int&);
    void getBookData(Product*[], int&);
    void printInventory(Product*[], int&);
    void printCart(Product*[], int&);
    void getShopperData(Shopper**);
    void getFindName(string&);
    void shopperNotFound();
    void wrongPassword();
    void scanCode(Shopper*, Product*[], int&);
    bool adminMenu();
    void loginMenu(int* choice);
    void companyBalance(int);
    void showName(string);
  private:
    int getInt();
};

#endif

