#ifndef D_LIST_H
#define D_LIST_H

#include <iostream>
#include <string>
#include <sstream>

#include "Course.h"

using namespace std;

template <class T>
class DList
{
    class Node
    {
        friend class DList;
        
    private:
        T data;
        Node*   next;
        Node*   prev;
    };
    
    friend ostream& operator<<(ostream&, DList&);
public:
    DList();
    ~DList();
    void cleanupData();
    void cleanup();
    void add(T);
    void remove(T);
    T find(string&);
    T find(int&);
    int getSize();
    string formatIncreasing();
    string formatDecreasing();
    DList& operator+=(T);
    DList& operator+=(DList&);
    DList& operator-=(T);
    DList& operator-=(DList&);
private:
    Node* head;
    int size;
};


template<class T>
ostream& operator<<(ostream& out, DList<T>* items) {
    out << "\n\n" << "ALL COURSES:" << "\n\n"
    << "\nIncreasing" << "\n" << items->formatIncreasing() << "\n"
    << "\nDecreasing" << "\n" << items->formatDecreasing() << "\n";
    
    return out;
}

template<class T>
DList<T>::DList() : head(0), size(0) { }

template<class T>
DList<T>::~DList() {
    cleanup();
}

template<class T>
void DList<T>::cleanupData() {
    Node *currNode = head;
    
    while (currNode != 0) {
        delete currNode->data;
        currNode = currNode->next;
    }
    
    size = 0;
}

template<class T>
void DList<T>::cleanup() {
    Node *currNode, *nextNode;
    
    currNode = head;
    
    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    
    head = 0;
}

template<class T>
void DList<T>::add(T item) {
    Node* currNode = head;
    Node* prevNode = 0;
    
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = 0;
    newNode->prev = 0;
    
    while (currNode != 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    if (prevNode == 0) {
        head = newNode;
        newNode->prev = 0;
    } else {
        prevNode->next = newNode;
        newNode->prev = prevNode;
    }
    
    if (currNode != 0) {
        currNode->prev = newNode;
    }
    
    newNode->next = currNode;
    size++;
}

template<class T>
void DList<T>::remove(T item) {
    Node* currNode = head;
    Node* prevNode = 0;
    
    while (currNode != 0) {
        if (currNode->data == item) {
            break;
        }
        
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    if (currNode == 0) {
        return;
    }
    
    if (prevNode == 0) {
        head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }
    
    if(currNode->next != 0){
        currNode->next->prev = prevNode;
    }
    
    size--;
    delete currNode->data;
    delete currNode;
}

template<class T>
T DList<T>::find(string& search) {
    Node* currNode = head;
    while (currNode != 0) {
        if (currNode->data->equalsString(search)) {
            return currNode->data;
        }
        currNode = currNode->next;
    }
    return T();
}

template<class T>
T DList<T>::find(int& index) {
    Node* currNode = head;
    int count = 0;
    while (currNode != 0) {
        if (count == index) {
            return currNode->data;
        }
        count++;
        currNode = currNode->next;
    }
    return T();
}

template<class T>
int DList<T>::getSize() { return size; }

template<class T>
string DList<T>::formatIncreasing() {
    string returnValue = "";
    Node* currNode = head;
    
    while (currNode != 0) {
        returnValue.append(currNode->data->toString());
        returnValue.append("\n");
        currNode = currNode->next;
    }
    return returnValue;
}

template<class T>
string DList<T>::formatDecreasing() {
    string returnValue = "";
    Node* currNode = head;
    Node* prevNode = 0;
    
    while (currNode != 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    currNode = prevNode;
    
    while (currNode != 0) {
        returnValue.append(currNode->data->toString());
        returnValue.append("\n");
        
        currNode = currNode->prev;
    }
    return returnValue;
}

template<class T>
DList<T>& DList<T>::operator+=(T item) {
    this->add(item);
    
    return *this;
}

template<class T>
DList<T>& DList<T>::operator+=(DList& items) {
    
    Node* curNode = items.head;
    
    while(curNode != 0){
        this->add(curNode->data);
        curNode = curNode->next;
    }
    
    return *this;
}

template<class T>
DList<T>& DList<T>::operator-=(T item) {
    this->remove(item);
    
    return *this;
}

template<class T>
DList<T>& DList<T>::operator-=(DList& items) {
    
    Node* curNode = items.head;
    while(curNode != 0){
        this->remove(curNode->data);
        curNode = curNode->next;
    }
    
    return *this;
}

#endif

