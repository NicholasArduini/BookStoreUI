#include "WaterBottle.h"

WaterBottle::WaterBottle(string n, int p, string u, int y, string l, string m) : Product(n, p, u, y)
{
    logo = l;
    ml   = m;
    coupon = 0.5;
    discountOnCredit = 0.1;
}

string WaterBottle::getMl()   { return ml;   }
string WaterBottle::getLogo() { return logo; }

string WaterBottle::toString(){
    string returnValue = "--Water Bottle--\n";
    
    stringstream ss;
    string editionString;
    
    returnValue.append(Product::toString());
    returnValue.append("\nAmount: " + ml + "ml");
    
    returnValue.append("\nLogo: " + logo + "\n");
    
    return returnValue;
}

void WaterBottle::checkout(string& receipt, int& couponNumber, string& paymentMethod){
    string s = name + " ............... $" + _to_string(price) + " USD\n   " + logo + " -" + ml + "ml- UPC:" + upc + "\n";
    
    if(paymentMethod.compare("Credit") == 0){
        s += "      Credit discount: $" + _to_string((int)(price* (discountOnCredit))) + "\n";
    }
    
    if(couponNumber % 2 == 0 && couponNumber % 5 == 0){
        s += "      Coupon discount: $" + _to_string((int)(price* (coupon))) + "\n";
    }
    
    receipt += s;
}

void WaterBottle::priceAdjust(int& couponNumber, string& currency, string& paymentMethod, int& total){
    int newPrice = price;
    
    //coupon
    if(couponNumber % 2 == 0 && couponNumber % 5 == 0){
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