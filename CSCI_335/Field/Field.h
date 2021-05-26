/*
Assignment: Project 3 -  Field Class
Date: 11/21/2020

Purpose: This file is the header file for the Field class 
and contains the interface of the field class and it has 
the classes public and private member functions/data 
members. A
*/

#ifndef _FIELD_
#define _FIELD_
/* Preprocessor directives
#ifndef is used to conditionally include a class definition
#define directive defines the name _FIELD_  */

#include <vector>       //vector

class Field {
    private:
        int rows;       
        //This variable gets the number of rows of the given matrix to be used 
        //in compuatation and preprocessing afterwords
        
        int cols;
        //This variable gets the number of cols of the given matrix to be used 
        //in compuatation and preprocessing afterwords
        
        std::vector<std::vector<int>> v;
        //This matrix (vector of vectors) v will keep a copy of the matrix passed 
        //in in the two parameterized constructors. 

        std::vector<std::vector<int>> util;
        //This matrix util will be the utility matrix that will hold the preprocessed
        //values for the weight function. Each cell will hold its own cost plus 
        //the costs of all of the cells before the current cell encapsulated in a rectangle 
        //drawn from the origin (0,0) to that current cell.

        std::vector<std::vector<int>> path;
        //This matrix path is another utility matrix for the preprocessing of the pathCost
        //member function. Each cell will hold the current possible minimun value of the path.
        //Eventually at the last cell (rows-1,cols-1), we will have minimum possible path cost
        //with this matrix. 

    public:
        Field(const std::vector<std::vector<int>> & rhs);
        //This is a parameterized constructor that takes in a lvalue matrix, rhs, and copies it
        //and them preprocesses its cell values so util and path have the appropriate values in them
        //so they can be accessed in Weight and PathCost.

        Field(std::vector<std::vector<int>> && rhs);
        //This is a another parameterized constructor that takes in a rvalue matrix, rhs, 
        //and moves it and then preprocesses its cell values so util and path have the 
        //appropriate values in them so they can be accessed in Weight and PathCost.

        int Weight(int x1, int y1, int x2, int y2);
        //Weight takes in 2 coordinate pairs (x1, y1) and (x2, y2) and outputs the area or the
        //total cost of the area the coordinates represent. 

        int PathCost();
        //PathCost outputs the least expensive path to go from the topmost-leftmost cell 
        //at (0, 0) to the bottommost-rightmost cell in the matrix. 

};

//#include "Field.cpp"
#endif