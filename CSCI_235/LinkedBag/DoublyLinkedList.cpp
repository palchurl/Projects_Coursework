/** @file DoublyLinkedList.cpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 3 -  Doubly-Linked List
Date: 3/19/2020

Purpose: This file expands on DoublyLinkedList.hpp 
and has the implementation of the member functions 
in the header file.
*/

#include "DoublyLinkedList.hpp"
#include <cstdlib>
#include "DoubleNode.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), itemCount(0) //Constructor
{

} //end default constructor

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag) //Copy Constructor
{
    itemCount = aBag.itemCount;                   //Assigning ItemCount to be equal to aBag's Itemcount
                                                  //since they are copies they share same number of nodes
    DoubleNode<ItemType>* ptr1 = aBag.headPtr;    //Creates a ptr to point to aBag's headptr

    if (ptr1 == nullptr)                          //If aBag is empty then the headptr of the copy will 
    {                                             //be assigned to nullptr therefore making the copy empty.
        headPtr = nullptr;                       
    }

    else                                          //If aBag is not empty and there are nodes to be copied
    {   
        headPtr = new DoubleNode<ItemType>();     //Copies the headptr of aBag by setting the item inside ptr1
        headPtr->setItem(ptr1->getItem());        //to headPtr of the copy bag and then sets the headptrs
        headPtr->setPrev(nullptr);                //previous node to nullptr

        DoubleNode<ItemType>* current = headPtr;  //Creates two pointers both refering to headptr of copy chain
        DoubleNode<ItemType>* after = headPtr;    

        ptr1 = ptr1->getNext();                   //Moves the ptr of the original chain to next node
        while (ptr1 != nullptr)                   //Copies rest of the nodes by traversing the list till ptr 
        {                                         //doesn't reach nullptr
            DoubleNode<ItemType>* newPtr = new DoubleNode<ItemType>(ptr1->getItem());  //Creates a ptr to a new 
                                                  //node with the following node's item
            current->setNext(newPtr);             //Sets current's next to be the newly create ptr and its prev to be 
            current->setPrev(after);              //the after ptr
            
            current = current->getNext();         //This moves current ptr to next node
            after = after->getNext();             //Moves after and original chain ptr to next node
            ptr1 = ptr1->getNext();
        } 
        current->setNext(nullptr);  // Flag end of chain
    } 
}  // end copy constructor

template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
   clear();
}  // end destructor

/** Prints all the elements in a doubly linked list (Acessor)
@return printed doubly linked list, all the nodes inserted */
template<class ItemType>
void DoublyLinkedList<ItemType>::display() const
{   
    DoubleNode<ItemType>* tmp = headPtr;    //Creates a temporary ptr pointing to the headptr
 
    while (tmp->getNext() != nullptr)       //Traverses the list till ptr reaches second to last node
    {
        cout << tmp->getItem() << " ";      //Prints the data inside each node
        tmp = tmp->getNext();               //and moves the ptr to next node
    }
    cout << tmp->getItem();                 //Prints the item inside the last node and skips a line
    cout << endl;
}

/** Prints all the elements in a doubly linked list backwards (Acessor)
@return printed doubly linked list, all the nodes inserted, backwards */
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
   DoubleNode<ItemType>* tmp = this->headPtr; //Creates a temp ptr pointing to the headptr
	
    if(tmp == nullptr)                         //If list is empty exit
    {
        return; 
    }

    while(tmp->getNext() != nullptr)           //Traverse list till reached last node
    {
        tmp = tmp->getNext();
    }

    while(tmp->getPrev() != nullptr)           //Ptr traverses backwards till it reaches nullptr
    {
        cout << tmp->getItem() << " ";         //Prints the data inside each node
        tmp = tmp->getPrev();                  //and moves the ptr to previous node
    }
    cout << tmp->getItem();                    //Prints the item inside the first node and skips a line
    cout << endl;
}

