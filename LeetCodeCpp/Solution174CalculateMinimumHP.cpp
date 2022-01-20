#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>

using namespace std;
class Solution174CalculateMinimumHP {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int row = dungeon.size();
		int col = dungeon[0].size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT32_MAX));
		dp[row][col - 1] = dp[row - 1][col] = 1;
		for (int i = row - 1; i >= 0; i--)
		{
			for (int j = col - 1; j >= 0; j--)
			{
				int minLife = min(dp[i+1][j], dp[i][j + 1]);
				dp[i][j] = max(minLife - dungeon[i][j], 1);
			}
		}
		return dp[0][0];
	}
};

//int main() {
//	vector<vector<int>> dungeon{
//		{-2,-3,3},
//		{-5,-10,1},
//		{10,30,-5}
//	};
//	Solution174CalculateMinimumHP solution;
//	solution.calculateMinimumHP(dungeon);
//}