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

class Solution220ContainsNearbyAlmostDuplicate
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int numsSize = nums.size();
		set<int> numsSet;
		for (int i = 0; i < numsSize; i++)
		{
			if (i > k) {
				numsSet.erase(nums[i - k - 1]);
			}
			auto iter = numsSet.lower_bound(max(nums[i], INT32_MIN + t) - t);
			if (iter != numsSet.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
				return true;
			}
			numsSet.insert(nums[i]);
		}

		return false;
	}

	int GetBucketId(int x, long w) {
		// +1 确保如 -10 - -1 分到的桶与 0 - 9 分到的分子相同，然后 -1 确保分到的桶号从 -1 开始
		return x < 0 ? (x + 1ll) / w - 1 : x / w;
	}
	bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
		unordered_map<int, int> mp;
		int numsSize = nums.size();

		for (int i = 0; i < numsSize; i++)
		{
			long currentNum = nums[i];
			int id = GetBucketId(currentNum, t + 1ll);
			if (mp.find(id) != mp.end()) {
				return true;
			}
			if (mp.find(id - 1) != mp.end() && abs(currentNum - mp[id - 1]) <= t) {
				return true;
			}
			if (mp.find(id + 1) != mp.end() && abs(currentNum - mp[id + 1]) <= t) {
				return true;
			}
			mp[id] = currentNum;
			if (i >= k) {
				mp.erase(GetBucketId(nums[i - k], t + 1ll));
			}
		}

		return false;
	}
};