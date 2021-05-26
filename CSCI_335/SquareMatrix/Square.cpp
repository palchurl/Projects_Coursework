#ifndef _SQUARE_MATRIX_
#define _SQAURE_MATRIX_
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdexcept>

template<class ItemType>
class SquareMatrix {
    private:
        size_t side_length_;    //Stores the side length of the matrix (or the number of rows or column)
        ItemType ** sqmat;      //Pointer to an array of pointers (2D array)

    public:
        SquareMatrix();                 //Default Constructor                                                                                                         
        SquareMatrix(int sideLength);   //Parameterized Constructor                                                
        
        ~SquareMatrix();                                      //Destructor                         
        SquareMatrix(const SquareMatrix & rhs);               //Copy Constructor                             
        SquareMatrix(SquareMatrix && rhs);                    //Move Constructor                          
        SquareMatrix & operator= (const SquareMatrix & rhs);  //Copy Assignment                           
        SquareMatrix & operator= (SquareMatrix && rhs);       //Move Assignment          

        bool operator== (const SquareMatrix & rhs);                                  //Equality Operator   
        SquareMatrix<ItemType> operator+ (const SquareMatrix<ItemType> & sm);        //Addition Operator
        
        void resize(int newSideLength);          //Resize Matrix to another size                                      
        ItemType& at(int row, int column);       //At gets the reference to a cell in the matrix                            
        void fillMatrix(const ItemType& value);  //Fill Matrix with a value
        int size() const;                                          

        void displayMatrix(const SquareMatrix<ItemType> & sm);  //Print Matrix
        void allocateMemory();                                  //Allocate Space
        void deallocateMemory();                                //Deallocate Space
}; 

#endif


#include <iostream>
using namespace std;

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
    // cout << "in parameterized construtor" << endl;

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
    cout << "in copy construtor"<<endl;               //In initializer list copy rhs's side length attribute 
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
   cout << "in move construtor" << endl;
   rhs.side_length_ = 0;                    //In initializer list sets the objects private attributes to rhs's private attributes.
   rhs.sqmat = nullptr;                     //Then sets the rhs attributes to 0 and nullptr respectively to effectively clear them.
}

/* Copy Assignment 
@param an lvalue square matrix object is passed meant to be copied */
template<typename ItemType>
SquareMatrix<ItemType>& SquareMatrix<ItemType>::operator=(const SquareMatrix<ItemType> & rhs) {     
    cout << "in copy assign" << endl;
    if (this == &rhs) {
        return *this;
    }

    if(sqmat != nullptr) {
        for(int i = 0; i < side_length_; i++) {
            delete[] sqmat[i];
        }
        delete[] sqmat;
    
        sqmat = new ItemType*[rhs.side_length_];                            
        side_length_ = rhs.side_length_;

        for (int i = 0; i < side_length_; i++) {
            sqmat[i] = new ItemType[side_length_];
        }

        for (int i = 0; i < side_length_; i++) {
            for(int j = 0; j < side_length_; j++) {
                sqmat[i][j] = rhs.sqmat[i][j];
            }
        }
    }
    //cout << "in copy assign 2"<<endl;

    return *this;
}

template<typename ItemType>
SquareMatrix<ItemType>& SquareMatrix<ItemType>::operator= (SquareMatrix<ItemType>&& rhs) {     //Move Assignment
    cout << "in move assign"<<endl;

    if(this == &rhs) {
        return *this;
    }

    for(int i = 0; i < side_length_; i++) {
        delete[] sqmat[i];
    }
    delete[] sqmat;

    side_length_ = rhs.side_length_;
    sqmat = rhs.sqmat;

    rhs.side_length_ = 0;
    rhs.sqmat = nullptr;

    return *this;
   
}

