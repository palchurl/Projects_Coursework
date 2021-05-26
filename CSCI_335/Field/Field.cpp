/*
Assignment: Project 3 -  Field Class
Date: 11/21/2020

Purpose: This file is the implementation file for 
the Field class it has the classes public and private 
member functions/data members and the implementation of 
the member functions in the interface. A
*/

#include "Field.h"
#include <iostream>
#include <vector>       //vector
#include <stdexcept>    //std exceptions

/* Parameterized Constructor takes one parameter, a vector of vectors or a matrix 
named rhs. The constructor does an initial check if rhs is empty and if rhs has 
values then rhs is copied into the three private matrixes part of this class and
the row and columns are also assigned. Then we go through every cell of the matrix
and based on the indexes of the cell we assign the corresponding cell of util 
and path a certain value based on adjacent cells and current cells value.
*/
Field::Field(const std::vector<std::vector<int>> & rhs) {         
    
    if (rhs.empty()) {              //If rhs is empty then no preprocessing is necessary
      return;                       //so return and leave the parameterized constructor.
    }                               //util and path are also empty and will be dealt with 
                                    //accodingly in weight and path.

    util = path = v = rhs;          //Here we use the assignment operator to copy the values of 
    rows = v.size();                //rhs into util, path and v. This is so those three matrixes 
    cols = v[0].size();             //have the same dimentions as rhs.
    //Next we assign the size of v to rows which gets the number of vectors in v which is also equal
    //to number of rows in v. Then we assign the number of elements in row 0 of v to cols since the 
    //number of elements in a row will give the cols since the passed in matrixes are mxn matrixes.
    
    for (int i = 0; i < rows; i++) {                //Traverse through each element in a row
		for (int j = 0; j < cols; j++) {            //Traverse through each element in a column
            if(i == 0 && j == 0){                   
                util.at(i).at(j) = v.at(i).at(j);
                path.at(i).at(j) = v.at(i).at(j);   
            }
            //If we are at the indexes of the origin (0,0) we take the value of v(0,0) and put it into
            //util and path since it is the first element in the matrix no other computation occurs 
            //and the value is just copied into the origin cell of util and path.
            
            else if(i > 0 && j == 0) {
                util.at(i).at(j) = v.at(i).at(j) + util.at(i - 1).at(j);
                path.at(i).at(j) = v.at(i).at(j) + path.at(i - 1).at(j);
            }
            //If we are here we are at the indexes of the first column which need to be computed 
            //differently. To get sums of the current element of the first column we just need to
            //add the element above it to the current element at this index and assign it to
            //that index. With the path utility matrix we do same computation since the same calculation
            //is used to travel down rows.
            
            else if(i == 0 && j > 0) {
                util.at(i).at(j) = v.at(i).at(j) + util.at(i).at(j - 1);
                path.at(i).at(j) = v.at(i).at(j) + path.at(i).at(j - 1);
            }
            //If we are here we are at the indexes of the first row which need to be computed in a different 
            //mannar. To get the sum of the current element in the first column we need to add the value in the
            //cell before it (in the previous column). With the path utility matrix we do same computation 
            //since the same calculation is used to travel right across columns.

            else if(i > 0 && j > 0) {   
                util.at(i).at(j) = v.at(i).at(j) + util.at(i).at(j - 1) + util.at(i - 1).at(j) - util.at(i - 1).at(j - 1);   
                path.at(i).at(j) = std::min(path.at(i - 1).at(j) + v.at(i).at(j), path.at(i).at(j - 1) + v.at(i).at(j));
            } 
            //This condition is reached if the indexes are one or above. With the utility matrix the current 
            //value sum is calculated by adding the sume of all elements from (0,0) to the row above current row
            //(to the same col) and the sum of all elements from (0,0) to the col to the left of current col. These
            //are then subracted by overlapped area sum and then added to the current value of that index to get 
            //util[i][j]. With path the value of the cell at these indexes is calculated by taking the min of 
            //the value in path in the adjacent row and column added to the current cell's value. This condition 
            //should place values in all the other coordinates besides the ones of the first column and row.
		}
	}

}

