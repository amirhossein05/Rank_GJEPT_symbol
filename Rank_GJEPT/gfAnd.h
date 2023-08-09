#include <iostream>
#include <Readcsv.h>
#include <bitxor.h>
#include <vector>
#include <Mod.h>

using namespace std;

template<typename T>
T gfAnd(T ele1, T ele2, T n, const vector<vector<T>>& e2p)
{
	T gfAnd_val;

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
	int Power = ele1 + ele2;

	if (Power > n)
	{
		Power = Mod(Power, n);
	}
	if (Power == 0)
	{
		Power = n;
	}

	//gfAnd_val = e2p[Power-1][0];
	gfAnd_val = Power;
	return gfAnd_val;
}

//int main() {
//	vector<vector<int>> e2p = readCSV<int>("e2p.csv");
//	vector<vector<int>> p2e = readCSV<int>("p2e.csv");
//	vector<int> vector1 = {1,4,6 };
//	vector<int> vector2 = {3,0, 7 };
//	vector<int> result(vector1.size());
//
//	int n = 7;
//	for (int i = 0; i < vector1.size(); i++) {
//		result[i] = gfAnd(vector1[i], vector2[i], n, e2p);
//		cout << result[i] << endl;
//	}
//	return 0;
//}