#include "stdafx.h"

using namespace std;

class Solution1630CheckArithmeticSubarrays
{
public:
	vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		int n = l.size();
		vector<bool> result;
		for (int i = 0; i < n; i++) {
			int left = l[i];
			int right = r[i];
			int maxValue = *max_element(nums.begin() + left, nums.begin() + right + 1);
			int minValue = *min_element(nums.begin() + left, nums.begin() + right + 1);

			if (maxValue == minValue) {
				result.push_back(true);
				continue;
			}
			if ((maxValue - minValue) % (right - left) != 0) {
				result.push_back(false);
				continue;
			}

			vector<bool> seen(right - left + 1);
			int interval = (maxValue - minValue) / (right - left);
			bool valid = true;
			for (int j = left; j <= right; j++) {
				if ((nums[j] - minValue) % interval) {
					valid = false;
					break;
				}

				int currentIndex = (nums[j] - minValue) / interval;
				if (seen[currentIndex]) {
					valid = false;
					break;
				}
				seen[currentIndex] = true;
			}

			result.push_back(valid);
		}

		return result;
	}
};

//int main() {
//	Solution1630CheckArithmeticSubarrays solution;
//
//	vector<int> nums1{ -12,-9,-3,-12,-6,15,20,-25,-20,-15,-10 };
//	vector<int> l1{ 0,1,6,4,8,7 };
//	vector<int> r1{ 4,4,9,7,9,10 };
//
//	solution.checkArithmeticSubarrays(nums1, l1, r1);
//}
