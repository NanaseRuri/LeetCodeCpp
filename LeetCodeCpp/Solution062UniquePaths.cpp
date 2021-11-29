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

class Solution062UniquePaths {
public:
	int uniquePaths(int m, int n) {
		int** dp = new int* [m];
		for (int i = 0; i < m; i++)
		{
			dp[i] = new int[n] {};
		}
		dp[0][0] = 1;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) {
				if (i - 1 >= 0) {
					dp[i][j] += dp[i - 1][j];
				}

				if (j - 1 >= 0) {
					dp[i][j] += dp[i][j - 1];
				}
			}
		}

		return dp[m - 1][n - 1];
	}

	int uniquePaths1(int m, int n) {
		int minValue = min(m, n);
		int maxValue = max(m, n);
		long long result = 1;
		for (int x = 1, y = maxValue; x < minValue; ++x, ++y)
		{
			result = result * y / x;
		}
		return result;
	}
};