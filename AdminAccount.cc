#include "AdminAccount.h"

AdminAccount::AdminAccount(int b)
{
    balance = b;
    for (int i=0; i<MAX_SHOPPERS; ++i) {
        receipts[i] = "";
    }
    numReceipts = 0;
}

AdminAccount::~AdminAccount()
{
}

string AdminAccount::getReceipt(int index){
    return receipts[index];
}

void AdminAccount::addReceipt(string receipt){
    receipts[numReceipts] = receipt;
}

int AdminAccount::getNumReceipts(){
    return numReceipts;
}

void AdminAccount::addBalance(int b){
    balance += b;
    numReceipts++;
}

int AdminAccount::getBalance(){
    return balance;
}

