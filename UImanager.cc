#include "UImanager.h"

void UImanager::mainMenu(int* choice)
{
    string str;
    
    *choice = -1;
    
    cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
    cout << "  Course Management:" << endl;
    cout << "  ( 1 )  Add course(s)" << endl;
    cout << "  ( 2 )  List all courses" << endl;
    cout << "  ( 3 )  Delete Course(s)" << endl << endl;
    cout << "  Textbook Management:" << endl;
    cout << "  ( 4 )  Add textbook" << endl;
    cout << "  ( 5 )  List course textbooks" << endl << endl;
    cout << "  Product Management:" << endl;
    cout << "  ( 6 )  Add a product" << endl;
    cout << "  ( 7 )  List inventory" << endl << endl;
    cout << "  Cash Register Management:" << endl;
    cout << "  ( 8 )  Find shopper and checkout" << endl;
    cout << "  ( 9 )  Add shopper" << endl;
    cout << "  ( 10 ) List shoppers" << endl << endl;
    cout << "  Manger System:" << endl;
    cout << "  ( 11 )  Login" << endl << endl;
    cout << "  ( 0 )  Exit" << endl << endl;
    
    while (*choice < 0 || *choice > 11) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
}

bool UImanager::adminMenu(){
    string p = "";
    cout << endl << "Enter the admin password:  ";
    getline(cin, p);

    if(p.compare("carleton") == 0){
        return true;
    } else {
        return false;
    }
}

void UImanager::loginMenu(int* choice){
    string str;
    
    *choice = -1;
    
    cout << endl;
    cout << "  ( 1 )  Show company balance" << endl;
    cout << "  ( 2 )  View all receipts" << endl << endl;
    cout << "  ( 0 )  Exit" << endl << endl;
    
    while (*choice < 0 || *choice > 2) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
}

void UImanager::showName(string name){
    cout << endl << "Welcome " << name << endl;
}

void UImanager::companyBalance(int balance){
    cout << endl << "The current company balance is $" << balance << " USD" << endl << endl;
}

void UImanager::exitORcontinue(int* choice){
    cout << endl << "Enter 0 to exit or any number to continue" << endl;
    *choice = getInt();
}

void UImanager::addCoursesMenu(int* choice){
    string str;
    
    *choice = -1;
    
    cout << endl;
    cout << "  ( 1 )  Add a single course" << endl;
    cout << "  ( 2 )  Add many courses" << endl << endl;
    cout << "  ( 0 )  Exit" << endl << endl;
    
    while (*choice < 0 || *choice > 2) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
}


void UImanager::deleteCoursesMenu(int* choice){
    string str;
    
    *choice = -1;
    
    cout << endl;
    cout << "  ( 1 )  Delete a single course" << endl;
    cout << "  ( 2 )  Delete many courses" << endl << endl;
    cout << "  ( 0 )  Exit" << endl << endl;
    
    while (*choice < 0 || *choice > 2) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
}

void UImanager::addProductMenu(int* choice){
    
    *choice = -1;
    
    cout << endl;
    cout << "  ( 1 )  Add a book" << endl;
    cout << "  ( 2 )  Add a computer" << endl;
    cout << "  ( 3 )  Add a sweater" << endl;
    cout << "  ( 4 )  Add a water bottle" << endl << endl;
    cout << "  ( 0 )  Exit" << endl << endl;
    
    while (*choice < 0 || *choice > 4) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
}

void UImanager::shoppingCartMenu(int* choice){
    
    *choice = -1;
    
    cout << endl;
    cout << "  ( 1 )  Scan Code" << endl;
    cout << "  ( 2 )  View cart" << endl;
    cout << "  ( 3 )  Checkout" << endl << endl;
    cout << "  ( 0 )  Exit" << endl << endl;
    
    while (*choice < 0 || *choice > 3) {
        cout << "Enter your selection:  ";
        *choice = getInt();
    }
}

void UImanager::continueToPayMenu(int* choice, int total){
    
    *choice = -1;
    
    cout << endl << "The total before taxes is $" << total << endl << endl;
    
    cout << endl;
    cout << "  ( 1 )  Contiune to pay" << endl;
    cout << "  ( 0 )  Exit" << endl << endl;
    
    while (*choice < 0 || *choice > 1) {
        cout << "Would you like to:  ";
        *choice = getInt();
    }
}

void UImanager::checkoutMenu(int& couponNum, string& currency, string& payment){
    
    int choice = -1;
    
    string couponNumString;
    
    cout << endl << "If you have a coupon enter it now: ";
    getline(cin, couponNumString);
    stringstream(couponNumString) >> couponNum;
    
    while (choice < 0 || choice > 2) {
        cout << endl << "Enter (1) to pay in CAD or (2) to pay USD: ";
        choice = getInt();
    }
    if(choice == 1){
        currency = "CAD";
    } else {
        currency = "USD";
    }
    
    choice = -1;
    
    while (choice < 0 || choice > 2) {
        cout << endl << "Enter (1) to pay with Credit or (2) to pay with Cash: ";
        choice = getInt();
    }
    if(choice == 1){
        payment = "Credit";
    } else {
        payment = "Cash";
    }
}

