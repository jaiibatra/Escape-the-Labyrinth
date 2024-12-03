/*
Jai Batra
CS 211: Project 6
*/

//-------------------------------------------------
// TODO:  Update the member function comments in 
//        your own style.
//-------------------------------------------------

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct ROW {
    T*  Cols;     // array of column elements
    size_t NumCols;  // total # of columns (0..NumCols-1)
  };

  ROW* Rows;     // array of ROWs
  size_t  NumRows;  // total # of rows (0..NumRows-1)
    
public:
  //
  // default constructor:
  //
  // Called automatically by to construct a 4x4 Grid. 
  // All elements initialized to default value of T.
  //
  Grid() {
    Rows = new ROW[4];  // 4 rows
    NumRows = 4;

    // initialize each row to have 4 columns:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r].Cols = new T[4];
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (size_t c = 0; c < Rows[r].NumCols; ++c) {
        Rows[r].Cols[c] = T();  // default value for type T:
      }
    }
  }

  //
  // parameterized constructor:
  //
  // Called automatically to construct a Grid 
  // with R rows, where each row has C columns. 
  // All elements initialized to default value of T.
  //
  Grid(size_t R, size_t C) {
    //Write invalid argument for if the grid has 0 rows and columns (Lab 11)
    if (R < 1) { 
        throw invalid_argument("Grid::constructor: # of rows");
    }
    if (C < 1) {
        throw invalid_argument("Grid::constructor: # of cols");
    }

    Rows = new ROW[R]; //Allocates memory for the rows
    NumRows = R; //Total number of rows is set to R

    for (size_t r = 0; r < NumRows; ++r) { //Looping through each row and adding a column
        Rows[r].Cols = new T[C];
        Rows[r].NumCols = C;

        for (size_t c = 0; c < Rows[r].NumCols; ++c) { //Looping through the columns
            Rows[r].Cols[c] = T();  //Sets each column in the row to T (similar to lab but instead of space its a T)
        }
    }
}
    
  //
  // destructor:
  //
  // Called automatically to free memory for this Grid.
  //
  virtual ~Grid() {
    //Similar to the lab 11 destructor
    for(size_t r = 0; r < NumRows; r++){ 
        delete[] Rows[r].Cols; //Frees the memory for each column in the row
    }

    delete[] Rows; //In cpp, we use the delete[] instead of free() 

  }


  //
  // copy constructor:
  //
  // Called automatically to construct a Grid that contains a
  // copy of an existing Grid.  Example: this occurs when passing
  // Grid as a parameter by value
  //
  //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
  //   { ... }
  //
  Grid(const Grid<T>& other) {
      this->Rows = new ROW[other.NumRows];  //Copying other.NumRows into the Rows
        this->NumRows = other.NumRows; //Copies the number of rows from other to numRows

        for (size_t r = 0; r < other.NumRows; ++r) { //Copies each row and column from other
            size_t other_numcols = other.Rows[r].NumCols;

            this->Rows[r].Cols = new T[other_numcols]; //Allocating memory for the number of columns from the other columns
            this->Rows[r].NumCols = other_numcols; //Initializing the number of columns to other

            for (size_t c = 0; c < other_numcols; ++c) { //Copies each character from the grid of other to the new grid
                this->Rows[r].Cols[c] = other.Rows[r].Cols[c];
        }
    }
}
    
  //
  // copy operator=
  //
  // Called when one Grid is assigned into another, i.e. this = other;
  //
  Grid& operator=(const Grid& other) {
      Grid<T> temp;
      if (this == &other) {
            return *this; //If other is assigning to itself, then return *this
        }
        
        for (size_t r = 0; r < NumRows; ++r) {
            delete[] Rows[r].Cols; //freeing the columns within the rows
        }
        delete[] Rows; //freeing the rows itself
        
        //Same as the copy constructor
        this->Rows = new ROW[other.NumRows]; 
        this->NumRows = other.NumRows;
        
        for (size_t r = 0; r < other.NumRows; ++r) {
            size_t other_numcols = other.Rows[r].NumCols;
            
            this->Rows[r].Cols = new T[other_numcols]; //Also similar to lab 11 but instead of char we use T
            this->Rows[r].NumCols = other_numcols;
            
            for (size_t c = 0; c < other_numcols; ++c) {
                this->Rows[r].Cols[c] = other.Rows[r].Cols[c];
            }
        }
        return *this;
  }

  //
  // numrows
  //
  // Returns the # of rows in the Grid.  
  // The indices for these rows are 0..numrows-1.
  //
  size_t numrows() const {
    return NumRows; //Just a simple return statement (also similar to lab 11)
  }
  

  //
  // numcols
  //
  // Returns the # of columns in row r.  
  // The indices for these columns are 0..numcols-1.  
  // For now, each row has the same number of columns.
  //
  size_t numcols(size_t r) const {
   if(r >= NumRows){
    throw invalid_argument("numcols: out of range");
   } 
   return Rows[r].NumCols; //Returns number of columns in row
}


  //
  // size
  //
  // Returns the total # of elements in the Grid.
  //
  size_t size() const {
    size_t totalElements = 0;
    for(size_t r = 0; r < NumRows; r++){
        totalElements += Rows[r].NumCols;
    }
    return totalElements;
  }


  //
  // ()
  //
  // Returns a reference to the element at location (r, c);
  // this allows you to access or assign the element:
  //
  //    grid(r, c) = ...
  //    cout << grid(r, c) << endl;
  //
  T& operator()(size_t r, size_t c) { //Similar to setCellValue from lab 11
      if(r >= NumRows){
        throw invalid_argument("Grid::operator(): row is out of range");
      }
      if(c >= Rows[r].NumCols){
        throw invalid_argument("Grid::operator(): col is out of range");
      }
      return Rows[r].Cols[c]; 
  }

  //
  // _output
  //
  // Outputs the contents of the grid; for debugging purposes.  
  // This is not tested.
  //
  void _output() {
    for (size_t r = 0; r < NumRows; ++r) { //Going through the numRows
        cout << "| "; 
        for (size_t c = 0; c < Rows[r].NumCols; ++c) {
            cout << Rows[NumRows-r-1].Cols[c] << " | "; //Prints each column in reverse order
        }
        cout << endl; //Moves to the next line after each row
        }
    }
};
