/** @file Mammal.hpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 1 - Classes and Inheritance
Date: 2/14/2020

Purpose: This is the header file for 
Mammal.cpp, it contains the declaration of the
Mammal class and the classes public and private 
and member functions/ data members. The mammal class
inherits properties of the superclass Animal.
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include "Animal.hpp" 
//Includes header file for Animal.hpp suggesting 
//that an object of the Mammal class will inherit from the Animal class

/* The next two lines contain preprocessor directives
#ifndef is used to conditionally include a class definition
#define directive defines the name _MAMMAL_ */
#ifndef _MAMMAL_
#define _MAMMAL_

class Mammal : public Animal //Suggests that the mammal class will inherit from Animal
{
    public:
        Mammal(); //Default Constructor

        /* Parametrized constructor
        @param name, domestic, and predator. */
        Mammal(std::string name, bool domestic = false, bool predator = false);
        
        /** Method sees whether the mammal object has hair or not. (Accessor)
        @return The boolean value true(1) if it has hair 
        or false(0) if does not have hair */
        bool hasHair() const;
        
        /** Method sees whether the mammal object can fly or not. (Accessor)
        @return The boolean value true(1) if it can fly
        or false(0) if cannot fly */
        bool isAirborne() const;

        /** Method sees whether the mammal object is Aquatic or not. (Accessor)
        @return The boolean value true(1) if it is Aquatic
        or false(0) if isn't Aquatic */        
        bool isAquatic() const; 
        
        /** Method sees whether the mammal object is Toothed or not. (Accessor)
        @return The boolean value true(1) if it toothed
        or false(0) if isn't toothed */        
        bool isToothed() const;
        
        /** Method sees whether the mammal object is has fins or not. (Accessor)
        @return The boolean value true(1) if it has fins
        or false(0) if does not have fins */        
        bool hasFins() const; 
        
        /** Method sees whether the mammal object it has a tail or not. (Accessor)
        @return The boolean value true(1) if it has a tail
        or false(0) if does not have a tail */        
        bool hasTail() const;
        
        /** Method sees how many legs the mammal has. (Accessor)
        @return an integer stored in private data member variable legs_ */        
        int legs() const;
        
        /** Method sets mammal object to have hair. (Mutator)
        The boolean variable hair_ is set to true(1) */
        void setHair();
        
        /** Method sets mammal object to be airborne. (Mutator)
        The boolean variable airborne_ is set to true(1) */
        void setAirborne();
        
        /** Method sets mammal object to be aquatic. (Mutator)
        The boolean variable aquatic_ is set to true(1) */
        void setAquatic(); 
        
        /** Method sets mammal object to have teeth. (Mutator)
        The boolean variable toothed is set to true(1) */
        void setToothed();
        
        /** Method sets mammal object to have fins. (Mutator)
        The boolean variable fins_ is set to true(1) */
        void setFins(); 
        
        /** Method sets mammal object to have a tail. (Mutator)
        The boolean variable tail_ is set to true(1) */
        void setTail();
        
        /* Method sets the number of legs of the animal. (Mutator)
        @param a integer stored in the variable called legs
        what is stored in the parameter variable legs is set to 
        the Mammal class private variable called legs_ */
        void setLegs(int legs);
    
    private:
        
        //private data members/variables for the mammal class

        bool hair_;
        bool airborne_;
        bool aquatic_; 
        bool toothed_;
        bool fins_; 
        bool tail_;
        int legs_;
 
};

/* If the compiler did not define the name _MAMMAL_, it would process
the code till it reached the #endif directive. */
#endif