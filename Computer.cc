#include "Computer.h"

Computer::Computer(string n, int p, string u, int y, string b, int d) : Product(n, p, u, y)
{
    brand  = b;
    driveSize = d;
    coupon = 0.1;
    discountOnCredit = 0.01;
}

string Computer::getBrand()   { return brand; }
int Computer::getDriveSize()  { return driveSize; }

string Computer::toString(){
    string returnValue = "--Computer--\n";
    
    stringstream ss;
    string driveSizeString;
    
    returnValue.append(Product::toString());
    returnValue.append("\nBrand: " + brand);
    
    ss << driveSize;
    driveSizeString = ss.str();
    
    returnValue.append("\nDrive Size: " + driveSizeString + " GB\n");
    
    return returnValue;
}

void Computer::checkout(string& receipt, int& couponNumber, string& paymentMethod){
    string s = name + " ............... $" + _to_string(price) + " USD\n   " + brand + " -" + _to_string(driveSize) + "GB- UPC:" + upc + "\n";
    
    if(paymentMethod.compare("Credit") == 0){
        s += "      Credit discount: $" + _to_string((int)(price* (discountOnCredit))) + "\n";
    }
    
    if(couponNumber % 2 == 0 && couponNumber % 3 == 0){
        s += "      Coupon discount: $" + _to_string((int)(price* (coupon))) + "\n";
    }

    receipt += s;
}

void Computer::priceAdjust(int& couponNumber, string& currency, string& paymentMethod, int& total){
    int newPrice = price;
    
    //coupon
    if(couponNumber % 2 == 0 && couponNumber % 3 == 0){
        newPrice -= price * coupon;
    }
    
    //payment method
    if(paymentMethod.compare("Credit") == 0){
        newPrice -= price * discountOnCredit;
    }
    
    //currency
    if(currency.compare("CAD") == 0){
        newPrice *= canadianDollar;
    }
    
    total += newPrice;
}


