#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <ZerosMatrix.h>
#include <dynamic_bitset.hpp>
#include <boost/lexical_cast.hpp>


using namespace std;
// creat e2p table.
vector<vector<int>> e2p(int m, int prim_poly, int twos)
{
   int size_v = pow(2, m) - 1;
   vector<vector<int>> V = OnesVector(size_v);
   
   for (int i = 0; i < V.size(); i++) {
      for (int j = 0; j < V[i].size(); j++) {
         V[i][j] *= 2;
      }
   }

   int size_y = pow(2, m) - 1;
   vector<int> y(size_y);
   for (int i = 0; i < size_y - 1; i++) {
      y[i] = i;
   }
   int size_zeros = pow(2, m);
   vector<vector<int>> z = ZeroVector(size_zeros);
   
   
   for (int idx = 0; idx < size_v;idx++) 
   {
      if (y[idx] * V[0][idx] == 0)
      {
         z[0][idx] = (y[idx] == 0);
      }
      else 
      {
         z[0][idx] = V[0][idx];
         for ( int count = 1; count < y[idx]; count++)
         {
            z[0][idx] = 1111111;
         }
      }   
   }
   return z;
}


int gfmultiply(int a,int b ,int prim_poly,int twos, int m)
{
   
   int y;
   if (prim_poly <=3)
   {
       y = a * b;
      return y;
   }
   if (a * b == 0)
   {
       y = 0;
      return y;
   }
   int numBits = m;
   boost::dynamic_bitset<> bin(numBits, a);
   std::string binary = boost::lexical_cast<std::string>(bin);

   reverse(binary.begin(), binary.end());


}


int main() {
   int m = 8;
   int prim_poly = 7;
   int size_twos = m - 1;
   vector<int> twos(size_twos);
   for(int i=0;i < size_twos;i++)
   {
      vector<int> twos[i] = pow(2, i);
   }

   vector<vector<int>> result = e2p(m, prim_poly, twos);

   // Print the resulting vectors
   for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
         cout << result[i][j] << " ";
      }
      cout << endl;
   }
   
   return 0;
}
