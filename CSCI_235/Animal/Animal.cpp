 /** @file Animal.cpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 1 - Classes and Inheritance
Date: 2/14/2020

Purpose: This file expands on Animal.hpp and has 
the implementation of the member functions in 
the header files.
*/

#include <iostream>
#include <string>
#include <stdio.h>

#include "Animal.hpp" // Includes the header file 
                      // which containes the class and the prototypes

using namespace std;

//Default Constructor (sets everything to false by default)
Animal::Animal():name_(""),domestic_(false),predator_(false) {}  

Animal::Animal(string name, bool domestic, bool predator)  //Parametrized Constructor
{
    name_ = name;
    domestic_ = domestic;
    predator_ = predator;
}

/** Gets the name of the animal object. (Accessor)
@return The string name_ of the animal object. */
string Animal::getName() const
{
    return name_;
}

/** Sees whether the animal object is domestic or not. (Accessor)
@return The boolean value true(1) if it is domesticated 
or false(0) if its not domesticated */
bool Animal::isDomestic() const
{
   return domestic_; 
}

/** Sees whether the animal object is a predator or not. (Accessor)
@return The boolean value true(1) if it is a predator 
or false(0) if its not a predator*/
bool Animal::isPredator() const
{
    return predator_; 
}

/** Sets the name of the animal to what is given in the main. (Mutator)
@param a string name stored in the variable called name
what is stored in the parameter variable name is set to 
the Animal class private variable called name_ */
void Animal::setName(string name)
{
    name_ = name;
}

/** Sets animal object to be domestic. (Mutator)
The boolean variable domestic_ is set to true(1) */
void Animal::setDomestic()
{
    domestic_ = true;
}

/** Sets animal object to be a predator. (Mutator)
The boolean variable predator_ is set to true(1) */
void Animal::setPredator()
{
    predator_ = true;
}

