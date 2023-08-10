#include "stdafx.h"

using namespace std;

class Solution152MaxProduct
{
public:
	int maxProduct(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize == 0) {
			return 0;
		}

		int maxProduct = nums[0];
		int minProduct = nums[0];
		int result = nums[0];
		for (int i = 1; i < numsSize; i++)
		{
			int preMaxProduct = maxProduct;
			int preMinProduct = minProduct;
			maxProduct = max(preMaxProduct * nums[i], max(preMinProduct * nums[i], nums[i]));
			minProduct = min(preMaxProduct * nums[i], min(preMinProduct * nums[i], nums[i]));
			result = max(result, maxProduct);
		}
		return result;
	}
};

//int main() {
//	vector<int> nums1{ 2,3,-2,4,-2 };
//	vector<int> nums2{ 2,3,0,4,-2 };
//	vector<int> nums3{ -2,0,-1 };
//
//	Solution152MaxProduct solution;
//	cout << solution.maxProduct(nums1) << endl;
//	cout << solution.maxProduct(nums2) << endl;
//	cout << solution.maxProduct(nums3) << endl;
//}
