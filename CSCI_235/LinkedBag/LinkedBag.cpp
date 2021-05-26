
//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */


/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 2 - Linked List
Date: 2/29/2020

Purpose: This file expands on LinkedBag.hpp and has 
the implementation of the member functions in 
the header file.
*/
#include <iostream>

using namespace std;
#include "LinkedBag.h"
#include <cstdlib>
#include "Node.h"
#include <cstddef>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(ItemType entries[], int entryCount): itemCount(0),headPtr(nullptr) 
{  //parameterized constructor adds elements in entries array into a linked list, 
   //intializes itemcount and headptr
   for(int i = 0; i < entryCount; i++)
   {
      add(entries[i]);
   }
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

/** Checks if all nodes are removed in a linked list (Accessor)
@return true(1) if list is empty false(0) if nodes are not empty */        
template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

/** Gets size of linked list (Accessor)
@return integer representing number of nodes */        
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

/************************************************************************************* STARTS HERE */

/** Adds a new node to the end of a linked list (Mutator)
@return true(1) if a node has been added and false(0) 
if a node has not been added */  
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{

   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);

   //Case 1: If there are no elements in the linked list then the headptr is assigned
   //to the new node with inputted data inside it and the item count is incremented and 
   //a true value is returned signifying the single new element being added to the list.
   if(this->headPtr == nullptr)
   {
      this->headPtr = nextNodePtr;
      itemCount++;
      return true;
   }

   //Case 2: If there are other elements a pointer is sent to the last node
   //this last node's next node is set to the new node which is then set to 
   //the nullptr. Item count is incremented and a true value is returned signifying 
   //the new element being added to the end of the list.
   else
   {
      Node<ItemType>* ptr = this->headPtr;
      while (ptr->getNext() != nullptr)
      {
         ptr = ptr->getNext();
      }
      ptr->setNext(nextNodePtr);
      nextNodePtr->setNext(nullptr);
      itemCount++;
      return true;
   }

   //A false value is returned signifying 
   //the new element is not being added to the end of the list.
   return false;
  
}  // end add

/** Deletes the second node in a linked list (Mutator)
@return true(1) if the second node has been deleted and false(0) 
if a node has not been deleted */  
template<class ItemType>
void LinkedBag<ItemType>::deleteSecondNode()
{
   //If there are 2 or more elements in the list then make a pointer thats 
   //pointing to the second element and then set the first elements next 
   //to be the third element then delete the ptr and set it to the nullptr 
   //and decrement the item count.
   if (itemCount >= 2)
   {
      if(itemCount == 2)
      {
         Node<ItemType>* ptr = this->headPtr;
         ptr->setNext(nullptr);
         itemCount--;

      }
      else
      {
         Node<ItemType>* ptr = this->headPtr;
         ptr->setNext(ptr->getNext()->getNext());
         itemCount--;
      }
   }
   /*if (itemCount >= 2)
   {
      Node<ItemType>* secondptr = headPtr->getNext();
      headPtr->setNext(secondptr->getNext());
      delete secondptr;
      secondptr = nullptr;
      itemCount--;
   }*/
}

/** Gets current size of linked list iteratively (Accessor)
@return an integer representing the number of nodes in the list */    
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize()
{  
   //Creates a pointer and and a counter. This pointer traverses the list till it 
   //reaches the nullptr and then returns the counter integer.
   int running_number_of_nodes = 0;
   Node<ItemType>* tmpptr = headPtr; 
   while (tmpptr != nullptr)
   {
      running_number_of_nodes++;
      tmpptr = tmpptr->getNext();
   }
   return running_number_of_nodes;
}


/** Is a wrapper function it gets current size of linked list recursively (Accessor)
@return an integer representing the number of nodes in the list */  
template<class ItemType>
int LinkedBag<ItemType>::rec_get_count(Node<ItemType>* uptr)
{
   if (uptr == nullptr) //base case
   {
      return 0;  
   }
   return 1 + rec_get_count(uptr->getNext()); //increase counter by 1 and call function again with next node
}

/** Uses the function rec_get_count to access number of nodes in list (Accessor)
@return an integer representing the number of nodes in the list */  
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSizeRecursive()
{
   return rec_get_count(headPtr); //sent wrapper function the headptr
}

/** Removes a random node in the linked list (Mutator)
@return an data entry in the linked list */    
template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom()
{
   int pos =  rand() % itemCount;  //generates a random number using random function   
                                   //with the range 0 to item count   

   //Case 1: If the node to be deleted is the head/first node then store the head node
   //data into a variable. Then make the head the second node and return the storage 
   //variable and decrement the item count.
   if (pos == 0)
   {
      ItemType holder_of_deleted_node = headPtr->getItem();
      headPtr = headPtr->getNext();
      itemCount--;
      return holder_of_deleted_node;
   }
   
   //Case 2: If the node to be deleted is the last node then make a pointer to the head and 
   //traverse list to second to last node. Then make a new pointer storing the last node 
   //and set the 1st ptr to null, store the value in the last node and return it 
   //and decrement the item count.
   else if (pos == itemCount)
   {
      Node<ItemType>* prev = headPtr;

      while (prev->getNext()->getNext() != nullptr)
      {
         prev = prev->getNext();
        
      }
      Node<ItemType>* last_item = prev->getNext();
      prev->setNext(nullptr);
      ItemType store_last_val = last_item->getItem();
      itemCount--;
      return store_last_val;
   }
   
   Node<ItemType>* previous = headPtr;
   Node<ItemType>* current = headPtr;
   
   for(int i = 0; i < pos; i++)
   {
      previous = current;
      current = current->getNext();
   }
   
   ItemType store_middle_val = current->getItem();
   previous->setNext(current->getNext());
   current->setNext(nullptr);
   delete current;
   itemCount--;
   return store_middle_val;

   //Case 3: If node position to be deleted is in the middle (i.e not first or last node)
   //make two nodes and set them to the headptr. Use a for loop to create a staggered set of 
   //pointers with the previous always being one node before the current node. Make a new 
   //variable to store the value in position you are going to delete. Then set prev pointer to 
   //next next node. Then set current pointer to the nullptr. Then delete current pointer 
   //and decrement the item count and return the stored variable value.
   //
}
 
/************************************************************************************  STOPS HERE*/

/** Makes list a vector (Accessor)
@return a string with list values */
template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

/** Removes one node with a specific entry data (Mutator)
@return true(1) if item is removed false(0) if it stays */        
template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

/** Removes all nodes to a linked list (Mutator)
@return true(1) if list is emptied false(0) if nodes are not emptied */  
template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear

/** Will count number of times a specific entry data is in list(Accessor)
@return integer representing frequency of the entry */ 
template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

/** Will check if a value is in list (Accessor)
@return true(1) if item is found false(0) if it is not found */ 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo
