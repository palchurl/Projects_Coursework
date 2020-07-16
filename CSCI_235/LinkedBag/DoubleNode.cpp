/** @file DoubleNode.cpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 3 - Doubly Linked List
Date: 3/19/2020

Purpose: This file expands on DoubleNode.hpp and has 
the implementation of the member functions in 
the header file.
*/

#include "DoubleNode.hpp" // Includes the header file 
                          // which containes the class and the prototypes

template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : next(nullptr), previous(nullptr) {}
//Default Constructor

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem) : item(anItem), next(nullptr),previous(nullptr) {} 
//Parameterized Constructor

/** Sets an item sent as a parameter to a node (Mutator)
@param is an item of any type consistent with the instantiated objects type */ 
template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;               //the private item is set to parameter anItem
} 

/** Sets the next node of a pointer to be the the sent next_node_ptr (Mutator)
@param is a node pointer */ 
template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* next_node_ptr)
{
    next = next_node_ptr;        //the next ptr of the private paramteter and 
}                                //set it to the nect_node_ptr

/** Gets the item inside a node (Acessor)
@return an item value */ 
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
    return item;                  //returns private data member item
} 

/** Gets a pointer to the next node (Acessor)
@return a pointer to the next node */
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
    return next;                 //returns private data member, ptr named next
} 

/** Sets the prev node of a pointer to be the the sent prev_node_ptr (Mutator)
@param is a node pointer */ 
template<class ItemType>
void DoubleNode<ItemType>::setPrev(DoubleNode<ItemType>* prev_node_ptr)
{
    previous = prev_node_ptr;   //sets private data member, ptr named previoud
} 

/** Gets a pointer to the previous node (Acessor)
@return a pointer to the previous node */
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() const
{
    return previous;            //returns private data member, a ptr named previous
} 


