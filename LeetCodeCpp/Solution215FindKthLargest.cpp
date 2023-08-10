#include "stdafx.h"

using namespace std;

class Solution215FindKthLargest
{
private:
	int SortUnit(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return left;
		}

		int key = nums[left];
		while (left < right)
		{
			while (left < right && nums[right] <= key)
			{
				right--;
			}
			nums[left] = nums[right];
			while (left < right && nums[left] >= key)
			{
				left++;
			}
			nums[right] = nums[left];
		}
		nums[left] = key;

		return left;
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		k -= 1;
		int left = 0;
		int right = nums.size() - 1;

		int result = SortUnit(nums, left, right);
		while (result != k)
		{
			if (result < k) {
				left = result + 1;
			}
			else {
				right = result - 1;
			}
			result = SortUnit(nums, left, right);
		}

		return nums[result];
	}

	int QuickSelect(vector<int>& a, int l, int r, int index) {
		int q = RandomPartition(a, l, r);
		if (q == index) {
			return a[q];
		}
		else {
			return q < index ? QuickSelect(a, q + 1, r, index) : QuickSelect(a, l, q - 1, index);
		}
	}

	int RandomPartition(vector<int>& a, int l, int r) {
		int i = rand() % (r - l + 1) + l;
		swap(a[i], a[r]);
		return Partition(a, l, r);
	}

	int Partition(vector<int>& a, int l, int r) {
		int key = a[r];
		int i = l - 1;

		for (int j = l; j < r; j++)
		{
			if (a[j] <= key) {
				++i;
				swap(a[i], a[j]);
			}
		}

		++i;
		swap(a[i], a[r]);
		return i;
	}

	int findKthLargest1(vector<int>& nums, int k) {
		srand(time(0));
		return QuickSelect(nums, 0, nums.size() - 1, nums.size() - k);
	}
};

//int main() {
//	Solution215FindKthLargest solution;
//	vector<int> nums1{ 3,2,1,5,6,4 };
//	vector<int> nums2{ 3,2,3,1,2,4,5,5,6 };
//
//	solution.findKthLargest(nums1, 2);
//	solution.findKthLargest(nums2, 4);
//}
