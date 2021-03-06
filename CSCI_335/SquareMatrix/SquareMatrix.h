/*
Assignment: Project 1 -  Square Matrix Class
Date: 10/4/2020

Purpose: This file contains the interface and 
implementation of the SquareMatrix class. It has 
the classes public and private member functions/data 
members. It also and has the implementation of 
the member functions in the interface. A
*/

#ifndef _SQUARE_MATRIX_
#define _SQAURE_MATRIX_
#include <cstddef>      //size_t
#include <stdexcept>    //throw exception
#include <iostream> 
using namespace std;

template<class ItemType>
class SquareMatrix {
    private:
        size_t side_length_;        //Stores the side length of the matrix (or the number of rows/column)
        ItemType ** sqmat;          //Pointer to an array of pointers (2D array) of type ItemType
        void allocateMemory();      //Allocates the necessary space needed for a matrix object
        void deallocateMemory();    //Deallocates the space used by a matrix object

    public:
        SquareMatrix();                                       //Default Constructor                                                                                                         
        SquareMatrix(int sideLength);                         //Parameterized Constructor                                                
        
        ~SquareMatrix();                                      //Destructor                         
        SquareMatrix(const SquareMatrix & rhs);               //Copy Constructor                             
        SquareMatrix(SquareMatrix && rhs);                    //Move Constructor                          
        SquareMatrix & operator= (const SquareMatrix & rhs);  //Copy Assignment                           
        SquareMatrix & operator= (SquareMatrix && rhs);       //Move Assignment          

        bool operator== (const SquareMatrix & rhs) const;                                  //Equality Operator   
        SquareMatrix<ItemType> operator+ (const SquareMatrix<ItemType> & sm) const;        //Addition Operator
        
        void resize(int newSideLength);          //Resize Matrix to another size thats passed as a parameter                                    
        ItemType& at(int row, int column);       //At gets the reference to a cell in the matrix                            
        void fillMatrix(const ItemType& value);  //Fill cells of Matrix with a value passed as a parameter
        int size() const;                                          

        void displayMatrix(const SquareMatrix<ItemType> & sm);  //Print Matrix
        
}; 

#endif

/* Default Constructor is called when no arguments are given.
Setting default arguements by setting private variable side_length_ 
to be 0 and setting sqmat to nullptr */
template<typename ItemType>                                                                 
SquareMatrix<ItemType>::SquareMatrix() : side_length_(0), sqmat(nullptr) {
    //cout << "in default construtor" << endl;
}

/* Parameterized Constructor is called when arguments are passed to the constructor.
@Param Integer to be assigned to be the side length of the matrix */
template<typename ItemType>                                                                 
SquareMatrix<ItemType>::SquareMatrix(int sideLength) : side_length_(sideLength) {
    //cout << "in parameterized construtor" << endl;

    allocateMemory();           //Calls allocateMemory function which allocates enough                          
    if(sideLength > 0) {        //space for a matrix of the side length passed 
       fillMatrix(0);           //If the sideLength is greater than zero (or is nonempty) 
    }                           //then fill allocated spaces with 0 values
}


/* Destructor which is invoked before an object's memory is going to be released,
it is called upon when an object becomes out of scope or is destroyed by delete.*/
template<typename ItemType>                                                                 
SquareMatrix<ItemType>::~SquareMatrix() {
    //cout << "in destructor"<<endl;
                                //Calls deallocateMemory function which destroys previous content in matrix
    deallocateMemory();         //and properly releases memory used
}                               

/* Copy Constructor creates a new object as a copy of an existing object, it performs a deep copy so 
all data inside of parameter being passed is copied as is the dynamically allocated memory pointing to the data. 
@param an lvalue square matrix object is passed meant to be copied */
template<typename ItemType>                                                                
SquareMatrix<ItemType>:: SquareMatrix(const SquareMatrix<ItemType> & rhs) : side_length_(rhs.side_length_) {      
    //cout << "in copy construtor"<<endl;               //In initializer list copy rhs's side length attribute 
                                                        //into side_length_ so new object can share size.
    if(rhs.sqmat != nullptr) {                          //If rhs is not assigned to null then allocate needed memory
        allocateMemory();                               //to copy the matrix being passed as a parameter. Then go through
        for (int i = 0; i < side_length_; i++) {        //every cell of rhs matrix and copy each cells value into 
            for (int j = 0; j < side_length_; j++) {    //the new object's value.
                sqmat[i][j] = rhs.sqmat[i][j];      
            }
        }
    }
}

