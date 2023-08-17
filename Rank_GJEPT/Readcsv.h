#ifndef READCSV_H
#define READCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

template<typename T>
vector<T> readCSV(string filename) {
   ifstream file(filename);

   vector<T> data;
   string line;

   while (getline(file, line)) {
      stringstream s(line);
      string word;

      while (getline(s, word, ',')) {
         data.push_back(stoi(word));
      }
   }

   return data;
}

#endif




//int main() {
//   vector<vector<int>> csvdata = readCSV<int>("e2p.csv");
//
//   // print the first element of the first row
//   cout << "first element of the first row is: " << csvdata[6][0] << "\n";
//
//   return 0;
//}
