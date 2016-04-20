#include "Course.h"

Course::Course(string s, string nu, string na, string i, int e)
{
    subj  = s;
    num   = nu;
    name  = na;
    instr = i;
    enrol = e;
    books = new BookArray();
}

Course::~Course()
{
    delete books;
}

string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()     { return enrol; }

int    Course::getNumBooks()  { return books->getSize(); }

void   Course::addBook(Book* b)
{
    books->add(b);
}

string Course::booksToString()
{
    string returnValue = "";
        
    stringstream ss;
    string edition;
    string year;
    
    for(int i = 0; i < books->getSize(); i++){
        returnValue.append("\n" + books->getBook(i)->toString());
    }
    
    return returnValue;
}

string Course::toString()
{
    string returnString = "\nCourse:      ";
    returnString.append(getCode());
    returnString.append(" " + name);
    returnString.append("\nInstructor: " + instr);
    
    stringstream ss;
    ss << enrol;
    
    returnString.append("\nEnrolment:  " + ss.str());
    returnString.append("\nTextbooks: " + booksToString());
    
    return returnString;
}

bool Course::equalsString(string& string){
    return (getCode().compare(string) == 0);
}

