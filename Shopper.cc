#include "Shopper.h"

Shopper::Shopper(string n)
{
    name  = n;
    productCart = new DList<Product*>();
    cartPriceBeforeTax = 0;
    receipt = "";
}

Shopper::~Shopper()
{
    delete productCart;
}

string Shopper::getName()  { return name; }
DList<Product*>* Shopper::getCart()  { return productCart; }

void Shopper::setName(string s)  {name = s;}

void Shopper::addProduct(Product* product){
    productCart->add(product);
}

string Shopper::_to_string(int value)
{
    ostringstream os ;
    os << value ;
    
    return os.str() ;
}

void Shopper::getPrice(int coupon, string currency, string payment, int& total){
    for(int i = 0; i < productCart->getSize(); i++){
        productCart->find(i)->priceAdjust(coupon, currency, payment, total);
    }
}

void Shopper::checkout(int coupon, string currency, string payment, AdminAccount& account){
    getPrice(coupon, currency, payment, cartPriceBeforeTax);
    
    receipt = "\n\n*************************************************************\n";
    
    if(productCart->getSize() > 0){
        receipt += "\n" + name + "'s receipt payed with " + payment + "\nCarleton Book Store\n\nItems:\n";
        
        for(int i = 0; i < productCart->getSize(); i++){
            productCart->find(i)->checkout(receipt, coupon, payment);
        }
        
        receipt += "\n\nSub Total .................. $" + _to_string((int)cartPriceBeforeTax) + " " + currency;
        receipt += "\nTax 13% .................... $" + _to_string((int)(cartPriceBeforeTax * 0.13)) + " " + currency;
        receipt += "\nTotal ...................... $" + _to_string((int)(cartPriceBeforeTax * 1.13)) + " " + currency;
        receipt += "\n\nThank you for shopping at the Carleton Book Store\n" ;
    }
    
    receipt += "\n*************************************************************\n";
    
    account.addReceipt(receipt);
    if(currency.compare("CAD") == 0){
        account.addBalance((int)((cartPriceBeforeTax * 1.13) * 0.77));
    }
    
    cout << receipt << endl;
}

string Shopper::toString(){
    string returnString = "\nName: " + name + "\nCart:\n";
    returnString.append(productCart->formatIncreasing());
    
    int cartTotal = 0;
    for(int i = 0; i < productCart->getSize(); i++){
        cartTotal += productCart->find(i)->getPrice();
    }
    
    returnString.append("Total before cart price before checkout $" + _to_string(cartTotal) + " USD\n");
    
    return returnString;
}

bool Shopper::equalsString(string& string){
    return (name.compare(string) == 0);
}