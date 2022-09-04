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
#include <numeric>

using namespace std;

class Solution2028MissingRolls
{
public:
	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int rollsSize = rolls.size();
		int sumValue = (n + rollsSize) * mean;

		int rollsSum = accumulate(rolls.begin(), rolls.end(), 0);

		int missSum = sumValue - rollsSum;

		vector<int> result;

		if (missSum > n * 6 || missSum < n) {
			return result;
		}
		else
		{
			result.resize(n, missSum / n);
			missSum %= n;
			if (missSum > 0) {
				for (int i = 0; i < missSum; ++i) {
					++result[i];
				}
			}
		}

		return result;
	}
};