/* Move Constructor allows for the resources in a rvalue object to be moved 
into an lvalue without copying them like in a copy constructor 
@param an rvalue square matrix object is passed meant to be moved*/
template<typename ItemType>
SquareMatrix<ItemType>::SquareMatrix(SquareMatrix<ItemType> && rhs) : sqmat(rhs.sqmat), side_length_(rhs.side_length_) {   
   //cout << "in move construtor"<<endl;
   rhs.side_length_ = 0;                    //In initializer list sets the objects private attributes to rhs's private attributes.
   rhs.sqmat = nullptr;                     //Then sets the rhs attributes to 0 and nullptr respectively to effectively clear them.
}

/* Copy Assignment called when an initialized square matrix object is assigned 
a new value from an existing sqmare matrix object
@param an lvalue square matrix object is passed meant to be copied */
template<typename ItemType>
SquareMatrix<ItemType>& SquareMatrix<ItemType>::operator=(const SquareMatrix<ItemType> & rhs) {     
    //cout << "in copy assign"<<endl;
    if (this == &rhs) {                             //If matrix is the same as the matrix being passed in
        return *this;                               //just return the matrix since no changes are needed.
    }   
    if(sqmat != nullptr) {                          //if sqmat is not null then only we deallocate
        for(int i = 0; i < side_length_; i++) {     //its content and delete its pointers of the root and arrays
            delete[] sqmat[i];
        }
        delete[] sqmat;
    }
    side_length_ = rhs.side_length_;                //Then assign the private side_length to rhs's side length
    allocateMemory();                               //then call allocate memory to aquire the necessary memory resources
    //sqmat = new ItemType*[rhs.side_length_];      //that sqmat needs based its new side length (rhs's side length)                      
    // for (int i = 0; i < side_length_; i++) {
    //     sqmat[i] = new ItemType[side_length_];
    // }

    for (int i = 0; i < side_length_; i++) {        //Traverse the rows and columns to go to each cell and copy the 
        for(int j = 0; j < side_length_; j++) {     //value in rhs's cell into sqmats cells.
            sqmat[i][j] = rhs.sqmat[i][j];
        }
    }
    
    return *this;           //return the squareobject that underwent assignment
}

/* Move Assignment called when an initialized square matrix object is assigned 
a new value from an existing sqmare matrix object
@param an rval square matrix object is passed meant to be copied and is temporary */
template<typename ItemType>
SquareMatrix<ItemType>& SquareMatrix<ItemType>::operator= (SquareMatrix<ItemType>&& rhs) {     
    //cout << "in move assign"<<endl;

    if(this == &rhs) {                          //If matrix is the same as the matrix being passed in
        return *this;                           //then just return the identical square matrix object
    }
    if(sqmat != nullptr) {
        for(int i = 0; i < side_length_; i++) {     //iterate through the array of ptrs and delete each one
            delete[] sqmat[i];                      //deallocate ptrs in sqmat
        }   
        delete[] sqmat;                             //delete the root ptr that stores the array of ptrs
    }
    side_length_ = rhs.side_length_;            //assign the side length passed into the matrix's private variable
    sqmat = rhs.sqmat;                          //also copy the sqmat of rhs (shallow copy)

    rhs.side_length_ = 0;                       //now set rhs's attributes to 0 and nullptr since the parameter
    rhs.sqmat = nullptr;                        //var is soon to be destroyed so properly reset them

    return *this;                               //return the square matrix object
   
}

/* Equality Operator checks if object passed is equal to another object
@param an object to be compared for equality */
template<typename ItemType>                                                                   
bool SquareMatrix<ItemType>::operator== (const SquareMatrix<ItemType> & rhs) const{
    if(side_length_ != rhs.side_length_) {          //If the side length of the passed object and the other object is 
        return false;                               //not equal return false and dont continue with further comparison
    }

    for (int i = 0; i < side_length_; i++) {           //if side length is same then goes through each corresponsing cell
        for (int j = 0; j < side_length_; j++) {       //of each matrix and check if their value in the cells are the same.
            if(sqmat[i][j] != rhs.sqmat[i][j]) {       //If at any cell the values are not equal then return false.
                return false;                          //If not then return true since every cell is the identical
            }
        }
    }
    return true;    
}

