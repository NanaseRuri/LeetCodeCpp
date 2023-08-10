#include "stdafx.h"

class Solution931MinFallingPathSum
{
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int col = matrix[0].size();
		int row = matrix.size();
		if (col == 1) {
			int result = 0;
			for (auto& r : matrix)
			{
				result += r[0];
			}
			return result;
		}
		else {
			vector<int> preDp(col);
			vector<int> newDp(col);

			for (auto& r : matrix)
			{
				fill(newDp.begin(), newDp.end(), 0);

				newDp[0] = r[0] + min(preDp[0], preDp[1]);
				for (int j = 1; j < col - 1; j++)
				{
					newDp[j] = r[j] + min(min(preDp[j - 1], preDp[j]), preDp[j + 1]);
				}

				newDp[col - 1] = r[col - 1] + min(preDp[col - 1], preDp[col - 2]);
				swap(newDp, preDp);
			}

			return *min_element(preDp.begin(), preDp.end());
		}
	}
};

//int main() {
//	vector<vector<int>> matrix{ {2, 1, 3}, { 6,5,4 }, { 7,8,9 } };
//
//	Solution931MinFallingPathSum solution;
//	solution.minFallingPathSum(matrix);
//}
