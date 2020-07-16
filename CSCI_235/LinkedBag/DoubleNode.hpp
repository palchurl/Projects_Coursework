/** @file DoubleNode.hpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 3 - Doubly Linked List
Date: 3/19/2020

Purpose: This is the header file for 
DoubleNode.cpp, it contains the declaration 
of the DoubleNode class and the classes public 
and private and member functions/ data members. 

*/

#ifndef DOUBLENODE_
#define DOUBLENODE_
/*Preprocessor directives
#ifndef is used to conditionally include a class definition
#define directive defines the name DOUBLENODE_ */

template<class ItemType>
class DoubleNode
{
    private:
        ItemType        item;// A data item
        DoubleNode<ItemType>* next; // Pointer to next node
        DoubleNode<ItemType>* previous; // the pointer to the previous node

    public:
        DoubleNode(); // Default Constructor

        DoubleNode(const ItemType& anItem); //Parameterized Constructor 
        
        DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* next_node_ptr); 
        
        /** Method sets an item sent as a parameter to a node (Mutator)
        @param is an item of any type consistent with the instantiated objects type */        
        void setItem(const ItemType& anItem); 

        /** Method sets the next node of a pointer to be the the sent next_node_ptr (Mutator)
        @param is a node pointer */    
        void setNext(DoubleNode<ItemType>* next_node_ptr);

        /** Method sets the prev node of a pointer to be the the sent prev_node_ptr (Mutator)
        @param is a node pointer */ 
        void setPrev(DoubleNode<ItemType>* prev_node_ptr); 

        /** Method gets the item inside a node (Acessor)
        @return an item value */ 
        ItemType getItem() const ;

        /** Method gets a pointer to the next node (Acessor)
        @return a pointer to the next node */
        DoubleNode<ItemType>* getNext() const ; 
        
        /** Method gets a pointer to the previous node (Acessor)
        @return a pointer to the previous node */       
        DoubleNode<ItemType>* getPrev() const; 

}; //end of DoubleNode class

#include "DoubleNode.cpp"
/* If the compiler did not define the name DOUBLENODE_, it would process
the code till it reached the #endif directive. */
#endif

