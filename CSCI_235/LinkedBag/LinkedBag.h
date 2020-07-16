//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 2 - Linked List
Date: 2/29/2020

Purpose: This is the header file for 
LinkedBag.cpp, it contains the declaration 
of the LinkedBag class and the classes public 
and private and member functions/ data members. 
The LinkedBag class inherits properties of 
the superclass BagInterface.
*/


#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   
public:

   LinkedBag();

   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   
   LinkedBag(ItemType entries[], int entryCount); //Parametrized Constructor

   virtual ~LinkedBag();                       // Destructor should be virtual

   /** Method gets size of linked list (Accessor)
   @return integer representing number of nodes */        
   int getCurrentSize() const;
   
   /** Method checks if all nodes are removed in a linked list (Accessor)
   @return true(1) if list is empty false(0) if nodes are not empty */        
   bool isEmpty() const;

   /** Method adds a new node to a linked list (Mutator)
   @return true(1) if a node has been added and false(0) 
   if a node has not been added */        
   bool add(const ItemType& newEntry);

   /** Method deletes the second node in a linked list (Mutator)
   @return true(1) if the second node has been deleted and false(0) 
   if a node has not been deleted */    
   void deleteSecondNode();

   /** Method gets current size of linked list iteratively (Accessor)
   @return an integer representing the number of nodes in the list */    
   int getCurrentSize();

   /** Method uses the function rec_get_count to access number of nodes in list (Accessor)
   @return an integer representing the number of nodes in the list */  
   int getCurrentSizeRecursive();

   /** Method is a wrapper function it gets current size of linked list recursively (Accessor)
   @param is sent the head pointer
   @return an integer representing the number of nodes in the list */  
   int rec_get_count(Node<ItemType>* headPtr);

   /** Method removes a random node in the linked list (Mutator)
   @return an data entry in the linked list */    
   ItemType removeRandom();
   
   /** Method removes one node with a specific entry data (Mutator)
   @param is the data that needs to be removed from the list.
   @return true(1) if item is removed false(0) if it stays */        
   bool remove(const ItemType& anEntry);

   /** Method removes all nodes to a linked list (Mutator)
   @return true(1) if list is emptied false(0) if nodes are not emptied */  
   void clear();

   /** Method checks if a value is in list (Accessor)
   @param is the data that needs to be removed from the list.
   @return true(1) if item is found false(0) if it is not found */ 
   bool contains(const ItemType& anEntry) const;

   /** Method counts number of times a specific entry data is in list(Accessor)
   @param is the data that needs to be removed from the list.
   @return integer representing frequency of the entry */ 
   int getFrequencyOf(const ItemType& anEntry) const;

   /** Method makes list a vector (Accessor)
   @return a string with list values */
   std::vector<ItemType> toVector() const;

}; // end LinkedBag

#include "LinkedBag.cpp"
#endif