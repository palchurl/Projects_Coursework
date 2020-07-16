/** @file DoublyLinkedList.hpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 3 -  Doubly-Linked List
Date: 3/19/2020

Purpose: This is the header file for 
DoublyLinkedList.cpp, it contains the declaration 
of the DoublyLinkedBag class and the classes public 
and private and member functions/ data members. 
*/

#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_
/*Preprocessor directives
#ifndef is used to conditionally include a class definition
#define directive defines the name DOUBLY_LINKED_LIST_*/

#include "DoubleNode.hpp" //This file include methods and data fields used
                          //used by DoublyLinkedList

template<class ItemType>
class DoublyLinkedList 
{
    private:
        DoubleNode<ItemType>* headPtr; // Pointer to first node
        
        int itemCount;                 // Current count of bag items

    public:
        DoublyLinkedList();  //Default Constructor
       
        DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag); //Copy Constructor
       
        ~DoublyLinkedList();  // Destructor

        /** Method adds a new node to a doubly linked list at given index (Mutator)
        @return true(1) if a node has been inserted and false(0) if a node has not been added *
        @param data item that needs to be inserted and the position it should be inserted in*/   
        bool insert(const ItemType& item, const int& position);
        
        /** Method removes one node at a specific positiona (Mutator)
        @param is the position that needs to be removed from the list.
        @return true(1) if item is removed false(0) if it stays */     
        bool remove(const int& position);  
        
        /** Method gets size of doubly linked list (Accessor)
        @return integer representing number of nodes */        
        int getSize() const;
        
        /** Method returns a pointer to the first node (Accessor)
        @return a pointer to the headptr */
        DoubleNode<ItemType>* getHeadPtr() const;  
        
        /** Method returns a pointer to a node at an inputted position (Accessor)
        @param a position to get the pointer too
        @return a pointer to the position */
        DoubleNode<ItemType>* getAtPos(const int& pos) const;  
        
        /** Method checks if all nodes are removed in a doubly linked list (Accessor)
        @return true(1) if list is empty false(0) if nodes are not empty */       
        bool isEmpty() const;
        
        /** Method removes all nodes in a doubly linked list (Mutator)
        @return true(1) if list is emptied false(0) if nodes are not emptied */  
        void clear();
        
        /** Method prints all the elements in a doubly linked list (Accessor)
        @return printed doubly linked list, all the nodes inserted */
        void display() const;
        
        /** Method prints all the elements in a doubly linked list backwards (Accessor)
        @return printed doubly linked list, all the nodes inserted, backwards */
        void displayBackwards() const;
        
        /** Method takes doubly linked list and interleaves it with the link there already (Mutator)
        @param a doubly linked list to interleave
        @return an pointer to the newly created interleaved doubly linked list*/
        DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& alist); 
};

#include "DoublyLinkedList.cpp"
/* If the compiler did not define the name DOUBLY_LINKED_LIST_, it would process
the code till it reached the #endif directive. */
#endif