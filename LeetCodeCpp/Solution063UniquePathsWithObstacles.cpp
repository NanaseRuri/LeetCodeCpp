#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution063UniquePathsWithObstacles {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int totalCol = obstacleGrid[0].size();
		int totalRow = obstacleGrid.size();
		int* dp = new int[totalCol] {};
		dp[0] = 1;
		for (int i = 0; i < totalRow; i++)
		{
			for (int j = 0; j < totalCol; j++)
			{
				if (obstacleGrid[i][j] == 1) {
					dp[j] = 0;
				}
				else {
					if (j - 1 >= 0) {
						dp[j] += dp[j - 1];
					}
				}
			}
		}
		return dp[totalCol - 1];
	}
};

//int main() {
//	vector<vector<int>> nums{ {0,1},{0,0} };
//	Solution063UniquePathsWithObstacles solution;
//	solution.uniquePathsWithObstacles(nums);
//}