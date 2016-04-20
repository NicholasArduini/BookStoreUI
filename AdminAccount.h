#ifndef AdminAccount_hpp
#define AdminAccount_hpp

#include <stdio.h>
#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"
#include "DList.h"

using namespace std;

class AdminAccount {
public:
    AdminAccount(int=0);
    ~AdminAccount();
    string getReceipt(int);
    int  getNumReceipts();
    int  getBalance();
    void addBalance(int);
    void addReceipt(string);
private:
    string receipts[MAX_SHOPPERS];
    int  numReceipts;
    int  balance;
};

#endif