/** Removes all nodes in a doubly linked list (Mutator)
@return true(1) if list is emptied false(0) if nodes are not emptied */  
template<class ItemType>  
void DoublyLinkedList<ItemType>::clear()
{
    DoubleNode<ItemType>* traversingPtr = headPtr;
    
    while (traversingPtr != nullptr) 
    {
      DoubleNode<ItemType>* store_nxt = traversingPtr->getNext();
      traversingPtr->setPrev(nullptr);
      traversingPtr->setNext(nullptr);
      traversingPtr = store_nxt;
    
    }
    headPtr = nullptr; 
    traversingPtr = nullptr;
    itemCount = 0;
    
    //Makes a ptr assigned to the headptr. Ptr traverses the list till reaching the nullptr
    //Stores the next ptr in a newly created ptr and sets the curretptr's next and prev 
    //to null. Then deletes the headptr and sets the itemCount to 0. 
}

/** Gets size of doubly linked list (Accessor)
@return integer representing number of nodes */   
template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    return itemCount;
}

/** Checks if all nodes are removed in a doubly linked list (Accessor)
@return true(1) if list is empty false(0) if nodes are not empty */       
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    if(itemCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** Adds a new node to a doubly linked list at given index (Mutator)
@return true(1) if a node has been inserted and false(0) if a node has not been added *
@param data item that needs to be inserted and the position it should be inserted in*/   
template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position)
{
    if (position < 1 || position > itemCount+1)   
    {
		return false;   //Checks if the position is within the range 1 to itemcount+1 
	}                   //if it is not false is returned

    DoubleNode<ItemType>* newNode = new DoubleNode<ItemType>;
    newNode->setItem(item);
    //Creates a new node with the data given as a parameter

    if(position == 1)
    { 
        if(headPtr == nullptr)
        {
            newNode->setNext(nullptr);
            newNode->setPrev(nullptr);
            headPtr = newNode;
        }
        //if list is empty then set new node's prev and next to null 
        //and set it to the head pointer and the itemcount is incremented
        else
        {
            headPtr->setPrev(newNode);
            newNode->setPrev(nullptr);
            newNode->setNext(headPtr);
            headPtr = newNode;
        }
        //If there is already a headptr then set its previous node to be the
        //new node and set the new node's next to the headptr and prev to nullptr
        //then assign it to be the new headptr.
        itemCount++;
        return true;
    }

    else if(position == itemCount+1)
    {
        DoubleNode<ItemType>* tail = headPtr;
        while(tail->getNext() != nullptr)
        {
            tail = tail->getNext();
        }
        tail->setNext(newNode);
        newNode->setPrev(tail);
        newNode->setNext(nullptr);
        itemCount++;
        return true;
    }
    //if node is to be placed in the last position make a new ptr assigned to the headptr
    //Till ptr reaches last node it is moved. Then the current last node's next becomes the new 
    //node created and the new nodes previous becomes the current node and the new nodes next 
    //is set to null and the itemcount is incremented. 

    else
    {
        int index = 1;
        DoubleNode<ItemType>* middle = headPtr;
        while(index != position - 1)
        {
            middle = middle->getNext();
            index++;
        }
        newNode->setPrev(middle);
        newNode->setNext(middle->getNext());
        middle->setNext(newNode);
        newNode->getNext()->setPrev(newNode);
        itemCount++;
        return true;
    }
    //Created a variable and assigned its value to 1 and it is incremented till it reaches pos-1
    //each traversal tmp is moved by one node. Then upon exit of the while loop the new node's 
    //prev is set to the tmp ptr, and the next is set to the the tmp ptr's next. the tmp pointers
    //next is set to the new node and the new nodes next's prev is set to the new node. Then the 
    //itemcount is incremented.
    
    return true;
}

/** Method returns a pointer to the first node (Accessor)
@return a pointer to the headptr */
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const
{
    return headPtr;                                                 
}

