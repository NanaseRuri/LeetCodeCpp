#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <limits>

using namespace std;

class Solution016ThreeSumClosest {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int size = nums.size();
		int closest = 100000;
		int lastAbs = 100000;
		for (int left = 0; left < size - 2; left++)
		{
			if (left > 0 && nums[left] == nums[left - 1]) {
				continue;
			}

			int right = size - 1;
			int middle = left + 1;
			while (middle < right)
			{
				int sum = nums[left] + nums[middle] + nums[right];
				if (sum == target) {
					return target;
				}

				int abs1 = abs(sum - target);
				if (abs1 < lastAbs) {
					lastAbs = abs1;
					closest = sum;
				}

				if (sum > target) {
					--right;
					while (middle < right && nums[right] == nums[right + 1]) {
						--right;
					}
				}
				else {
					++middle;
					while (middle < right && nums[middle] == nums[middle - 1]) {
						++middle;
					}
				}
			}
		}
		return closest;
	}

	void QuickSort(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}

		int i = left;
		int j = right;
		int key = nums[left];

		while (i < j)
		{
			while (i < j && nums[j] >= key)
			{
				j--;
			}
			nums[i] = nums[j];
			while (i < j && nums[i] <= key)
			{
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
//	vector<int> nums{ 5,3,2,8,6,9,4,2,5,6,8 };
//	vector<int> nums1{ -1,2,1,-4 };
//	vector<int> nums2{ 1,1,1,0 };
//	vector<int> nums3{ 1,1,-1,-1,3 };
//	Solution016ThreeSumClosest solution;
//	//solution.QuickSort(nums, 0, nums.size() - 1);
//	solution.threeSumClosest(nums1, 1);
//	cout << solution.threeSumClosest(nums2, 100) << endl;
//	cout << solution.threeSumClosest(nums3, -1) << endl;
//}