#ifndef GFADD_H
#define GFADD_H
#include <iostream>
#include <Readcsv.h>
#include <bitxor.h>
#include <vector>
#include <Mod.h>

using namespace std;

template<typename T>
T gfAdd(T ele1, T ele2, T n, const vector<vector<T>>& e2p, const vector<T>& p2e)
{
	T gfaddval;

	if (ele1 > n) {
		ele1 = Mod(ele1, n);
		if (ele1 == 0) {
			ele1 = n;
		}
	}
	if (ele2 > n) {
		ele2 = Mod(ele2, n);
		if (ele2 == 0) {
			ele2 = n;
		}
	}
	if (ele1 == 0)
	{
		gfaddval = ele2;
	}
	else if (ele2 == 0)
	{
		gfaddval = ele1;
	}
	else {
		for (T i = 0; i < e2p.size();i++)
		{
			gfaddval = bitxor(e2p[i][ele1 - 1], e2p[i][ele2 - 1]);
		}
		
		if (gfaddval == 1) {
			gfaddval = n;
		}
		else if (gfaddval != 0) {
			//gfaddval = p2e[gfaddval - 1][0];
			T p2e_temp = static_cast<int>(p2e[gfaddval - 1]);
			gfaddval = p2e_temp;
		}
	}
	return gfaddval;
}
#endif
//int main() {
//   vector<vector<int>> e2p = readCSV<int>("e2p.csv");
//   vector<vector<int>> p2e = readCSV<int>("p2e.csv");
//   vector<int> vector1 = { 1, 4, 6 };
//   vector<int> vector2 = { 3, 0, 7 };
//   vector<int> result(vector1.size());
//
//   int n = 255;
//   for (int i = 0; i < vector1.size(); i++) {
//      result[i] = gfAdd(vector1[i], vector2[i], n, e2p, p2e);
//      cout << result[i] << endl;
//   }
//
//   return 0;
//}
