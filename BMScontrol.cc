#include "BMScontrol.h"

BMScontrol::BMScontrol()
{
    view = new UImanager();
    courses = new DList<Course*>();
    shoppers = new DList<Shopper*>();
    
    for (int i=0; i<MAX_PRODUCTS; ++i) {
        products[i] = 0;
    }
    
    numProducts = 0;
    account = AdminAccount(); //account password is "carleton"
    
    
    //added product items to make testing more convenient
    //coupon code divisable by 2 and 3 so a valid coupon is: 12
    Computer* c1 = new Computer("ZenBook", 1999, "123", 2015, "Asus", 512); //upc = 123
    Computer* c2 = new Computer("Mac Pro", 3999, "456", 2014, "Apple", 512); //upc = 456
    
    //coupon code divisable by 5 and 3 so a valid coupon is: 15
    Book* b1 = new Book("The Hunger Games", 20, "11", 2012, "Suzanne Collins" , "134543", 1); //upc = 11
    Book* b2 = new Book("Harry Potter", 25, "22", 2008, "J.K. Rowling" , "527542", 1); //upc = 22
    
    //coupon code divisable by 5 and 2 so a valid coupon is: 10
    WaterBottle* w1 = new WaterBottle("Nalgene", 15, "12", 2012, "Ravens", "1000"); //upc = 12
    
    //coupon code divisable by 8 and 3 so a valid coupon is: 24
    Sweater* s1 = new Sweater("Womens Hoodie", 45, "34", 2015, "medium", "red"); //upc = 34
    Sweater* s2 = new Sweater("Mens Hoodie", 45, "56", 2015, "medium", "blue"); //upc = 56
    
    products[numProducts++] = c1;
    products[numProducts++] = c2;
    products[numProducts++] = b1;
    products[numProducts++] = b2;
    products[numProducts++] = w1;
    products[numProducts++] = s1;
    products[numProducts++] = s2;
}

BMScontrol::~BMScontrol()
{
    delete view;
    courses->cleanupData();
    delete courses;
    
    shoppers->cleanupData();
    delete shoppers;
    
    for(int i = 0; i < numProducts; ++i){
        delete products[i];
    }
}

void BMScontrol::launch()
{
    int    choice;
    string code;
    
    while (1) {
        choice = -1;
        view->mainMenu(&choice);
        if (choice == 0) { //on exit
            break;
        } else if (choice == 1) { //add courses
            int addChoice = -1;
            view->addCoursesMenu(&addChoice);
            
            if(addChoice == 1){
                Course* newCourse;
                view->getCourseData(&newCourse);
                *courses += newCourse;
            } else if(addChoice == 2){
                DList<Course*> *newCourses = new DList<Course*>();
                addChoice = -1;
                
                while(true){
                    if(addChoice == 0){
                        *courses += *newCourses;
                        break;
                    } else{
                        Course* newCourse;
                        view->getCourseData(&newCourse);
                        *newCourses += newCourse;
                    }
                    
                    view->exitORcontinue(&addChoice);
                }
                delete newCourses;
            }
        } else if (choice == 2) { //list courses
            cout << courses << endl;
        } else if (choice == 3) { //delete courses
            int delChoice = -1;
            view->deleteCoursesMenu(&choice);
            
            if(choice == 1){
                string input;
                view->getDeleteData(&input);
                Course* answer = courses->find(input);
                if (answer != 0) {
                    *courses -= answer;
                } else {
                    view->courseNotFound();
                }
            } else if(choice == 2){
                DList<Course*> *delCourses = new DList<Course*>();
                delChoice = -1;
                
                while(true){
                    if(delChoice == 0){
                        *courses -= *delCourses;
                        break;
                    } else{
                        string input;
                        view->getDeleteData(&input);
                        Course* answer = courses->find(input);
                        if (answer != 0) {
                            *delCourses += answer;
                        } else {
                            view->courseNotFound();
                        }
                    }
                    view->exitORcontinue(&delChoice);
                }
                delete delCourses;
            }
        } else if (choice == 4) { //add textbook
            view->getBookData(courses);
        } else if (choice == 5) { //list course textbook
            view->printCourseBooks(courses);
        } else if(choice == 6){ //add a product
            int productChoice = -1;
            
            view->addProductMenu(&productChoice);
            
            if(productChoice == 1){
                view->getBookData(products, numProducts);
            } else if(productChoice == 2){
                view->getComputerData(products, numProducts);
            } else if(productChoice == 3){
                view->getSweaterData(products, numProducts);
            } else if(productChoice == 4){
                view->getWaterBottleData(products, numProducts);
            }
        } else if(choice == 7){ //list inventory
            view->printInventory(products, numProducts);
        } else if(choice == 8){ //find shopper
            string findName = "";
            view->getFindName(findName);
            
            if(shoppers->find(findName)){
                view->showName(shoppers->find(findName)->getName());
                
                while(true){
                    view->shoppingCartMenu(&choice);
                    
                    if(choice == 1){
                        view->scanCode(shoppers->find(findName), products, numProducts);
                    } else if(choice == 2){
                        cout << shoppers->find(findName)->toString() << endl;
                    } else if(choice == 3){
                        int payChoice;
                        int total = 0;
                        int coupon = 0;
                        string currency = "";
                        string payment = "";
                        view->checkoutMenu(coupon, currency, payment);
                        
                        shoppers->find(findName)->getPrice(coupon, currency, payment, total);
                        view->continueToPayMenu(&payChoice, total);
                        
                        if(payChoice == 1){
                            shoppers->find(findName)->checkout(coupon, currency, payment, account);
                            *shoppers -= shoppers->find(findName);
                        }
                        break;
                    } else if(choice == 0) {
                        break;
                    }
                }
            } else {
                view->shopperNotFound();
            }
        } else if(choice == 9){ //add shopper
            Shopper* newShopper;
            view->getShopperData(&newShopper);
            *shoppers += newShopper;
        } else if(choice == 10){ //list shoppers and their carts
            cout << shoppers->formatIncreasing() << endl;
        } else if(choice == 11){
            if(view->adminMenu()){
                view->loginMenu(&choice);
                if(choice == 1){
                    view->companyBalance(account.getBalance());
                } else if(choice == 2){
                    for(int i = 0; i < account.getNumReceipts(); i++){
                        cout << endl << account.getReceipt(i) << endl;
                    }
                }
            } else {
                view->wrongPassword();
            }
        }
        
        view->pause();
    }
}

