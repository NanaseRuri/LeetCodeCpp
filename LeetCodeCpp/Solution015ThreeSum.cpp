#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution015ThreeSum {
public:

	vector<vector<int>> threeSum2(vector<int>& nums) {
		int numsSize = nums.size();

		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int leftLimit = numsSize - 2;
		int middleLimit = numsSize - 1;
		for (int i = 0; i < leftLimit; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}

			int target = -nums[i];
			int middle = i + 1;
			int right = numsSize - 1;
			while (middle < right)
			{
				if (middle > i + 1 && nums[middle] == nums[middle - 1]) {
					middle++;
					continue;
				}

				int currentSum = nums[middle] + nums[right];
				if (currentSum < target) {
					middle++;
					continue;
				}
				else if (currentSum > target) {
					--right;
					continue;
				}
				else {
					result.emplace_back(vector<int>{nums[i], nums[middle], nums[right]});
					++middle;
					--right;
				}
			}
		}

		return result;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		int size = nums.size();

		if (nums.size() < 3) {
			return vector<vector<int>>();
		}

		vector<vector<int>> result;
		//QuickSort(nums, 0, nums.size() - 1);
		sort(nums.begin(), nums.end());

		int target;
		for (int i = 0; i < size - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			target = -nums[i];
			int k = size - 1;
			for (int j = i + 1; j < size - 1; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}

				while (j < k && nums[j] + nums[k] > target) {
					k--;
				}

				if (j == k) {
					break;
				}

				if (nums[j] + nums[k] == target) {
					result.push_back(vector<int>{nums[i], nums[j], nums[k]});
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
		int key = nums[i];

		while (i < j)
		{
			while (i < j && nums[j] >= key)
			{
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
//	vector<int> nums{ -1,0,1,2,-1,-4 };
//	vector<int> nums4{ -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
//	vector<int> nums5{ -1,0,1,2,-1,-4,-2,-3,3,0,4 };
//	vector<int> nums6{ 1,2,-2,-1 };
//
//	Solution015ThreeSum sum;
//	vector<vector<int>> result = sum.threeSum2(nums);
//	for (int i = 0; i < result.size(); i++)
//	{
//		for (int j = 0; j < result[i].size(); j++) {
//			cout << result[i][j] << '\t';
//		}
//		cout << endl;
//	}
//}