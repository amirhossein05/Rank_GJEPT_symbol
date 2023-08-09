#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

template<typename T>
vector<vector<T>> readCSV(string filename) {
   ifstream file(filename);

   vector<vector<T>> data;
   string line;

   while (getline(file, line)) {
      vector<T> row;
      stringstream s(line);
      string word;

      while (getline(s, word, ',')) {
         row.push_back(stoi(word));
      }

      data.push_back(row);
   }

   return data;
}


//int main() {
//   vector<vector<int>> csvdata = readCSV<int>("e2p.csv");
//
//   // print the first element of the first row
//   cout << "first element of the first row is: " << csvdata[6][0] << "\n";
//
//   return 0;
//}
