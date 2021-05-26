/** @file Bird.hpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 1 - Classes and Inheritance
Date: 2/14/2020

Purpose: This is the header file for Bird.cpp, 
it contains the declaration of the
Bird class and the classes public and private 
and member functions/data members. The bird class
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
#define directive defines the name _BIRD_ */
#ifndef _BIRD_
#define _BIRD_

class Bird : public Animal //inheritance
{
    public:
        Bird(); //Default Constructor

        /* Parametrized constructor
        @param name, domestic, and predator. */
        Bird(std::string name, bool domestic = false, bool predator = false); 
        
        /** Method sees whether the bird object can fly or not. (Accessor)
        @return The boolean value true(1) if it can fly
        or false(0) if cannot fly */
        bool isAirborne() const;
        
        /** Method sees whether the bird object is Aquatic or not. (Accessor)
        @return The boolean value true(1) if it is Aquatic
        or false(0) if isn't Aquatic */        
        bool isAquatic() const;
        
        /** Method sets bird object to be airborne. (Mutator)
        The boolean variable airborne_ is set to true(1) */
        void setAirborne();
        
        /** Method sets mammal object to be aquatic. (Mutator)
        The boolean variable aquatic_ is set to true(1) */
        void setAquatic();
    
    private:
        
        //private data members/variables for the bird class

        bool airborne_;
        bool aquatic_;
};

/* If the compiler did not define the name _BIRD_, it would process
the code till it reached the #endif directive. */
#endif