/* Equality Operator checks if object passed is equal to another object
@param an object to be compared for equality */
template<typename ItemType>                                                                   
bool SquareMatrix<ItemType>::operator== (const SquareMatrix<ItemType> & rhs) {
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
*/
template<typename ItemType>
SquareMatrix<ItemType> SquareMatrix<ItemType>::operator+ (const SquareMatrix<ItemType> & sm) {  
    SquareMatrix<ItemType> answer_matrix(side_length_);                 //Make a new square matrix object of the same side length as 
    for (int i = 0; i < side_length_; i++) {                            //passed object and current object. Then iterate through each cell 
        for (int j = 0; j < side_length_; j++) {                        //of the square matrizes and add the corresponsing cells and put the 
            answer_matrix.sqmat[i][j] = sqmat[i][j] + sm.sqmat[i][j];   //added value into the resulting matrix we created in the begining then
        }                                                               //return this resulting matrix.
    }

    return answer_matrix;       //return *this
}

/*Size function returns an integer representing the size or side length of a square matrix object.
*/
template<typename ItemType>
int SquareMatrix<ItemType>:: size() const {
    return side_length_;    //Acesses the private variable side_length which stores the size of the object
}

/*At function returns the reference returns a reference to the element in the given row and column.
@param two integer variables that represent the row and column the value being accesseed is stored at.
*/
template<typename ItemType>
ItemType& SquareMatrix<ItemType>::at(int row, int column) {         
    if(!(row >= 0 && row < side_length_ && column >= 0 && column < side_length_)) {     //If statement checks to make sure row and column 
        throw std::out_of_range("Row and column parameters are out of range.");  //passed are valid and can be accessed else throws an exveption
    }
    //cout << "row col "<< sqmat[row][column] <<endl;
    return sqmat[row][column];                               //If case is passed and the cell is directly accessed and returned
}

/* Resize function resizes a square matrix object to be of a new side length 
@param an integer is passed meant to be the new side length of the matrix.
*/
template<typename ItemType>
void SquareMatrix<ItemType>::resize(int newSideLength) {
    if(sqmat != nullptr) {
        deallocateMemory();             //dellaocateMemory is called and destroys all previous content of the matrix and released its memory
        side_length_ = newSideLength;   //The objects private attribute of side_length_ is updated to be what is passed as a param
        allocateMemory();               //new memory is allocated and filled with 0;s
        fillMatrix(0);
    }
}

/* AllocateMemory allocates the needed space in memory for a matrix object based on 
its sidelength and assigns this new memory to the sqmat attribute of the object. */
template<typename ItemType>
void SquareMatrix<ItemType>::allocateMemory() {    
    //cout << "in allocateMem" << endl;   
                                                    //Makes a new array of type itemtype and of size side_length
    sqmat = new ItemType*[side_length_];            //and each element in array is assigned an array of size side_length 
    for(int i = 0; i < side_length_; i++) {         //thus allocating enough space for a square matrix object 
        sqmat[i] = new ItemType[side_length_];  
    }
}

/*DeallocateMemory destroys previous content of a matrix and released 
its memory resources properly. */
template<typename ItemType>
void SquareMatrix<ItemType>::deallocateMemory() {        
   // cout << "in deallocateMem" << endl;
                                                        //Iterates through each row in the object and deletes its pointer
    for(int i = 0; i < side_length_; i++) {             //then deletes the sqmat pointer and sets it to nullptr ro 
        delete[] sqmat[i];                              //patch its memory.
    }
    delete[] sqmat;
    sqmat = nullptr;
}

/*Fill Matrix sets all the cells in a square matrix object to the value passed as a paramter
@param a value of itemtype meant for every cell in a square matrix to have.
*/
template<typename ItemType>
void SquareMatrix<ItemType>::fillMatrix(const ItemType& value){
    for (int i = 0 ; i < side_length_; i++) {               //Iterate through each row and iterate through each column
        for (int j = 0 ; j < side_length_; j++) {           
            sqmat[i][j] = value;                            //Assign each cell's value to the value passed as a parameter
        }
    }
}

/*Display function to print out all the cells in a square matrix object. 
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

int main() {
    
    SquareMatrix<int> sqm(5);
    SquareMatrix<int> sq;
    
    //Testing Default Constructor (W)   Paramterized Constructor(W)   Display(W)  fillMatrix(W)    Destructor(W)

    cout << "Testing  Default Paramterized Display fillMatrix Destructor Size: " << endl;
    
    cout << "sqm display 5*5: " << endl;
    sqm.displayMatrix(sqm);
    
    cout << "sq 0*0: "<<endl;
    sq.displayMatrix(sq);

    cout << "sqm size 5: " << sqm.size() << endl;
    cout << "sqm size 0: " << sq.size() << endl;

    SquareMatrix<int> sqma(4);
    sqma.fillMatrix(5);
    cout<< "Display 4*4 fill 5: " <<endl;
    sqma.displayMatrix(sqma);


    //Resize
    cout << "Testing Resize"<<endl;
    SquareMatrix<int> res(2);
    res.fillMatrix(10);
    cout<<"print resize: "<<endl;
    res.displayMatrix(res);
    
    cout<<"after resize fx: "<<endl;
    res.resize(1);    
    res.displayMatrix(res);       
    
    //Test Equality Operator    == (W)
    SquareMatrix<int> sww;
    SquareMatrix<int> smww;
    cout << "When matrizes are same 0: "<<(sww == smww) << endl;    //T 1
    SquareMatrix<int> sqy(4);
    SquareMatrix<int> sqmy(4);
    cout << "When matrizes are same: "<<(sqy == sqmy) << endl;   //T 1
    SquareMatrix<int> sqtu(4);
    sqtu.fillMatrix(10);
    SquareMatrix<int> sqmtu(4);
    sqmtu.fillMatrix(10);
    cout << "When matrizes are same w fillMatrix "<<(sqtu == sqmtu) << endl;  //T 1
    SquareMatrix<int> sqto(5);
    sqto.fillMatrix(10);
    SquareMatrix<int> sqmto(4);
    sqmto.fillMatrix(10);
    cout << "When matrizes are not same w fillMatrix "<<(sqto == sqmto) << endl;  //F0
    SquareMatrix<int> sqtos(5);
    sqtos.fillMatrix(5);
    SquareMatrix<int> sqmtos(5);
    sqmtos.fillMatrix(10);
    cout << "When matrizes are same w diff fillMatrix "<<(sqtos == sqmtos) << endl;  //F0


    // SquareMatrix<int> tot(4); 
    // tot.fillMatrix(10); 
    // tot.displayMatrix(tot);  //displays all 10s
    // SquareMatrix<int> ip(4);
    // ip.fillMatrix(5);        //new matrix with all 5s
    // tot = ip;
    // ip.displayMatrix(tot);

    //Test Add Operator += (W)      //How to test add operator
    cout <<endl<<"Testing Add operator and move assign"<<endl;
    SquareMatrix<int> siya(2);
    siya.fillMatrix(5);
    siya.displayMatrix(siya);
    SquareMatrix<int> smile(2);
    smile.fillMatrix(1);
    SquareMatrix<int> smqe(2);
    smqe = smile + siya;
    smqe.displayMatrix(smqe);

    //Test at
    cout <<endl<<"Testing At and move"<<endl;
    SquareMatrix<int> sqmgh(4);
    sqmgh.fillMatrix(5);
    cout<< "before changing:  "<< sqmgh.at(0,1)<<endl;
    sqmgh.at(0,1) = 9;
    cout<< "after changing:  "<<sqmgh.at(0,1)<<endl;
    sqmgh.displayMatrix(sqmgh);
    cout<<sqmgh.at(0,1);
    cout<<sqmgh.at(1,0);
    cout<<sqmgh.at(0,0);
    cout<<sqmgh.at(1,1);
    
   
    //Test Copy Constructor (W)
    cout << "Copy Constructor"<<endl;
    SquareMatrix<int> sqmcopy(4);
    sqmcopy.fillMatrix(10);
    SquareMatrix<int> sqeel(sqmcopy);
    sqmcopy.displayMatrix(sqmcopy);
    sqeel.displayMatrix(sqeel);

    //Testing Copy Assignment  (W)
    cout << "Copy Assignment"<<endl;
    SquareMatrix<double> sqmassi(4);
    sqmassi.fillMatrix(10);
    sqmassi.displayMatrix(sqmassi);
    SquareMatrix<double> sqassignment;
    sqassignment = sqmassi;
    sqassignment.displayMatrix(sqassignment);

    //Testing Move Constructor

 
    return 0;
}



/*
TO COMPILE: 
g++ -std=c++11 SquareMatrix.cpp -o pi
./pi

