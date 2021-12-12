#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution081Search
{
public:
	bool search(vector<int>& nums, int target) {
		int numsSize = nums.size();
		if (target == nums[0] || target == nums[numsSize - 1]) {
			return true;
		}
		int left = 0;
		int right = numsSize - 1;
		int middle;

		while (left <= right)
		{
			middle = (left + right) / 2;
			if (nums[middle] == target) {
				return true;
			}

			if (nums[middle] == nums[left] && nums[middle] == nums[right]) {
				++left;
				--right;
			}
			else if (nums[middle] >= nums[left]) {
				if (nums[middle] > target && target >= nums[left]) {
					right = middle - 1;
				}
				else {
					left = middle + 1;
				}
			}
			else {
				if (nums[middle] < target && target <= nums[right]) {
					left = middle + 1;
				}
				else {
					right = middle - 1;
				}
			}
		}

		return false;
	}
};

//int main() {
//	vector<int > nums{ 1,0,1,1,1 };
//	Solution081Search solution;
//	solution.search(nums, 0);
//}