/* Another Parameterized Constructor takes one parameter, a vector of vectors, a matrix 
named rhs. Initially checked if rhs is empty return and exit the constructor as preprocessing
an empty matrix is unecessary. the rows and cols of rhs is assigned and since rhs is a rvalue
move is used to transfer all the data inside rhs into v. Then util and path copy v into themselves
and preprocess v like in the previous constructor. Every cell of v is traversed and assigned a util 
and a path value.
*/
Field::Field(std::vector<std::vector<int>> && rhs) { 

    if (rhs.empty()) {          //If rhs is empty then no preprocessing is necessary
      return;                   //so return and leave the parameterized constructor
    }   

    rows = rhs.size();          //rows gets the size or number of rows in rhs
    cols = rhs[0].size();       //cols gets the number of elements in the first row
                                //of rhs which represents number of columns in rhs

    v = std::move(rhs);         //data in rhs is moved into v and rhs is no longer accessable
    path = util = v;            //path and util copy v using an assignment operator. This is to 
    //to ensure that path and util share the same dimentions as rhs.

    //Same preprocessing as in the lvalue parameterized constructor

    for (int i = 0; i < rows; i++) {            //Traverse through each element in a row
		for (int j = 0; j < cols; j++) {        //Traverse through each element in a column
            if(i == 0 && j == 0){
                util.at(i).at(j) = v.at(i).at(j);
                path.at(i).at(j) = v.at(i).at(j);   
            }
            //At the origin (0,0) the value in util and path origins copy v's origin

            else if(i > 0 && j == 0) {
                util.at(i).at(j) = v.at(i).at(j) + util.at(i - 1).at(j);
                path.at(i).at(j) = v.at(i).at(j) + path.at(i - 1).at(j);
            }
            //When the index is in the first column we add the previous rows value util[i - 1][0]
            //to the current value at v. The same is done with path.

            else if(i == 0 && j > 0) {
                util.at(i).at(j) = v.at(i).at(j) + util.at(i).at(j - 1);
                path.at(i).at(j) = v.at(i).at(j) + path.at(i).at(j - 1);
            }
            //When the index is in the first row we add the previous columns value util[0][j - 1]
            //to the current value at v. The same is done with path.

            else if(i > 0 && j > 0) {   
                util.at(i).at(j) = v.at(i).at(j) + util.at(i).at(j - 1) + util.at(i - 1).at(j) - util.at(i - 1).at(j - 1);
                path.at(i).at(j) = std::min(path.at(i - 1).at(j) + v.at(i).at(j), path.at(i).at(j - 1) + v.at(i).at(j));
            }
            //This condition is reached if the indexes are one or above. With the utility matrix the current 
            //value sum is calculated by adding the sume of all elements from (0,0) to the row above current row
            //(to the same col) and the sum of all elements from (0,0) to the col to the left of current col. These
            //are then subracted by overlapped area sum and then added to the current value of that index to get 
            //util[i][j]. With path the value of the cell at these indexes is calculated by taking the min of 
            //the value in path in the adjacent row and column added to the current cell's value. This condition 
            //should place values in all the other coordinates besides the ones of the first column and row.
		}
	}
}


/* The Wieght function takes in four parameters x1, y1, x2, y2. The x and y values are passed in swapped.
It checks if the coordinates are valid and then properly assigns the correct coordinate values 
so a weight can be calculated with the appropriate processed data used.
*/
int Field::Weight(int x1, int y1, int x2, int y2) {
    
    if(util.empty()) {                                                           //If the utility matrix is empty 
        throw std::out_of_range("matrix is empty so x and y are out of range."); //then throw an exception to 
    }                                                                            //indicate this.

    if(x1 >= cols || x2 >= cols || y1 >= rows || y2 >= rows || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) {                 
        throw std::out_of_range("x and/or y coordinates are out of range.");    
    }                                                                           
    //If the x and y coordinates are out of range then an exception is throwed saying this.
    
    //Since the x and y coordinates are swapped we make the new x variables choose from the y values and
    //the new y variables choose from the x values.
    int xOne = std::min(y1, y2);          //xOne represents the x coordinate of topleft corner of matrix
    int yOne = std::min(x1, x2);          //yOne represents the y coordinate of topleft corner of matrix
    int xTwo = std::max(y1, y2);          //xTwo represents the x coordinate of bottom right corner of matrix
    int yTwo = std::max(x1, x2);          //yTwo represents the y coordinate of bottom right corner of matrix
    //The minimum is taken for the first pair since they have be higher(lower y value) and more to 
    //the left (lower x value) and the maximum is taken for the second pair which has to be lower
    //(higher y value) and more to the right (higher x value)

    if(xOne == 0 && yOne == 0) {            //If the first pair of coordinated is (0, 0) then no extra computation 
        return util.at(xTwo).at(yTwo);      //is needed and the util value at the second pairs coordinates is taken
    }                                       //and returned.

    if(yOne == 0 && xOne >= 1) {                                        //If the first coordinate pair is on 
        return util.at(xTwo).at(yTwo) - util.at(xOne - 1).at(yTwo);     //first col then you get util[xTwo][yTwo]
    }                                                                   //which is the sum from 0,0 to that coordinate
    //and subtract the row(s) before it by getting the util.at(xOne - 1).at(yTwo) value.
    
    if(xOne == 0 && yOne >= 1) {                                        //If the first coordinate pair is on 
        return util.at(xTwo).at(yTwo) - util.at(xTwo).at(yOne - 1);     //the first row then take the value at the 
    }                                                                   //utility matrix at the coordinates of 
    //the second pair and subtract it by the column(s) befores sum by getting util.at(xTwo).at(yOne - 1) value.

    return util.at(xTwo).at(yTwo) - util.at(xOne - 1).at(yTwo) - util.at(xTwo).at(yOne - 1) + util.at(xOne - 1).at(yOne - 1);
    //if xOne >= 1 && yOne >= 1 then we first get the util sum at xTwo,yTwo and then subtract it by the colums not covered 
    //in the matrix and then subtract the rows not covered in the matrix and then add the overlapped area back to get the 
    //area of the section of the matrix.  
}

/* PathCost returns the minimum path cost to get from the origin of the matrix to 
the last cell in the matrix and it checks if the matrix that has been processed 
is empty and and then returns the minimum cost value according to the utility path
matrix.
*/
int Field::PathCost() {

    if(v.empty() || path.empty()) {             //If the processed matrix or the utility 
        return 0;                               //matrix is empty them return 0.
    }
    
    return path.at(rows - 1).at(cols - 1);      //Retun the value in the last cell of the matrix which should 
    //represent the minimum path cost since in the preprocessing the least of the values to the left or above 
    //was taken to calculate the accurate value.
}






