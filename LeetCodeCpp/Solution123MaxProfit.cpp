#include "stdafx.h"

using namespace std;

class Solution123MaxProfit
{
public:
	int maxProfit(vector<int>& prices) {
		int pricesSize = prices.size();
		int buy1 = -prices[0];
		int sell1 = 0;
		int buy2 = -prices[0];
		int sell2 = 0;

		for (int i = 1; i < pricesSize; i++)
		{
			buy1 = max(buy1, -prices[i]);
			sell1 = max(sell1, buy1 + prices[i]);
			buy2 = max(buy2, sell1 - prices[i]);
			sell2 = max(sell2, buy2 + prices[i]);
		}

		return sell2;
	}
};

//int main() {
//	vector<int> prices{ 3,3,5,0,0,3,1,4 };
//	Solution123MaxProfit solution;
//	solution.maxProfit(prices);
//}
