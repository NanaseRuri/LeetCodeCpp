#include "stdafx.h"

class Solution746MinCostClimbingStairs
{
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int costSize = cost.size();
		if (costSize < 2) {
			return 0;
		}

		int currentCost[2] = { cost[0],cost[1] };
		for (int i = 2; i < costSize; i++) {
			currentCost[i % 2] = min(currentCost[i % 2], currentCost[(i + 1) % 2]) + cost[i];
		}

		return min(currentCost[0], currentCost[1]);
	}
};

//int main() {
//	Solution746MinCostClimbingStairs solution;
//	vector<int> cost1{ 10,15,20 };
//	vector<int> cost2{ 1,100,1,1,1,100,1,1,100,1 };
//	vector<int> cost3{ 0,0,1,1 };
//	solution.minCostClimbingStairs(cost1);
//	solution.minCostClimbingStairs(cost2);
//	solution.minCostClimbingStairs(cost3);
//}
