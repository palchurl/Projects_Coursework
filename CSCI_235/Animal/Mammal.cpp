/** @file Mammal.cpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 1 - Classes and Inheritance
Date: 2/14/2020

Purpose: This file expands on Mammal.hpp and has 
the implementation of the member functions in 
the header files.
*/

#include <iostream>
#include <string>
#include <stdio.h>

#include "Mammal.hpp" // Includes the header file 
                      // which containes the class and the prototypes


//Default Constructor (sets everything to false by default)
Mammal::Mammal():Animal(), hair_(false), airborne_(false), aquatic_(false),  toothed_(false), fins_(false), tail_(false), legs_(0) {}

Mammal::Mammal(std::string name, bool domestic, bool predator):Animal(name, domestic, predator) //Parametrized Constructor
{
    hair_ = false;
    airborne_ = false;
    airborne_ = false;
    aquatic_ = false;
    toothed_ = false;
    fins_ = false;
    tail_ = false;
    legs_ = 0;
}

/** Sees whether the mammal object has hair or not. (Accessor)
@return The boolean value true(1) if it has hair 
or false(0) if does not have hair */
bool Mammal:: hasHair() const
{
    return hair_;
}

/** Sees whether the mammal object can fly or not. (Accessor)
@return The boolean value true(1) if it can fly
or false(0) if cannot fly */
bool Mammal:: isAirborne() const
{   
    return airborne_;
}

/** Sees whether the mammal object is Aquatic or not. (Accessor)
@return The boolean value true(1) if it is Aquatic
or false(0) if isn't Aquatic */   
bool Mammal:: isAquatic() const
{
    return aquatic_;
}

/** Sees whether the mammal object is Toothed or not. (Accessor)
@return The boolean value true(1) if it toothed
or false(0) if isn't toothed */        
bool Mammal:: isToothed() const
{
    return toothed_;
}

/** Sees whether the mammal object is has fins or not. (Accessor)
@return The boolean value true(1) if it has fins
or false(0) if does not have fins */    
bool Mammal:: hasFins() const
{
    return fins_;
}

/** Sees whether the mammal object it has a tail or not. (Accessor)
@return The boolean value true(1) if it has a tail
or false(0) if does not have a tail */ 
bool Mammal:: hasTail() const
{
    return tail_;
}

/** Sees how many legs the mammal has. (Accessor)
@return an integer stored in private data member variable legs_ */     
int Mammal:: legs() const
{
    return legs_;
}

/** Sets mammal object to have hair. (Mutator)
The boolean variable hair_ is set to true(1) */
void Mammal:: setHair()
{
    hair_ = true;
}

/** Sets mammal object to be airborne. (Mutator)
The boolean variable airborne_ is set to true(1) */
void Mammal:: setAirborne()
{
    airborne_ = false;
}

/** Sets mammal object to be aquatic. (Mutator)
The boolean variable aquatic_ is set to true(1) */
void Mammal:: setAquatic()
{
    aquatic_ = true;
}

/** Sets mammal object to have teeth. (Mutator)
The boolean variable toothed is set to true(1) */
void Mammal:: setToothed()
{
    toothed_ = true;
}

/** Sets mammal object to have fins. (Mutator)
The boolean variable fins_ is set to true(1) */
void Mammal:: setFins()
{
    fins_ = true;
}

/** Sets mammal object to have a tail. (Mutator)
The boolean variable tail_ is set to true(1) */
void Mammal:: setTail()
{
    tail_ = true;
}

/* Sets the number of legs of the animal. (Mutator)
@param a integer stored in the variable called legs
what is stored in the parameter variable legs is set to 
the Mammal class private variable called legs_ */
void Mammal:: setLegs(int legs)
{
    legs_ = legs;
}