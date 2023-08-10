#include "stdafx.h"

using namespace std;

class Solution279NumSquares
{
public:
	int numSquares(int n) {
		vector<int> dp(n + 1);
		for (int i = 1; i <= n; i++)
		{
			int minN = INT32_MAX;
			for (int j = 1; j * j <= i; j++)
			{
				minN = min(minN, dp[i - j * j]);
			}
			dp[i] = minN + 1;
		}

		return dp[n];
	}
};

//int main() {
//	Solution279NumSquares solution;
//	solution.numSquares(12);
//	solution.numSquares(13);
//}
