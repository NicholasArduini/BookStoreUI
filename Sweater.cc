#include "Sweater.h"

Sweater::Sweater(string n, int p, string u, int y, string s, string c) : Product(n, p, u, y)
{
    size  = s;
    color = c;
    coupon = 0.4;
    discountOnCredit = 0.06;
}

string Sweater::getSize()   { return size; }
string Sweater::getColor()  { return color; }

string Sweater::toString(){
    string returnValue = "--Sweater--\n";
    
    stringstream ss;
    string editionString;
    
    returnValue.append(Product::toString());
    returnValue.append("\nSize: " + size);
    
    returnValue.append("\nColor: " + color + "\n");
    
    return returnValue;
}

void Sweater::checkout(string& receipt, int& couponNumber, string& paymentMethod){
    string s = name + " ............... $" + _to_string(price) + " USD\n   " + size + " -" + color + "- UPC:" + upc + "\n";
    
    if(paymentMethod.compare("Credit") == 0){
        s += "      Credit discount: $" + _to_string((int)(price* (discountOnCredit))) + "\n";
    }
    
    if(couponNumber % 8 == 0 && couponNumber % 3 == 0){
        s += "      Coupon discount: $" + _to_string((int)(price* (coupon))) + "\n";
    }
    
    receipt += s;
}

void Sweater::priceAdjust(int& couponNumber, string& currency, string& paymentMethod, int& total){
    int newPrice = price;
    
    //coupon
    if(couponNumber % 8 == 0 && couponNumber % 3 == 0){
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