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

class Solution221MaximalSquare
{
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();

		vector<int> dp(col + 1);

		int maxBoundary = 0;
		int northWest;
		for (int i = 0; i < row; i++)
		{
			northWest = 0;
			for (int j = 0; j < col; j++)
			{
				int nextNorthWest = dp[j + 1];
				if (matrix[i][j] == '1') {
					dp[j + 1] = min(min(dp[j], dp[j + 1]), northWest) + 1;
					maxBoundary = max(maxBoundary, dp[j + 1]);
				}
				else {
					dp[j + 1] = 0;
				}

				northWest = nextNorthWest;
			}
		}

		return maxBoundary * maxBoundary;
	}
};

//int main() {
//	Solution221MaximalSquare solution;
//	vector<vector<char>> matrix{
//		{'0','1'},
//		{'1','0'},
//	};
//	vector<vector<char>> matrix1{
//		{'1','1','1','1','0'},
//		{'1','1','1','1','0'},
//		{'1','1','1','1','1'},
//		{'1','1','1','1','1'},
//		{'0','0','1','1','1'},
//	};
//
//	solution.maximalSquare(matrix);
//}