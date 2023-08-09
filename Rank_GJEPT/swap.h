#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function to swap the columns
template<typename T>
vector<vector<T>> swapColumns(vector<vector<T>>& matrix, int col1, int col2) {
   for (auto& row : matrix) {
      swap(row[col1], row[col2]);
   }
   return matrix;
}

// Function to swap the rows
template<typename T>
vector<vector<T>> swapRows(vector<vector<T>>& matrix, int row1, int row2) {
   swap(matrix[row1], matrix[row2]);
   return matrix;
}

// Function to print the matrix
template<typename T>
void printMatrix(const vector<vector<T>>& matrix) {
   for (const auto& row : matrix) {
      for (T val : row) {
         // Use setw to set a fixed width for each element
         // Adjust the number to change the width
         cout << setw(4) << val;
      }
      cout << endl;
   }
   // Add a newline or two after printing the matrix
   cout << endl << endl;
}