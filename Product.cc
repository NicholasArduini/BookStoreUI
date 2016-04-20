#include "Product.h"

Product::Product(string n, int p, string u, int y)
{
    name  = n;
    price = p;
    upc   = u;
    year  = y;
    coupon = 0.0;
    discountOnCredit = 0.0;
    canadianDollar = 1.31;
}

Product::~Product()
{
    
}

string Product::getName()   { return name;  }
int Product::getPrice()  { return price; }
string Product::getUPC()    { return upc;   }
int    Product::getYear()   { return year;  }

string Product::toString(){
    string returnValue = "";
    
    stringstream ss;
    string edition;
    string yearString;
    
    returnValue.append(name + " - $" + _to_string(price) + "\n");
    returnValue.append("UPC: " + upc + "\n");
    
    ss << year;
    yearString = ss.str();
    
    returnValue.append("Year: " + yearString);
    
    return returnValue;
}

string Product::_to_string(int value)
{
    ostringstream os ;
    os << value ;
    
    return os.str() ;
}