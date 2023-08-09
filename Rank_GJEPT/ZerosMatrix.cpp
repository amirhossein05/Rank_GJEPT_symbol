#include <iostream>
#include <vector>
#include "swap.h"
using namespace std;

vector<vector<int>> ZeroMatrix(int n) {
   vector<vector<int>> matrix(n, vector<int>(n, 0));
   return matrix;
}

//int main() {
//   int n = 5; // Size of the matrix
//
//   vector<vector<int>> Zeroes = ZeroMatrix(n);
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
