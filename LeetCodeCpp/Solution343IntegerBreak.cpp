#include "stdafx.h"

using namespace std;

class Solution350Intersect {
public:
	int integerBreak(int n) {
		if (n <= 3) {
			return n - 1;
		}
		int quotient = n / 3;
		int remainder = n % 3;
		if (remainder == 0) {
			return (int)pow(3, quotient);
		}
		else if (remainder == 1) {
			return (int)pow(3, quotient - 1) * 4;
		}
		else {
			return (int)pow(3, quotient) * 2;
		}
	}

	int integerBreak1(int n) {
		if (n <= 3) {
			return n - 1;
		}

		vector<int> dp(n + 1);
		dp[2] = 1;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = max(max(max(2 * (i - 2), 2 * dp[i - 2]), 3 * dp[i - 3]), 3 * (i - 3));
		}

		return dp[n];
	}
};
