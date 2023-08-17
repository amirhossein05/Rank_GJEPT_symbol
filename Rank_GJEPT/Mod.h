#ifndef MOD_H
#define MOD_H
#include <iostream>

using namespace std;

// Template function for Mod

template<typename T>
T Mod(T dividend, T divisor) {
   T mod = (dividend % divisor + divisor) % divisor;
   return mod;
}
#endif

//int main() {
//   int intDividend = 10;
//   int intDivisor = 3;
//   int intResult = Mod(intDividend, intDivisor);
//   cout << "Integer Result: " << intResult << endl;
//
//   double doubleDividend = 10.5;
//   double doubleDivisor = 3.2;
//   double doubleResult = Mod(doubleDividend, doubleDivisor);
//   cout << "Double Result: " << doubleResult << endl;
//
//   return 0;
//}
