#include "stdafx.h"

using namespace std;

class Solution064MinPathSum {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int rowCount = grid.size();
		int colCount = grid[0].size();

		int* dp = new int[colCount] {};

		dp[0] = grid[0][0];
		for (int j = 1; j < colCount; j++)
		{
			dp[j] = dp[j - 1] + grid[0][j];
		}

		for (int i = 1; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++) {
				if (j - 1 >= 0) {
					dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
				}
				else {
					dp[j] += grid[i][j];
				}
			}
		}
		return dp[colCount - 1];
	}
};
