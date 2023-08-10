#include "stdafx.h"

using namespace std;

class Solution188MaxProfit
{
public:
    int maxProfit(int k, vector<int>& prices) {
        int pricesSize = prices.size();
        if (pricesSize <= 1 || k == 0) {
            return 0;
        }

        int* buy = new int[k] {};
        int* sell = new int[k] {};

        for (int i = 0; i < k; i++)
        {
            buy[i] = -prices[0];
        }

        for (int i = 1; i < pricesSize; i++)
        {
            buy[0] = max(-prices[i], buy[0]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for (int j = 1; j < k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }

        return sell[k - 1];
    }
};

//int main() {
//    Solution188MaxProfit solution;
//
//    vector<int> nums1{ 2,4,1 };
//    vector<int> nums2{ 3,2,6,5,0,3 };
//    solution.maxProfit(2, nums1);
//    solution.maxProfit(2, nums2);
//}
