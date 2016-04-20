#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

#include "defs.h"
#include "BookArray.h"
#include "sstream"

using namespace std;

class Course {
  public:
    Course(string="", string="", string="", string="", int=0);
    ~Course();
    string  getCode();
    string  getName();
    string  getInstr();
    int     getEnrol();
    int     getNumBooks();
    void    addBook(Book*);
    string  booksToString();
    string  toString();
    bool equalsString(string&);
  private:
    string    subj;
    string    num;
    string    name;
    string    instr;
    int       enrol;
    BookArray* books;
};

#endif

