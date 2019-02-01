//
//  list.h
//  Battleship Project
//
//  Created by Aaron Bloomfield on 10/10/18.
//  CPSC 340 Section 1

#ifndef LISTH
#define LISTH

#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

template <typename LISTTYPE>
class List
{
public:
    
    //Default constructor
    //sets all values to zero
    List();
    
    //return True if the list is empty; otherwise returns false
    bool isEmpty() const;
    
    //return the number of items stored in the list.
    int getSize() const;
    
    //Inserts an item into the list at position index.
    void insert(const LISTTYPE newItem);
 
    //Inserts an item into the list at position index.
    void replace(const LISTTYPE newItem, int index);
    
    // Deletes an item from the list at a given position.
    // returns -1 if nothing can be removed
    LISTTYPE remove(int index);
    
    // Retrieves a list item by position.
    // returns true if found
    // passes back what is in the index spot if boolean is true
    bool retrieve(int index, LISTTYPE &value) const;
    
    
    // Output all elements.
    void print() const;
    
    //sorts the list using any algorithm from scratch
    //including the zeros
    void sort();
private:
    
    // array of list items
    LISTTYPE items[MAX_SIZE];
    
    //number of items
    int size;
    
};//end List
//end file.
#include "list.cpp"
#endif /* LISTS_H */
