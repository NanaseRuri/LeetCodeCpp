#include "stdafx.h"

using namespace std;

class Solution070CimbStairs
{
public:
	int climbStairs(int n) {
		int* dp = new int[2]{ 1,2 };
		for (int i = 2; i < n; i++)
		{
			dp[(i % 2)] += dp[((i + 1) % 2)];
		}

		return dp[(n - 1) % 2];
	}
};
