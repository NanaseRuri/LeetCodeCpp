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

class Solution055CanJump {
public:
	bool canJump(vector<int>& nums) {
		int numsSize = nums.size() - 1;

		int lastIndex = 0;
		int maxPosition = 0;
		for (int i = 0; i < numsSize; i++)
		{
			maxPosition = max(maxPosition, i + nums[i]);
			if (i == lastIndex) {
				lastIndex = maxPosition;
				if (nums[i] == 0 && i == lastIndex) {
					return false;
				}
			}
		}
		return true;
	}

	bool canJump1(vector<int>& nums) {
		int last = nums.size() - 1;

		for (int i = last - 1; i >= 0; --i)
		{
			if (last <= i + nums[i]) {
				last = i;
			}
		}
		return last == 0;
	}
};

//int main() {
//	Solution055CanJump solution;
//
//	vector<int> nums = { 0 };
//	vector<int> nums1 = { 2,0,0 };
//	vector<int> nums2 = { 2,5,0,0 };
//	vector<int> nums3 = { 1,1,2,2,0,1,1 };
//	vector<int> nums4 = { 2,3,1,1,4 };
//	vector<int> nums5 = { 3,2,1,0,4 };
//	cout << solution.canJump(nums) << endl;
//	cout << solution.canJump(nums1) << endl;
//	cout << solution.canJump(nums2) << endl;
//	cout << solution.canJump(nums3) << endl;
//	cout << solution.canJump(nums4) << endl;
//	cout << solution.canJump(nums5) << endl;
//}