//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <bitxor.h>
//
//using namespace std;
//
//template<typename T>
//vector<vector<T>> readCSV(string filename) {
//   ifstream file(filename);
//
//   vector<vector<T>> data;
//   string line;
//
//   while (getline(file, line)) {
//      vector<T> row;
//      stringstream s(line);
//      string word;
//
//      while (getline(s, word, ',')) {
//         row.push_back(stoi(word));
//      }
//
//      data.push_back(row);
//   }
//
//   return data;
//}
//// Calculate Mod
//int Mod(int dividend, int divisor) {
//   int mod = (dividend % divisor + divisor) % divisor;
//   return mod;
//}
//
//// GF ADD
//int gfadd(int ele1, int ele2, int n, const vector<vector<int>>& e2p, const vector<vector<int>>& p2e)
//{
//   int gfaddval;
//
//   if (ele1 > n) {
//      ele1 = Mod(ele1, n);
//      if (ele1 == 0) {
//         ele1 = n;
//      }
//   }
//   if (ele2 > n) {
//      ele2 = Mod(ele2, n);
//      if (ele2 == 0) {
//         ele2 = n;
//      }
//   }
//   if (ele1 == 0)
//   {
//      gfaddval = ele2;
//   }
//   else if (ele2 == 0)
//   {
//      gfaddval = ele1;
//   }
//   else {
//      for (int i = 0; i < e2p[ele1].size(); i++)
//      {
//         gfaddval = bitxor(e2p[ele1][i], e2p[ele2][i]);
//      }
//
//      if (gfaddval == 1) {
//         gfaddval = n;
//      }
//      else if (gfaddval != 0) {
//         gfaddval = p2e[gfaddval - 1][0];
//      }
//   }
//   return gfaddval;
//}
//
////int main() {
////   vector<vector<int>> e2p = readCSV<int>("e2p.csv");
////   vector<vector<int>> p2e = readCSV<int>("p2e.csv");
////   int ele1 = 5;
////   int ele2 = 6;
////   int n = 255;
////   int X = gfadd(ele1, ele2, n, e2p, p2e);
////   cout << X << endl;
////   return 0;
////}
