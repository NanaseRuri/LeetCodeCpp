#include "stdafx.h"

using namespace std;
class Solution2367ArithmeticTriplets
{
public:
	int arithmeticTriplets(vector<int>& nums, int diff) {
		unordered_set<int> mySet;

		int result = 0;
		for (auto& num : nums) {
			if (mySet.find(num - diff) != mySet.end() && mySet.find(num - 2 * diff) != mySet.end()) {
				result++;
			}
			mySet.insert(num);
		}

		return result;
	}

	int arithmeticTriplets1(vector<int>& nums, int diff) {
		int result = 0;
		int middle = 1;
		int right = 2;

		int n = nums.size();

		for (int left = 0; left < n - 2; left++) {
			if (middle <= left) {
				middle = left + 1;
			}

			while (middle < n - 1 && nums[middle] - nums[left] < diff) {
				middle++;
			}

			if (middle >= n - 1 || nums[middle] != nums[left] + diff) {
				continue;
			}

			if (right <= middle) {
				right = middle + 1;
			}

			while (right < n && nums[right] - nums[middle] < diff) {
				right++;
			}

			if (right >= n || nums[right] != nums[middle] + diff) {
				continue;
			}
			else {
				result++;
			}
		}

		return result;
	}
};
