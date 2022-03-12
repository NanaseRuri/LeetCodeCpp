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

class Solution309MaxProfit
{
public:
	int maxProfit(vector<int>& prices) {
		int pricesSize = prices.size();
		if (pricesSize == 0) {
			return 0;
		}

		int buy = -prices[0];
		int sellInCold = 0;
		int sellNotInCold = 0;

		for (int i = 0; i < pricesSize; i++)
		{
			int newBuy = max(buy, sellNotInCold - prices[i]);
			int newSellInCold = buy + prices[i];
			int newSellNotInCold = max(sellNotInCold, sellInCold);
			tie(buy, sellInCold, sellNotInCold) = { newBuy,newSellInCold,newSellNotInCold };
		}

		return max(sellInCold, sellNotInCold);
	}
};