#include <iostream>
#include <bitset>
#include <string>

using namespace std;

template<size_t N>
string xorBinaryData(const string& data1, const string& data2) {
   if (data1.length() != data2.length()) {
      cerr << "Error: Binary data lengths do not match." << endl;
      return "";
   }

   bitset<N> bits1(data1);
   bitset<N> bits2(data2);

   bitset<N> result = bits1 ^ bits2;

   return result.to_string().substr(N - data1.length());
}


//int main() {
//   string binaryData1 = "10101110";
//   string binaryData2 = "01101010";
//
//   string result = xorBinaryData(binaryData1, binaryData2);
//
//   if (!result.empty()) {
//      cout << "XOR Result: " << result << endl;
//   }
//
//   return 0;
//}
