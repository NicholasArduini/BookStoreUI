# BookStoreUI

* C++ program that resembles a book store management system in which a user can
  * add courses
    * in which many courses or one course can be added at a time
  * list courses
  * delete courses
    * in which many courses or one course can be deleted at a time
  * add textbooks to specific courses
  * list the textbooks of a course
  * add products
  * list the inventory of products
  * add a new shopper
  * find a shopper and check out
    * if a shopper is found UPC codes can be scanned to be added to the cart, the cart can be viewed, and the shopper can checkout
    * at the checkout stage the user has the option to enter a coupon, each product reacts to different coupons. The user now has the option to pay in USD or CAD currency. As well as the option to pay with cash or credit, offering minimal but different discounts for credit depending on the product 
    * the shopper can now see the balance of the cart and can decide to continue to pay or exit
    * if the shopper pays a receipt is generated polymorphically calling the priceAdjust and checkout function of each product
    * the shopper's name is now removed from the current list of shoppers
  * list current shoppers
  * login as administer to see current days sales as well as previous receipts
    * password is "carleton"
  
* This program implements
  * overloaded functions 
    * in the DList class for += when one item is being added and += for another list being added
    * in the DList class for += when one item is being removed and += for another list being removed
    * the Dlist class also overloads the stream insertion operator
  * a templated DList to be able to contain any object type
  * dynamically allocated UImanger, controller, courses, textbooks, products, arrays, and DList's as well as properly deallocating all memory
  * polymorphism for listing products, adjusting prices, and creating receipts
  
  
  
  
