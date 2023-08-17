#ifndef GFTABLE_H
#define GFTABLE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <ZerosMatrix.h>
#include <Mod.h>
#include <bitxor.h>
#include <dynamic_bitset.hpp>
#include <boost/lexical_cast.hpp>

template <typename T>
T gfmultiply(T a, T b, T prim_poly, std::vector<T> twos, int m);
using namespace std;
// creat e2p table.
template <typename T>
vector<vector<T>> e2p_table(int m, T prim_poly, vector<T> twos) {
   
   int size_v = static_cast<int>(pow(2, m)) - 1;
   int size_y = static_cast<int>(pow(2, m)) - 1;
   vector<int> y(size_y);
   vector<vector<int>> V;
   vector<vector<int>> e2p;
   vector<vector<int>> temp_e2p;
   

   V = OnesVector(size_v);
   for (int i = 0; i < V.size(); i++) {
      for (int j = 0; j < V[i].size(); j++) {
         V[i][j] *= 2;
      }
   }

  
   for (int i = 0; i < size_y ; i++) {
      y[i] = i;
   }
   int size_zeros = static_cast<int>(pow(2, m));
   vector<vector<int>> z;
   z = ZeroVector(size_zeros);
   
   
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
            z[0][idx] = gfmultiply(z[0][idx], V[0][idx], prim_poly, twos, m);
         }
      }   
   }
   temp_e2p = OnesVector(size_v);
   for (int i = 0; i < temp_e2p[0].size()-1; i++)
   {
      temp_e2p[0][i] = z[0][i + 1];
     
   }
   
   e2p = temp_e2p;
   return e2p;
}

// creat p2e table.
template <typename T>
vector<int> sort_indexes(const vector<vector<T>>& v, int m)
{
   // initialize original index locations
   vector<int> idx(v[0].size());
   
   iota(idx.begin(), idx.end(), 0);

   // sort indexes based on comparing values in v
   sort(idx.begin(), idx.end(),
      [&v](size_t i1, size_t i2) {return v[0][i1] < v[0][i2]; });
   for (int i = 0; i < v[0].size(); i++)
   {
      idx[i] += 1;
      int power = static_cast<int>(pow(2, m) - 1);
      int array = idx[i];
      idx[i] = Mod(array, power);
   }
   return idx;
}

// gfmultiply function.
template <typename T>
T gfmultiply(T a, T b, T prim_poly, vector<T> twos, int m)
{
   
   int y;
   int degY;
   int degQ;
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
   y = 0;
   // temp
   int numBits = m;
   boost::dynamic_bitset<> bin(numBits, a);
   std::string binary = boost::lexical_cast<std::string>(bin);

   reverse(binary.begin(), binary.end());
   
   vector<int> binary_as_vector;
   for (char c : binary) {
      binary_as_vector.push_back(c - '0');
   }


   for (int i = 0; i < binary_as_vector.size(); i++)
   {
      binary_as_vector[i] *= b;
   }
   vector<int> temp(binary_as_vector.size());
   for (int i = 0; i < binary_as_vector.size(); i++)
   {
      temp[i] = binary_as_vector[i] * twos[i];
   }
   for (int idx = 0; idx < m; idx++)
   {
       y = bitxor(y, temp[idx]);
   }
   degY = static_cast<int>(floor(log2(y)));
   degQ = degY - m;
   if (degQ < 0)
   {
      return y;
   }
   else (degQ == 0);
   {
      y = bitxor(y, prim_poly);
   }
   return y;
}
#endif


//int main() {
//   int m = 3;
//   int prim_poly = 11;
//   int size_twos = m - 1;
   /*vector<int> twos;
   for (int i = 0; i <= 2 * m - 2; i++) {
      twos.push_back(pow(2, i));
   }*/
//   /*for (int i = 0; i < twos.size(); i++) {
//      cout << twos[i] << " ";
//   }*/
//   
   /*vector<vector<int>> e2p = e2p_table(m, prim_poly, twos);
   vector<size_t> p2e = sort_indexes(e2p[0],m);*/
//
//   // print the indexes
//   for (auto i : p2e) {
//      cout << i << ' ';
//   }
//   //vector<vector<int>> result = e2p(m, prim_poly, twos);
//
//   //// Print the resulting vectors
//   //for (int i = 0; i < result.size(); i++) {
//   //   for (int j = 0; j < result[i].size(); j++) {
//   //      cout << result[i][j] << " ";
//   //   }
//   //   cout << endl;
//   //}
//   
//   return 0;
//}
