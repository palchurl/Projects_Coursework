/** @file Fish.hpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 1 - Classes and Inheritance
Date: 2/14/2020

Purpose: This is the header file for Fish.cpp, 
it contains the declaration of the
Fish class and the classes public and private 
and member functions/data members. The Fish class
inherits properties of the superclass Animal.
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include "Animal.hpp"
/* Includes header file for Animal.hpp suggesting 
that an object of the Mammal class will inherit from the Animal class*/

/* The next two lines contain preprocessor directives
#ifndef is used to conditionally include a class definition
#define directive defines the name _FISH_ */
#ifndef _FISH_
#define _FISH_

class Fish : public Animal //inheritance
{
    public:
        Fish(); //Default Constructor

        /* Parametrized constructor
        @param name, domestic, and predator. */
        Fish(std::string name, bool domestic = false, bool predator = false); 
        
        /** Method sees whether the fish object is venomousor not. (Accessor)
        @return The boolean value true(1) if it is venomous
        or false(0) if its not venomous */
        bool isVenomous() const;
        
        /** Method sets fish object to be venomous. (Mutator)
        The boolean variable venomous_ is set to true(1) */
        void setVenomous();
    
    private:
        
        //private data members/variables for the Fish class

        bool venomous_;
};

/* If the compiler did not define the name _BIRD_, it would process
the code till it reached the #endif directive. */
#endif