/* Add Operator Assignment adds two objects presuming the objects will be of the same size 
@param a square matrix object that is meant to added to matrix and result is returned */
template<typename ItemType>
SquareMatrix<ItemType> SquareMatrix<ItemType>::operator+ (const SquareMatrix<ItemType> & sm) const{ 
    
    SquareMatrix<ItemType> answer_matrix(side_length_);                 //Make a new square matrix object of the same side length as 
    for (int i = 0; i < side_length_; i++) {                            //passed object and current object. Then iterate through each cell 
        for (int j = 0; j < side_length_; j++) {                        //of the square matrizes and add the corresponsing cells and put the 
            answer_matrix.sqmat[i][j] = sqmat[i][j] + sm.sqmat[i][j];   //added value into the resulting matrix we created in the begining then
        }                                                               //return this resulting matrix.
    }
    return answer_matrix;       
}

/*Size function returns an integer representing the size or side length of a square matrix object.*/
template<typename ItemType>
int SquareMatrix<ItemType>:: size() const {
    return side_length_;    //Acesses the private variable side_length which stores the size of the object
}

/*At function returns the reference returns a reference to the element in the given row and column.
@param two integer variables that represent the row and column the value being accesseed is stored at. */
template<typename ItemType>
ItemType& SquareMatrix<ItemType>::at(int row, int column) {         
    if(!(row >= 0 && column >= 0 && row < side_length_ && column < side_length_)) {    //If statement checks to make sure row and column 
        throw std::out_of_range("Row and column parameters are out of range.");   //passed are valid and can be accessed else throws an exveption
    } 
    //cout << "row col "<< sqmat[row][column] <<endl;
    return sqmat[row][column];                 //If case is passed and the cell is directly accessed and returned
}

/* Resize function resizes a square matrix object to be of a new side length 
@param an integer is passed meant to be the new side length of the matrix. */
template<typename ItemType>
void SquareMatrix<ItemType>::resize(int newSideLength) {
    if(newSideLength >= 0) {            //validating passed new side length to make sure its 0 or higher if invalid int then skip to end
        deallocateMemory();             //dellaocateMemory is called and destroys all previous content of the matrix and released its memory
        side_length_ = newSideLength;   //The objects private attribute of side_length_ is updated to be what is passed as a param
        allocateMemory();               //new memory is allocated and filled with 0's
        fillMatrix(0);
    }
}

/* AllocateMemory allocates the needed space in memory for a matrix object based on 
its sidelength and assigns this new memory to the sqmat attribute of the object. */
template<typename ItemType>
void SquareMatrix<ItemType>::allocateMemory() {    
    //cout << "in allocateMem" << endl;   
                                                    //Makes a new array of type itemtype and of size side_length
    sqmat = new ItemType*[side_length_];            //and each element in array is has a ptr assigned an array of 
    for(int i = 0; i < side_length_; i++) {         //size side_length thus allocating enough space for 
        sqmat[i] = new ItemType[side_length_];      //the square matrix object 
    }
}

/* DeallocateMemory destroys previous content of a matrix and released 
its memory resources properly. */
template<typename ItemType>
void SquareMatrix<ItemType>::deallocateMemory() {        
   // cout << "in deallocateMem" << endl;
    if(sqmat != nullptr) {                                  //Iterates through the pointers that all store their own arrays 
        for(int i = 0; i < side_length_; i++) {             //and deletes each pointer for each element in array 
            delete[] sqmat[i];                              //then delete the sqmat pointer and sets it to nullptr to 
        }                                                   //patch its memory.
        delete[] sqmat;
        sqmat = nullptr;
    }     
}

/* Fill Matrix sets all the cells in a square matrix object to the value passed as a paramter
@param a value of itemtype meant for every cell in a square matrix to have.
*/
template<typename ItemType>
void SquareMatrix<ItemType>::fillMatrix(const ItemType& value) {
    for (int i = 0 ; i < side_length_; i++) {               //Iterate through each row and iterate through each column
        for (int j = 0 ; j < side_length_; j++) {           
            sqmat[i][j] = value;                            //Assign each cell's value to the value passed as a parameter
        }
    }
}

/* Display function to print out all the cells in a square matrix object. 
@param square matrix object to be printed */
template<typename ItemType>
void SquareMatrix<ItemType>::displayMatrix(const SquareMatrix<ItemType> & sm) {
        for (int i = 0; i < sm.side_length_; i++) {             //Iterate through each row and iterate through each column
            for (int j = 0; j < sm.side_length_; j++) {          
                cout << sm.sqmat[i][j] << " ";                  //Print each element/cell in the matrix 
            }
            cout << endl;
        }
        cout << endl;
}