#include <iostream>
#include <vector>
#include "swap.h"
using namespace std;

template<typename T>
vector<vector<T>> ZeroMatrix(T n) {
   vector<vector<T>> matrix(n, vector<T>(n, 0));
   return matrix;
}
template<typename T>
vector<vector<T>> ZeroVector(T n) {
   vector<vector<T>> matrix(1, vector<T>(n, 0));
   return matrix;
}

//int main() {
//   int n = 5; // Size of the matrix
//
//   vector<vector<int>> Zeroes = ZeroVector(n);
//
//   // Print the zero matrix
//  /* for (int i = 0; i < n; i++) {
//      for (int j = 0; j < n; j++) {
//         cout << Zeroes[i][j] << " ";
//      }
//      cout << endl;
//   }*/
//   printMatrix(Zeroes);
//
//   return 0;
//}
