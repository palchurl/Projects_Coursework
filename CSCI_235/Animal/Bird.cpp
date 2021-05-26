/** @file Bird.cpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 1 - Classes and Inheritance
Date: 2/14/2020

Purpose: This file expands on Bird.hpp and has 
the implementation of the member functions in 
the header files.
*/
#include <iostream>
#include <string>
#include <stdio.h>

#include "Bird.hpp" // Includes the header file 
                    // which containes the class and the prototypes

//Default Constructor 
Bird:: Bird() : Animal() {}

//Parametrized Constructor
Bird::Bird(std::string name, bool domestic, bool predator): Animal(name, domestic, predator)
{
    airborne_ = false;
    aquatic_ = false;
}

/** Sees whether the bird object can fly or not. (Accessor)
@return The boolean value true(1) if it can fly
or false(0) if cannot fly */
bool Bird::isAirborne() const
{
    return airborne_;
}

/** Sees whether the bird object is Aquatic or not. (Accessor)
@return The boolean value true(1) if it is Aquatic
or false(0) if isn't Aquatic */  
bool Bird::isAquatic() const
{
    return aquatic_;
}

/** Sets bird object to be airborne. (Mutator)
The boolean variable airborne_ is set to true(1) */
void Bird::setAirborne()
{
    airborne_ = true;
}

/** Sets mammal object to be aquatic. (Mutator)
The boolean variable aquatic_ is set to true(1) */
void Bird::setAquatic()
{
    aquatic_ = true;
}