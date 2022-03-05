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

class Solution2016MaximumDifference
{
public:
	int maximumDifference(vector<int>& nums) {
		int preMin = nums[0];
		int result = -1;
		int numsSize = nums.size();

		for (int i = 1; i < numsSize; i++)
		{
			if (nums[i] > preMin) {
				result = max(result, nums[i] - preMin);
			}
			else {
				preMin = nums[i];
			}
		}

		return result;
	}
};
