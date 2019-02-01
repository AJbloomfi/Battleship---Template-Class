//
//  list.cpp
//  Battleship Project
//
//  Created by Aaron Bloomfield on 10/10/18.
//  CPSC 340 Section 1

#ifndef LISTCPP
#define LISTCPP
#include "list.h"

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

//Default constructor
//sets all values to zero
template <typename LISTTYPE>
List<LISTTYPE>::List(){
    size = 0;
}

//return True if the list is empty; otherwise returns false
template <typename LISTTYPE>
bool List<LISTTYPE>::isEmpty() const{
    if(size==0){
        return true;
    }else{
        return false;
    }
}

//return the number of items stored in the list.
template <typename LISTTYPE>
int List<LISTTYPE>::getSize() const{
   
   return size;
   
}

//Inserts an item into the list at position index
template <typename LISTTYPE>
void List<LISTTYPE>::insert(const LISTTYPE newItem){
    if(size < MAX_SIZE){
        items[size] = newItem;
        
        size++;
    }
}

//Inserts an item into the list at position index.
template <typename LISTTYPE>
void List<LISTTYPE>::replace(const LISTTYPE newItem, int index){
       if(index>=0 && index<=MAX_SIZE)
       {
           
           items[index] = newItem;
       }

    
}

// Deletes an item from the list at a given position.
// returns -1 if nothing can be removed
template <typename LISTTYPE>
LISTTYPE List<LISTTYPE>::remove(int index){
    LISTTYPE temp = items[index];
    for(int i=0; i<size; i++){
        if(i==index){
            for(int j=i; j<size-1; j++){
                items[j] = items[j+1];
                
            }
        }
    }
    size--;
    return temp;
}

// Retrieves a list item by position.
// returns true if found
// passes back what is in the index spot if boolean is true
template <typename LISTTYPE>
bool List<LISTTYPE>::retrieve(int index, LISTTYPE &value) const{
    
        if(index<size){
            value = items[index];
            return true;
            
        }else
            return false;
    
    
}

// Output all elements.
template <typename LISTTYPE>
void List<LISTTYPE>::print() const{
   // cout << "List contains: " << endl;
    for(int i=0; i<size; i++){
        cout << items[i] << endl;
    }
    cout << endl;
}

//sorts the list using any algorithm from scratch
//including the zeros
template <typename LISTTYPE>
void List<LISTTYPE>::sort(){
   // cout << "Sorting .........." << endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(items[j] > items[j+1]){
                LISTTYPE temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
    
}
#endif