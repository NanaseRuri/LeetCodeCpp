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

class Solution714MaxProfit
{
public:
	int maxProfit(vector<int>& prices, int fee) {
		int buy = -prices[0];
		int sell = 0;

		int pricesSize = prices.size();
		for (int i = 0; i < pricesSize; i++)
		{
			buy = max(buy, sell - prices[i]);
			sell = max(sell, buy + prices[i] - fee);
		}

		return sell;
	}
};