#include <iostream>
#include <vector>
#include <algorithm>
#include "Vec2Mat.h"
#include "xorBinaryData.h"
#include "Identity.h"
#include "swap.h"
#include "Readcsv.h"
#include "Mod.h"
#include "bitxor.h"
//#include "ZerosMatrix.h"
//#include "gfAnd.h"
//#include "gfAdd.h"


using namespace std;
template<typename T>
T gfAdd(T ele1, T ele2, T n, const vector<vector<T>>& e2p, const vector<vector<T>>& p2e)
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
		for (T i = 0; i < e2p[ele1-1].size(); i++)
		{
			gfaddval = bitxor(e2p[ele1 - 1][i], e2p[ele2 - 1][i]);
		}

		if (gfaddval == 1) {
			gfaddval = n;
		}
		else if (gfaddval != 0) {
			gfaddval = p2e[gfaddval - 1][0];
		}
	}
	return gfaddval;
}

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


vector<vector<int>> Mapping(vector<vector<int>> R)
{

	// Add gf Table
	vector<vector<int>> e2p = readCSV<int>("e2p.csv");

	for (int i = 0; i < R[0].size(); i++) { // number of columns
		for (int j = 0; j < R.size(); j++) { // number of Rows
			if (R[i][j] != 0) {
				for (int k = 0; k < e2p.size(); k++) {
					if (e2p[k][0] == R[i][j]) {
						R[i][j] = k + 1;
						break;
					}
				}
			}
		}
	}
	return R;
}
vector<vector<int>> GJEP_symbol(vector<vector<int>> R, int n)
{
	vector<vector<int>> e2p = readCSV<int>("e2p.csv");
	vector<vector<int>> p2e = readCSV<int>("p2e.csv");
	for (int i = 0; i < R[0].size(); i++) {
		if (R[i][i] == 0) {
			for (int j = i + 1; j < R[0].size(); ++j) {
				if (R[i][j] == 1) {
					R = swapColumns(R, i, j);
					break;
				}
			}
		}
		if (R[i][i] == 0) {
			for (int j = i + 1; j < R.size(); ++j)
			{
				if (R[j][i] == 1)
				{
					R = swapRows(R, i, j);

					break;
				}
			}
		}
		if (Mod(R[i][i], n) != 0)
		{
			vector<int> ele1 = R[i];
			int ele2 = Mod(n - R[i][i], n);
			if (ele2 == 0)
			{
				ele2 = n;
			}
			//vector<vector<int>>  R;
			for (int j_col = 0; j_col < ele1.size(); j_col++)
			{
				int temp = gfAnd(ele1[j_col], ele2, n, e2p);
				R[i][j_col] = temp;
			}
			for (int j = i + 1; j < R.size(); ++j)
			{
				if (R[j][i] != 0)
				{
					int ele2 = Mod(n - R[j][i], n);
					if (ele2 == 0)
					{
						ele2 = n;
					}
						for (int i_col = 0; i_col < R[0].size(); i_col++) {
							int temp = gfAnd(R[j][i_col], ele2, n, e2p);
							R[j][i_col] = gfAdd(temp, R[i][i_col], n, e2p, p2e);
						}
					
				}
			}
		}
	}
	return R;
}






int main() {
	vector< vector<int>> R = { {3, 1, 0}, {0, 2, 0}, {3, 1, 0} };
	int n = 7;
	vector<vector<int>> e2p = readCSV<int>("e2p.csv");

	vector< vector<int>> R_new = Mapping(R);
	vector< vector<int>> R_final = GJEP_symbol(R_new, n);
	// Print the modified R matrix
	for (size_t i = 0; i < R_final.size(); i++) {
		for (size_t j = 0; j < R_final[0].size(); j++) {
			cout << R_final[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}