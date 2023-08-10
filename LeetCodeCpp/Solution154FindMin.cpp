#include "stdafx.h"

using namespace std;

class Solution154FindMin
{
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int middle;

		while (left < right)
		{
			middle = (left + right) / 2;
			if (nums[middle] < nums[right]) {
				right = middle;
			}
			else if (nums[middle] == nums[right]) {
				if (middle == right) {
					right--;
				}
				else {
					right = (middle + right) / 2;
				}
			}
			else
			{
				left = middle + 1;
			}
		}
		return nums[left];
	}
};

//int main() {
//	Solution154FindMin solution;
//	vector<int> nums1{ 2,2,2,3,2 };
//	vector<int> nums2{ 2,2,2,1,2 };
//	vector<int> nums3{ 4,5,6,7,0,1,4 };
//	vector<int> nums4{ 0,1,4,4,5,6,7 };
//	vector<int> nums5{ 1,3,5 };
//	vector<int> nums6{ 2,2,2,0,1 };
//	vector<int> nums7{ 0,1 };
//	cout << solution.findMin(nums1) << endl;
//	cout << solution.findMin(nums2) << endl;
//	cout << solution.findMin(nums3) << endl;
//	cout << solution.findMin(nums4) << endl;
//	cout << solution.findMin(nums5) << endl;
//	cout << solution.findMin(nums6) << endl;
//	cout << solution.findMin(nums7) << endl;
//}
