#include "stdafx.h"

using namespace std;

class Solution1582NumSpecial
{
public:
	int numSpecial(vector<vector<int>>& mat) {
		int row = mat.size();
		int col = mat[0].size();

		vector<int> currentCountOfOneInRow(row);
		vector<int> currentCountOfOneInCol(col);

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				currentCountOfOneInRow[i] += mat[i][j];
				currentCountOfOneInCol[j] += mat[i][j];
			}
		}

		int result = 0;
		for (int i = 0; i < row; i++)
		{
			if (currentCountOfOneInRow[i] != 1) {
				continue;
			}
			for (int j = 0; j < col; j++) {
				if (currentCountOfOneInCol[j] != 1) {
					continue;
				}

				if (mat[i][j] == 1)
				{
					result++;
				}
			}
		}

		return result;
	}

};

// int main() {
// 	Solution1582NumSpecial solution;

// 	vector<vector<int>> nums{
// 		{1,0,0},
// 		{0,0,1},
// 		{1,0,0}
// 	};
// 	solution.numSpecial(nums);
// };