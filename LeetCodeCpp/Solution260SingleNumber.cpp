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

class Solution260SingleNumber
{
public:
	vector<int> singleNumber(vector<int>& nums) {
		int xOrSum = 0;
		for (auto& num : nums)
		{
			xOrSum ^= num;
		}

		int lastBitIsOne = xOrSum == INT32_MIN ? xOrSum : xOrSum & (-xOrSum);
		int result1 = 0;
		int result2 = 0;

		for (auto& num : nums)
		{
			if ((num & lastBitIsOne) == 0)
			{
				result1 ^= num;
			}
			else {
				result2 ^= num;
			}
		}

		return vector<int>{result1, result2};
	}
};