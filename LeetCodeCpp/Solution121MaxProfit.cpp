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

class Solution121MaxProfit
{
public:
    int maxProfit(vector<int>& prices) {
        int earn = 0;

        int minPrice = prices[0];
        int pricesSize = prices.size();

        for (int i = 1; i < pricesSize; i++)
        {
            if (prices[i] > minPrice) {
                earn = max(earn, prices[i] - minPrice);
            }
            else {
                minPrice = prices[i];
            }
        }

        return earn;
    }
};