void UImanager::printInventory(Product* products[], int &size){
    
    cout << endl << endl << "ALL PRODUCTS:" << endl << endl;
    
    for(int i = 0; i < size; ++i){
        cout << products[i]->toString() << endl;
    }
}

void UImanager::printCart(Product* products[], int &size){
    
    cout << endl << endl << "SHOPPING CART:" << endl << endl;
    
    for(int i = 0; i < size; ++i){
        cout << products[i]->toString() << endl;
    }
}

void UImanager::getCourseData(Course** course)
{
    string    str = "";
    string    subj, num, name, inst;
    int       enrol;
    
    cout << endl;
    
    while (str.length() != 8) {
        cout << "Enter course code (e.g. COMP2404):  ";
        getline(cin, str);
    }
    subj = str.substr(0,4);
    num  = str.substr(4);
    
    cout << endl << "Enter course name (e.g. Introduction to SE):  ";
    getline(cin, name);
    
    cout << endl << "Enter instructor name:   ";
    getline(cin, inst);
    
    cout << endl << "Enter enrolment:   ";
    getline(cin, str);
    stringstream ss(str);
    ss >> enrol;
    
    Course* tmpCourse = new Course(subj, num, name, inst, enrol);
    
    *course = tmpCourse;
}

void UImanager::getBookData(DList<Course*> *courses)
{
    string    str = "";
    string    title, authors, isbn, editionString, yearString, priceString, upc;
    int       edition, year, price;
    
    string courseCode;
    
    cout << endl;
    
    while (courseCode.length() != 8) {
        cout << "Enter course code the book belongs to (e.g. COMP2404):  ";
        getline(cin, courseCode);
    }
    
    
    if(courses->find(courseCode)){
        cout << endl << "Enter the book title:  ";
        getline(cin, title);
        
        cout << endl << "Enter the book price:  ";
        getline(cin, yearString);
        stringstream(yearString) >> year;
        
        cout << endl << "Enter the book UPC:  ";
        getline(cin, upc);
        
        cout << endl << "Enter book year:  ";
        getline(cin, yearString);
        stringstream(yearString) >> year;
        
        cout << endl << "Enter the book authors:  ";
        getline(cin, authors);
        
        cout << endl << "Enter the book isbn:  ";
        getline(cin, isbn);
        
        cout << endl << "Enter book edition:  ";
        getline(cin, editionString);
        stringstream(editionString) >> edition;
        
        Book* book = new Book(title, price, upc, year, authors, isbn, edition);
        
        courses->find(courseCode)->addBook(book);
        
        
    } else {
        cout << endl << "Sorry that course does not exist" << endl;
    }
}

void UImanager::getBookData(Product* products[], int &size){
    string    str = "";
    string    name, priceString, upc, yearString, authors, isbn, editionString;
    int       year, edition, price;
    
    cout << endl;
    
    cout << endl << "Enter the book title:  ";
    getline(cin, name);
    
    cout << endl << "Enter the book price:  ";
    getline(cin, yearString);
    stringstream(yearString) >> year;
    
    cout << endl << "Enter the book UPC:  ";
    getline(cin, upc);
    
    cout << endl << "Enter the book year:  ";
    getline(cin, yearString);
    stringstream(yearString) >> year;
    
    cout << endl << "Enter the book authors:  ";
    getline(cin, authors);
    
    cout << endl << "Enter the book isbn:  ";
    getline(cin, isbn);
    
    cout << endl << "Enter the book edition:  ";
    getline(cin, editionString);
    stringstream(editionString) >> edition;
    
    Book* book = new Book(name, price, upc, year, authors, isbn, edition);
    
    products[size] = book;
    size++;
}

void UImanager::getComputerData(Product* products[], int &size){
    string    str = "";
    string    name, priceString, upc, yearString, brand, driveSizeString;
    int       price, year, driveSize;
    
    cout << endl;
    
    cout << endl << "Enter the computer name:  ";
    getline(cin, name);
    
    cout << endl << "Enter the computer price:  ";
    getline(cin, priceString);
    stringstream(priceString) >> price;
    
    cout << endl << "Enter the computer UPC:  ";
    getline(cin, upc);
    
    cout << endl << "Enter the computer year:  ";
    getline(cin, yearString);
    stringstream(yearString) >> year;
    
    cout << endl << "Enter the computer brand:  ";
    getline(cin, brand);
    
    cout << endl << "Enter the computer drive size:  ";
    getline(cin, driveSizeString);
    stringstream(driveSizeString) >> driveSize;
    
    Computer* computer = new Computer(name, price, upc, year, brand, driveSize);
    
    products[size] = computer;
    size++;
}

