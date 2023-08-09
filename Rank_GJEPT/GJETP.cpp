#include <iostream>
#include <vector>
#include <algorithm>
#include "Vec2Mat.h"
#include "xorBinaryData.h"
#include "Identity.h"
#include "swap.h"

using namespace std;

template <typename T>

vector<vector<T>> GJEPT(vector<T> vec)
{

   cout << "Enter the number of Columns: " << endl;
   int cols;
   cin >> cols;
   vector<vector<int>> R = Vec2Mat(vec, cols);
   size_t l = cols;
   size_t M = R.size();
   vector<vector<int>> A = Identity(M);
   vector<vector<int>> B = Identity(l);


   // ... GJEPT ...

   for (int i = 0; i < l; ++i)
   {
      printMatrix(R);
      
      if (R[i][i] == 0)
      {
         for (int j = i + 1; j < l; ++j)
         {
            if (R[i][j] == 1)
            {
               R = swapColumns(R, i, j);
               printMatrix(R);
               break;
            }
         }
      }
      if (R[i][i] == 0)
      {
         for (int j = i + 1; j < M; ++j)
         {
            if (R[j][i] == 1)
            {
               R = swapRows(R, i, j);
               printMatrix(R);
               break;
            }
         }
      }
      
       if (R[i][i] == 1)
         for (int j = i + 1; j < l; ++j)
         {
            if (R[i][j] == 1)
            {
               for (int ii = 0; ii < R.size(); ++ii)
               {
                R[ii][j] ^= R[ii][i];
               }
            }
            printMatrix(R);
         }

   }


   return R;

}

//int main()
//{
//   vector<int> vec = { 1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1};
//   vector<vector<int>> R = GJEPT(vec);
//   printMatrix(R);
//}
