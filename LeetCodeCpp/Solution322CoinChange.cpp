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

class Solution322CoinChange
{
public:
	int coinChange(vector<int>& coins, int amount) {
		int dpSize = amount + 1;
		vector<int> dp(dpSize, dpSize);

		int coinsSize = coins.size();

		dp[0] = 0;
		for (int i = 1; i <= amount; i++)
		{
			for (int j = 0; j < coinsSize; j++)
			{
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
};
