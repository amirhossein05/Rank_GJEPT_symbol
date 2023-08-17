#ifndef GFAND_H
#define GFAND_H
#include <iostream>
#include <Readcsv.h>
#include <bitxor.h>
#include <vector>
#include <Mod.h>
#include <ZerosMatrix.h>

using namespace std;

template<typename T>
T gfAnd(T ele1, T ele2, T n, const vector<vector<T>>& e2p)
{
	T gfAnd_val;
	T Power;
	if (ele1 > n) {
		ele1 = Mod(ele1, n);
	}
	if (ele2 > n) {
		ele2 = Mod(ele2, n);
	}
	if (ele2 == 0 || ele1 == 0) {
		Power = 0;
	}

	else {
		Power = ele1 + ele2;
	}


	if (Power > n)
	{
		Power = Mod(Power, n);
		if (Power == 0)
		{
			Power = n;
		}
	}


	//gfAnd_val = e2p[Power-1][0];
	gfAnd_val = Power;
	return gfAnd_val;
}
#endif



//int main() {
//	vector<vector<int>> e2p = readCSV<int>("e2p.csv");
//	vector<vector<int>> p2e = readCSV<int>("p2e.csv");
//	vector<int> vector1 = {3,1,1 };
//	vector<int> vector2 = {4,4, 0 };
//	vector<int> result(vector1.size());
//
//	int n = 7;
//	for (int i = 0; i < vector1.size(); i++) {
//		result[i] = gfAnd(vector1[i], vector2[i], n, e2p);
//		cout << result[i] << endl;
//	}
//	return 0;
//}