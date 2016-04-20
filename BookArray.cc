#include "BookArray.h"

BookArray::BookArray()
{
    size = 0;
    for(int i = 0; i < MAX_BOOKS; ++i){
        books[i] = 0;
    }
}

BookArray::~BookArray()
{
    for(int i = 0; i < size; ++i){
        delete books[i];
    }
}

int   BookArray::getSize()         { return size; }
Book*  BookArray::getBook(int i)   { return books[i]; }

void BookArray::add(Book* book)
{
    if (size == MAX_BOOKS)
        return;
    
    books[size] = book;
    size++;
}

