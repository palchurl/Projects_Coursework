/** @file Animal.hpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 1 - Classes and Inheritance
Date: 2/14/2020

Purpose: This is the header file for 
Animal.cpp, it contains the declaration of the
Animal class and the classes public and private 
and member functions/ data members.
*/

#include <iostream>
#include <string>
#include <stdio.h>

/* The next two lines contain preprocessor directives
#ifndef is used to conditionally include a class definition
#define directive defines the name _ANIMAL_ */
#ifndef _ANIMAL_  
#define _ANIMAL_  

class Animal
{
    public:
        Animal(); //Default constructor

        /** Parametrized constructor
        @param name, domestic, and predator. */
        Animal(std::string name, bool domestic = false, bool predator = false); //

        /** Method gets the name of the animal object. (Accessor)
        @return The string name_ of the animal object. */
        std::string getName() const;
        
        /** Method sees whether the animal object is domestic or not. (Accessor)
        @return The boolean value true(1) if it is domesticated 
        or false(0) if its not domesticated */
        bool isDomestic() const; 

        /** Method sees whether the animal object is a predator or not. (Accessor)
        @return The boolean value true(1) if it is a predator 
        or false(0) if its not a predator*/
        bool isPredator() const;

        /* Method sets the name of the animal to what is given in the main. (Mutator)
        @param a string name stored in the variable called name
        what is stored in the parameter variable name is set to 
        the Animal class private variable called name_ */
        void setName(std::string name);

        /** Method sets animal object to be domestic. (Mutator)
        The boolean variable domestic_ is set to true(1) */
        void setDomestic(); 

        /** Method sets animal object to be a predator. (Mutator)
        The boolean variable predator_ is set to true(1) */
        void setPredator();

    private:

        //private data members/variables for the animal class
    
        std::string name_;
        bool domestic_; 
        bool predator_;
};

/* If the compiler did not define the name _ANIMAL_, it would process
the code till it reached the #endif directive. */
#endif