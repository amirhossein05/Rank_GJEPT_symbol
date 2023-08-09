#include<iostream>
#include<vector>
#include<cmath>
#include<functional>
using namespace std;

template<typename T>
T bitxor(T ele1, T ele2) {
   // Function to convert decimal to binary 
   function<vector<int>(T)> decimalToBinary = [](T n) -> vector<int> {
      vector<int> binary;
      while (n != 0) {
         binary.insert(binary.begin(), n % 2);
         n = n / 2;
      }
      return binary;
   };

   // Function to perform XOR operation on two binary numbers
   function<vector<int>(vector<int>, vector<int>)> binaryXOR = [](vector<int> binary1, vector<int> binary2) -> vector<int> {
      int size1 = binary1.size();
      int size2 = binary2.size();

      // Making the binary numbers of equal size by adding leading 0's
      while (size1 < size2) {
         binary1.insert(binary1.begin(), 0);
         size1++;
      }

      while (size2 < size1) {
         binary2.insert(binary2.begin(), 0);
         size2++;
      }

      vector<int> binary3(max(size1, size2));

      // Calculating XOR 
      for (int i = 0; i < binary3.size(); i++) {
         binary3[i] = binary1[i] ^ binary2[i];
      }

      return binary3;
   };

   // Function to convert binary to decimal
   function<T(vector<int>)> binaryToDecimal = [](vector<int> binary) -> T {
      T decimal = 0;
      for (int i = 0; i < binary.size(); i++) {
         decimal = decimal + binary[i] * pow(2, (binary.size() - 1 - i));
      }
      return decimal;
   };

   vector<int> binary1 = decimalToBinary(ele1);
   vector<int> binary2 = decimalToBinary(ele2);

   vector<int> binary3 = binaryXOR(binary1, binary2);

   T decimal = binaryToDecimal(binary3);

   return decimal;
}
//
//int main() {
//   int ele1, ele2;
//   cout << "Enter two decimal numbers: ";
//   cin >> ele1 >> ele2;
//
//   int result = bitxor(ele1, ele2);
//
//   cout << "The decimal result after XOR operation is: " << result;
//
//   return 0;
//}
