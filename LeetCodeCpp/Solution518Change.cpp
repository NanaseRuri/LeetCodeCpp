#include "stdafx.h"

using namespace std;

class Solution518Change
{
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1);
		dp[0] = 1;

		for (auto& coin : coins)
		{
			for (int i = coin; i <= amount; i++)
			{
				dp[i] += dp[i - coin];
			}
		}

		return dp[amount];
	}
};
