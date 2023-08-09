#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> getColumn(const vector<vector<T>>& matrix, size_t column) {
   vector<T> colVec;
   for (const auto& row : matrix) {
      if (column < row.size())
         colVec.push_back(row[column]);
   }
   return colVec;
}
//int main() {
//   vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//   vector<int> column = getColumn(matrix, 1); // Get the second column
//   for (const auto& elem : column) {
//      cout << elem << ' ';
//   }
//   cout << '\n';
//}