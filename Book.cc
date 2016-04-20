#include "Book.h"

Book::Book(string n, int p, string u, int y, string a, string i, int e) : Product(n, p, u, y)
{
    authors  = a;
    isbn = i;
    edition = e;
    coupon = 0.3;
    discountOnCredit = 0.05;
}


string Book::getAuthors()  { return authors; }
string Book::getISBN()     { return isbn; }
int    Book::getEdition()  { return edition; }

string Book::toString(){
    string returnValue = "--Book--\n";
    
    stringstream ss;
    string editionString;
    
    returnValue.append(Product::toString());
    returnValue.append("\nAuthors: " + authors);
    
    returnValue.append("\nISBN: " + isbn);
    
    ss << edition;
    editionString = ss.str();
    
    returnValue.append("\nEdition: " + editionString + "\n");
    
    return returnValue;
}

void Book::checkout(string& receipt, int& couponNumber, string& paymentMethod){
    string s = name + " ............... $" + _to_string(price) + " USD\n   " + authors + " -" + _to_string(edition) + " editon- UPC:" + upc + "\n";
    
    if(paymentMethod.compare("Credit") == 0){
        s += "      Credit discount: $" + _to_string((int)(price* (discountOnCredit))) + "\n";
    }
    
    if(couponNumber % 5 == 0 && couponNumber % 3 == 0){
        s += "      Coupon discount: $" + _to_string((int)(price* (coupon))) + "\n";
    }
    
    receipt += s;
}

void Book::priceAdjust(int& couponNumber, string& currency, string& paymentMethod, int& total){
    int newPrice = price;
    
    //coupon
    if(couponNumber % 5 == 0 && couponNumber % 3 == 0){
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