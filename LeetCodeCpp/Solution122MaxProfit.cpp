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

using namespace std;

class Solution122MaxProfit
{
public:
	int maxProfit1(vector<int>& prices) {
		int earn = 0;

		int currentMinPrices = INT32_MAX;
		int currentMaxPrices = INT32_MIN;

		int pricesSize = prices.size();
		for (int i = 0; i < pricesSize; i++)
		{
			if (prices[i] < currentMinPrices) {
				if (currentMaxPrices != INT32_MIN) {
					earn += currentMaxPrices - currentMinPrices;
					currentMaxPrices = INT32_MIN;
				}
				currentMinPrices = prices[i];
			}
			else if (prices[i] >= currentMaxPrices) {
				currentMaxPrices = prices[i];
			}
			else {
				earn += currentMaxPrices - currentMinPrices;
				currentMinPrices = prices[i];
				currentMaxPrices = INT32_MIN;
			}
		}

		// 遍历到最后没有卖出
		if (currentMaxPrices != INT32_MIN) {
			earn += currentMaxPrices - currentMinPrices;
		}

		return earn;
	}

	int maxProfit(vector<int>& prices) {
		int pricesSize = prices.size();

		int sell = 0;
		int buy = -prices[0];

		for (int i = 0; i < pricesSize; i++)
		{
			int newSell = max(sell, buy + prices[i]);
			int newBuy = max(buy, sell - prices[i]);
			sell = newSell;
			buy = newBuy;
		}

		return sell;
	}
};

//int main() {
//	vector<int> prices{ 7,1,5,3,2,6,7 };
//	Solution122MaxProfit solution;
//	solution.maxProfit(prices);
//}