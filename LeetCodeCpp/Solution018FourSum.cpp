#include "stdafx.h"

using namespace std;

class Solution018FourSum {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int size = nums.size();
		if (size < 4) {
			return result;
		}

		sort(nums.begin(), nums.end());

		for (int left = 0; left < size - 3; left++)
		{
			if (left > 0 && nums[left] == nums[left - 1]) {
				continue;
			}

			for (int middleLeft = left + 1; middleLeft < size - 2; middleLeft++)
			{
				if (middleLeft > left + 1 && nums[middleLeft] == nums[middleLeft - 1])
				{
					continue;
				}

				int right = size - 1;
				int target1 = target - nums[left] - nums[middleLeft];
				for (int middleRight = middleLeft + 1; middleRight < size - 1; middleRight++)
				{
					if (middleRight > middleLeft + 1 && nums[middleRight] == nums[middleRight - 1]) {
						continue;
					}

					while (middleRight < right && nums[middleRight] + nums[right] > target1) {
						right--;
					}

					if (middleRight == right) {
						break;
					}

					if (nums[middleRight] + nums[right] == target1) {
						result.push_back({ nums[left], nums[middleLeft], nums[middleRight], nums[right] });
					}
				}
			}
		}

		return result;
	}

	void QuickSort(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}

		int i = left;
		int j = right;
		int key = nums[left];

		while (i < j) {
			while (i < j && nums[j] >= key) {
				j--;
			}
			nums[i] = nums[j];
			while (i < j && nums[i] <= key) {
				i++;
			}
			nums[j] = nums[i];
		}
		nums[i] = key;

		QuickSort(nums, left, j - 1);
		QuickSort(nums, j + 1, right);
	}
};

//int main() {
//	vector<int> nums{ 5,8,9,2,1,4,6,8,9,7,2,3,5,12 };
//	Solution018FourSum solution;
//	solution.QuickSort(nums, 0, nums.size() - 1);
//	for (int i = 0; i < nums.size(); i++)
//	{
//		cout << nums[i] << '\t';
//	}
//	vector<int> nums1{ 1, 0, -1, 0, -2, 2 };
//	vector<int> nums2{ 2,2,2,2 };
//	vector<int> nums3{ -2,-1,-1,1,1,2,2 };
//	vector<vector<int >> result = solution.fourSum(nums1, 0);
//	for (int i = 0; i < result.size(); i++)
//	{
//		for (int j = 0; j < result[i].size(); j++)
//		{
//			cout << result[i][j] << '\t';
//		}
//		cout << endl;
//	}
//
//	result = solution.fourSum(nums2, 8);
//	for (int i = 0; i < result.size(); i++)
//	{
//		for (int j = 0; j < result[i].size(); j++)
//		{
//			cout << result[i][j] << '\t';
//		}
//		cout << endl;
//	}
//
//	result = solution.fourSum(nums3, 0);
//	for (int i = 0; i < result.size(); i++)
//	{
//		for (int j = 0; j < result[i].size(); j++)
//		{
//			cout << result[i][j] << '\t';
//		}
//		cout << endl;
//	}
//}
