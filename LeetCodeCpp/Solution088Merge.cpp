#include "stdafx.h"

using namespace std;

class Solution088Merge
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int right = m + n - 1;

		int nums1Index = m - 1;
		int nums2Index = n - 1;

		while (nums1Index >= 0 && nums2Index >= 0)
		{
			if (nums1[nums1Index] >= nums2[nums2Index]) {
				nums1[right] = nums1[nums1Index];
				nums1Index--;
			}
			else {
				nums1[right] = nums2[nums2Index];
				nums2Index--;
			}
			right--;
		}

		while (nums2Index >= 0)
		{
			nums1[right] = nums2[nums2Index];
			nums2Index--;
			right--;
		}
	}
};

//int main() {
//	vector<int> nums1{ 1,2,3,0,0,0 };
//	int m = 3;
//	vector<int> nums2{ 0,1,5 };
//	int n = 3;
//
//	Solution088Merge solution;
//	solution.merge(nums1, m, nums2, n);
//}
