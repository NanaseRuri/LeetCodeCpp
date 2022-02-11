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

class Solution238ProductExceptSelf
{
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> result;
		int zeroCount = 0;

		int numsSize = nums.size();
		for (int i = 0; i < numsSize; i++) {
			if (nums[i] == 0) {
				zeroCount++;
			}
		}

		if (zeroCount >= 2) {
			result.assign(numsSize, 0);
		}
		else if (zeroCount == 1) {
			int multipleResult = 1;
			int zeroIndex = 0;
			for (int i = 0; i < numsSize; i++)
			{
				if (nums[i] != 0) {
					multipleResult *= nums[i];
				}
				else {
					zeroIndex = i;
				}
			}

			result.assign(numsSize, 0);
			result[zeroIndex] = multipleResult;
		}
		else {
			int multipleResult = 1;
			for (int i = 0; i < numsSize; i++)
			{
				multipleResult *= nums[i];
			}

			for (int i = 0; i < numsSize; i++)
			{
				result.push_back(multipleResult / nums[i]);
			}
		}

		return result;
	}
};