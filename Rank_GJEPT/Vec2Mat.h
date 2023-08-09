#include <iostream>
#include <vector>

using namespace std;
template <typename T>
// Function to transform vector to matrix.
vector<vector<T>> Vec2Mat(vector<T> vec, int cols) {
   int  vecSize = vec.size();

   // Padding the vector with 0s to match number of columns
   while (vecSize % cols != 0)
   {
      vec.push_back(0);
      vecSize++;
   }

   // Creating a 2D vector to represent the matrix
   vector<vector<T>> matrix;

   for (int i = 0; i < vecSize; i += cols) {
      vector<T> row;
      for (int j = 0; j < cols; j++) {
         row.push_back(vec[i + j]);
      }
      matrix.push_back(row);
   }


   return matrix;
}

//int main() {
//   int cols;
//   cout << "Enter number of columns: ";
//   cin >> cols;
//
//   // Vector can be input by the user in a real scenario
//   vector<int> vec = { 1, 2, 3, 4, 5 };
//
//   vector<vector<int>> matrix = Vec2Mat(vec, cols);
//
//   // Printing matrix
//   for (auto& row : matrix) {
//      for (auto& elem : row) {
//         cout << elem << " ";
//      }
//      cout << "\n";
//   }
//
//   return 0;
//}
