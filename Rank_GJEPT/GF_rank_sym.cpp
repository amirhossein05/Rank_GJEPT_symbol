#include <iostream>
#include <vector>
#include <algorithm>
#include "swap.h"
#include "Readcsv.h"
#include "Mod.h"
#include "gfAnd.h"
#include "gfAdd.h"
#include "gfTable.h"
#include "Vec2Mat.h"

using namespace std;


vector<vector<int>> Mapping(vector<vector<int>> R, vector<vector<int>>& e2p)
{

	// Add gf Table
	
	for (int i = 0; i < R[0].size(); i++) { // number of columns
		for (int j = 0; j < R.size(); j++) { // number of Rows
			if (R[i][j] != 0) {
				for (int k = 0; k < e2p[0].size(); k++) {
					if (e2p[0][k] == R[i][j]) {
						R[i][j] = k + 1;
						break;
					}
				}
			}
		}
	}
	return R;
}


vector<vector<int>> GJEP_symbol(vector<vector<int>> R, int n, vector<vector<int>>& e2p, vector<int>& p2e)
{
	
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
			int RII = R[i][i];
			int ele2 = Mod(n - RII, n);
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
					int RJI = R[j][i];
					int ele2 = Mod(n - RJI, n);
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
	//ctor< vector<int>> R= { {3, 1, 0}, {0, 2, 0}, {3, 1, 0} };
	vector<int> csvData = readCSV<int>("data.csv");
	int cols = 255;
	
	vector<vector<int>> R = Vec2Mat(csvData, cols);
	// creat n*n matrix
	while (R.size() > R[0].size()) {
		R.pop_back(); // This removes the last row. Change this if you want to remove a different row.
	}
	//// Print n*n matrix
	//cout << "\nTransformed matrix:" << endl;
	//for (const auto& row : R) {
	//	for (int num : row) {
	//		cout << num << " ";
	//	}
	//	cout << endl;
	//}

	int n = 255;
	int m = 8;
	int prim_poly = 285;
	vector<int> twos;
	for (int i = 0; i <= 2 * m - 2; i++) {
		twos.push_back(pow(2, i));
	}
	
	vector<vector<int>> e2p = e2p_table(m, prim_poly, twos);
	vector<int> p2e = sort_indexes(e2p, m);
	vector< vector<int>> R_new = Mapping(R,e2p);
	vector< vector<int>> R_final = GJEP_symbol(R_new, n,e2p,p2e);
	// Print the modified R matrix
	/*for (size_t i = 0; i < R_final.size(); i++) {
		for (size_t j = 0; j < R_final[0].size(); j++) {
			cout << R_final[i][j] << " ";
		}
		cout << endl;
	}*/

	int Rank = 0;

	// Iterate over each row
	for (const auto& row : R_final) {
		// Check if the row contains any non-zero elements
		if (any_of(row.begin(), row.end(), [](int i) {return i != 0; })) {
			Rank++;
		}
	}

	cout << "Rank of matrix is: " << Rank - 1 << endl;
	
	return 0;
}