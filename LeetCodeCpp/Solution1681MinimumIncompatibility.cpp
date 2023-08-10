#include "stdafx.h"

using namespace std;

class Solution1681MinimumIncompatibility
{
public:
	int popcount(unsigned int u)
	{
		u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
		u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
		u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
		u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
		u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
		return u;
	}

	int minimumIncompatibility(vector<int>& nums, int k) {
		int n = nums.size();
		int group = n / k;
		vector<int> dp(1 << n, INT32_MAX);
		dp[0] = 0;
		unordered_map<int, int> values;


		for (int mask = 1; mask < 1 << n; mask++) {
			if (popcount(mask) != group) {
				continue;
			}

			unordered_set<int> cur;
			int minValue = INT32_MAX;
			int maxValue = INT32_MIN;

			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					if (cur.find(nums[i]) != cur.end()) {
						break;
					}
					cur.insert(nums[i]);
					minValue = min(minValue, nums[i]);
					maxValue = max(maxValue, nums[i]);
				}
			}

			if (cur.size() == group) {
				values[mask] = maxValue - minValue;
			}
		}

		for (int mask = 0; mask < (1 << n); mask++) {
			if (dp[mask] == -1) {
				continue;
			}

			unordered_map<int, int> seen;
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) == 0) {
					seen[nums[i]] = i;
				}
			}

			if (seen.size() < group) {
				continue;
			}

			int sub = 0;
			for (auto& pair : seen) {
				sub |= (1 << pair.second);
			}

			int next = sub;

			while (next > 0) {
				if (values.find(next) != values.end())
				{
					dp[mask | next] = min(dp[mask | next], dp[mask] + values[next]);
				}
				next = (next - 1) & sub;
			}
		}
		return dp[(1<<n) - 1] == INT32_MAX? -1: dp[(1 << n) - 1];
	}
};
