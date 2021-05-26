/** @file Fish.cpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 1 - Classes and Inheritance
Date: 2/14/2020

Purpose: This file expands on Fish.hpp and has 
the implementation of the member functions in 
the header files.
*/
#include <iostream>
#include <string>
#include "Fish.hpp" // Includes the header file 
                    // which containes the class and the prototypes

//Default Constructor 
Fish::Fish():Animal() {} 

//Parametrized Constructor
Fish::Fish(std::string name, bool domestic, bool predator):Animal(name, domestic, predator)
{
    venomous_ = false;
}

/** Sees whether the fish object is venomousor not. (Accessor)
@return The boolean value true(1) if it is venomous
or false(0) if its not venomous */
bool Fish::isVenomous() const
{
    return venomous_;
}

/** Sets fish object to be venomous. (Mutator)
The boolean variable venomous_ is set to true(1) */
void Fish::setVenomous()
{
    venomous_ = true;
}
   