/** Method returns a pointer to a node at an inputted position (Accessor)                                   
@param a position to get the pointer too
@return a pointer to the position */
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const
{
    if((pos >= 1) && (pos <= itemCount+1))          //Checks if pos parameter is within range
    {
        DoubleNode<ItemType>* nodePos = headPtr;    //Make a temp ptr and assign it to the headptr
        for(int i = 1; i < pos; i++)                //Traverses till ptr reaches position
        {
            nodePos = nodePos->getNext();
        }
        return nodePos;                             //returns the tmp ptr
    }
    return nullptr;                                 //else return nullptr
}

/** Method removes one node at a specific positiona (Mutator)
@param is the position that needs to be removed from the list.
@return true(1) if item is removed false(0) if it stays */     
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position)
{
    if (position < 0 || position > itemCount)  
    {
		return false;     //returns false if the position is within the range 1 to itemcount
	}                       

    if(position == 1) 
    {
        headPtr = headPtr->getNext();
        headPtr->setPrev(nullptr);
        itemCount--;
        return true;
    }
    //If position to be removed is 1, the headptr is moved to the next node and the previous of the 
    //new headptr is set to null and the itemcount is decremented and true is returned.

	else if (position == itemCount)
    {
        DoubleNode<ItemType>* tailptr = headPtr;
        while (tailptr->getNext() != nullptr)
        {
            tailptr = tailptr->getNext();
        }
        tailptr->getPrev()->setNext(nullptr);
        tailptr->setPrev(nullptr);
        delete tailptr;
        tailptr = nullptr;
        itemCount--;
        return true;
    }
    //if the position to be removed is the last one create a new node to traverse till the end
    //and its prev and next is set to the next to the nullptr. Then the tailptr is deallocated 
    //and itemCount is decrementedand true is returned.

    else
    {
        DoubleNode<ItemType>* posPtr = headPtr;       
        for(int i = 1; i < position; i++) 
        {
            posPtr = posPtr->getNext();
        }
        posPtr->getPrev()->setNext(posPtr->getNext());
        posPtr->getNext()->setPrev(posPtr->getPrev());
        itemCount--;
        return true;
    } 
    //if position is found in the middle. Then a ptr is made and it traverses list till it 
    //middle position. Then its ptr's prev is set to its next. And its next is set to its 
    //prev and itemcount is decremented and true is returned.

   return true;
}

/** Method takes doubly linked list and interleaves it with the link there already (Mutator)
@param a doubly linked list to interleave
@return an pointer to the newly created interleaved doubly linked list*/
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& alist)
{
    DoublyLinkedList<ItemType>* result_dll = new DoublyLinkedList();
    
    if(!(isEmpty()) && !(alist.isEmpty()))  //This checks if both lists are not empty
    {   
        DoubleNode<ItemType>* ourlist_ptr = headPtr;
        DoubleNode<ItemType>* alist_ptr = alist.headPtr;
        int index = 1;   
        while(ourlist_ptr != nullptr && alist_ptr != nullptr)
        {
            if(index % 2 != 0)
            {
                result_dll->insert(ourlist_ptr->getItem(), index);
                ourlist_ptr = ourlist_ptr->getNext();
                index++;
            }
            
            else
            {
                result_dll->insert(alist_ptr->getItem(), index);
                alist_ptr = alist_ptr->getNext();
                index++;   
            }
        }

        while(ourlist_ptr != nullptr)
        {
            result_dll->insert(ourlist_ptr->getItem(), index);
            ourlist_ptr = ourlist_ptr->getNext();
            index++;
        }

        while(alist_ptr != nullptr)
        {
            result_dll->insert(alist_ptr->getItem(), index);
            alist_ptr = alist_ptr->getNext();
            index++;
        }
        
    }
    return *result_dll; 
    //Makes a new doubly linked list called result_dll. Then makes two ptr to refer to alist and original
    //lists headptr respectively. Create a variable and set it to 1 (to keep track of positions). Then untill either ptr 
    //reaches the end of either list send a node from original list and then insert a node from alist alternatingly. 
    //The alternation is given by the index value ,if its odd takes from the origial list and if even it takes from 
    //parameter list. Then if there are any leftover nodes in one of the lists it will be done by one of the while loops, 
    //returns the resulting list.
}