void UImanager::getWaterBottleData(Product* products[], int &size){
    string    str = "";
    string    name, priceString, upc, yearString, ml, logo;
    int       price, year;
    
    cout << endl;
    
    cout << endl << "Enter the water bottle name:  ";
    getline(cin, name);
    
    cout << endl << "Enter the water bottle price:  ";
    getline(cin, priceString);
    stringstream(priceString) >> price;
    
    cout << endl << "Enter the water bottle UPC:  ";
    getline(cin, upc);
    
    cout << endl << "Enter the water bottle year:  ";
    getline(cin, yearString);
    stringstream(yearString) >> year;
    
    cout << endl << "Enter the water bottle logo:  ";
    getline(cin, logo);
    
    cout << endl << "Enter how many ml the bottle can hold:  ";
    getline(cin, ml);
    
    WaterBottle* waterBottle = new WaterBottle(name, price, upc, year, logo, ml);
    
    products[size] = waterBottle;
    size++;
}

void UImanager::getSweaterData(Product* products[], int &size){
    string    str = "";
    string    name, priceString, upc, yearString, sweaterSize, color;
    int       price, year;
    
    cout << endl;
    
    cout << endl << "Enter the sweater name:  ";
    getline(cin, name);
    
    cout << endl << "Enter the sweater price:  ";
    getline(cin, priceString);
    stringstream(priceString) >> price;
    
    cout << endl << "Enter the sweater UPC:  ";
    getline(cin, upc);
    
    cout << endl << "Enter the sweater year:  ";
    getline(cin, yearString);
    stringstream(yearString) >> year;
    
    cout << endl << "Enter the sweater size:  ";
    getline(cin, sweaterSize);
    
    cout << endl << "Enter the sweater color:  ";
    getline(cin, color);
    
    Sweater* sweater = new Sweater(name, price, upc, year, sweaterSize, color);
    
    products[size] = sweater;
    size++;
}

void UImanager::getDeleteData(string* code) {
    string str = "";
    cout << endl;
    
    while (str.length() != 8) {
        cout << "Enter course code to delete (e.g. COMP2404):  ";
        getline(cin, str);
    }
    *code = str;
}

void UImanager::printCourses(DList<Course*> *list)
{
    cout << endl << endl << "ALL COURSES:" << endl << endl;
    
    cout << "\nIncreasing" << endl << list->formatIncreasing() << endl;
    cout << "\nDecreasing" << endl << list->formatDecreasing() << endl;
    
    cout << endl;
}

void UImanager::printCourseBooks(DList<Course*> *list)
{
    string courseCode;
    cout << endl;
    
    while (courseCode.length() != 8) {
        cout << "Enter course code for whose textbooks you want to be printed (e.g. COMP2404):  ";
        getline(cin, courseCode);
    }
    
    if(list->find(courseCode)){
        if(list->find(courseCode)->booksToString().compare("") != 0){
            cout << list->find(courseCode)->booksToString();
        } else {
            cout << endl << "Sorry no textbooks for that course exists" << endl;
        }
    } else {
        cout << endl << "Sorry that course does not exist" << endl;
    }
    
}

void UImanager::getShopperData(Shopper** shopper)
{
    string    name;
    
    cout << endl;
    
    cout << endl << "Enter the shoppers name:  ";
    getline(cin, name);
    
    Shopper* tmpShopper = new Shopper(name);
    
    *shopper = tmpShopper;
}

void UImanager::getFindName(string& name){
    cout << endl;
    
    cout << "Enter the name of the shopper you want to find:  ";
    getline(cin, name);
}

void UImanager::scanCode(Shopper* shopper, Product* products[], int &size){
    string upc;
    bool found = false;
    
    while(upc.compare("0") != 0){
        found = false;
        cout << endl << "Enter or scan the UPC or 0 to exit:  ";
        getline(cin, upc);
        
        if(upc.compare("0") == 0){
            break;
        }
        
        for(int i = 0; i < size; i++){
            if(products[i]->getUPC().compare(upc) == 0){
                shopper->addProduct(products[i]);
                found = true;
            }
        }
        if(!found){
            cout << "\nProduct not found" << endl;
        }
    }
}

void UImanager::pause()
{
    string str;
    
    cout << endl << "\nPress enter to continue...";
    getline(cin, str);
}

void UImanager::courseNotFound() {
    cout << endl << "\nCourse Not Found therefore can't be deleted" << endl;
}

void UImanager::shopperNotFound() {
    cout << endl << "\nShopper Not Found" << endl;
}

void UImanager::wrongPassword() {
    cout << endl << "\nWrong Password" << endl;
}

int UImanager::getInt()
{
    string str;
    int    num;
    
    getline(cin, str);
    stringstream ss(str);
    ss >> num;
    
    return num;
}

