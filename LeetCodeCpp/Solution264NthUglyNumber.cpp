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

class Solution264NthUglyNumber
{
public:
	int nthUglyNumber1(int n) {
		vector<int> factors{ 2,3,5 };
		unordered_set<long long> seen;
		priority_queue<long long, vector<long long>, greater<long long>> heap;

		seen.insert(1);
		heap.push(1);
		int ugly = 0;

		for (int i = 0; i < n; i++)
		{
			long long current = heap.top();
			heap.pop();
			ugly = (int)current;
			for (auto& factor : factors) {
				long long next = current * factor;
				if (seen.find(next) == seen.end()) {
					seen.insert(next);
					heap.push(next);
				}
			}
		}

		return ugly;
	}

	int nthUglyNumber(int n) {
		vector<int> dp(n + 1);
		dp[1] = 1;
		int p2 = 1;
		int p3 = 1;
		int p5 = 1;

		for (int i = 2; i <= n; i++)
		{
			int num2 = dp[p2] * 2;
			int num3 = dp[p3] * 3;
			int num5 = dp[p5] * 5;
			dp[i] = min(min(num2, num3), num5);

			if (dp[i] == num2) {
				++p2;
			}
			if (dp[i] == num3) {
				++p3;
			}
			if (dp[i] == num5) {
				++p5;
			}
		}

		return dp[n];
	}
};

int main() {
	Solution264NthUglyNumber solution;
	solution.nthUglyNumber(10);
	solution.nthUglyNumber(1314);
}