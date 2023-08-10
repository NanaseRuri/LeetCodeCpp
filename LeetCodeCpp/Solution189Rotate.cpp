#include "stdafx.h"


using namespace std;

class Solution189Rotate
{
private:
	int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

public:
	void rotate1(vector<int>& nums, int k) {
		int numsSize = nums.size();
		k %= numsSize;
		if (k == 0) {
			return;
		}
		vector<int> rotateNums{ nums.begin() + numsSize - k,nums.end() };

		nums.erase(nums.begin() + numsSize - k, nums.end());
		nums.insert(nums.begin(), rotateNums.begin(), rotateNums.end());
	}

	void rotate2(vector<int>& nums, int k) {
		int numsSize = nums.size();
		k %= numsSize;
		if (k == 0) {
			return;
		}
		vector<int> rotateNums{ nums.begin(), nums.begin() + numsSize - k };

		nums.erase(nums.begin(), nums.begin() + numsSize - k);
		nums.insert(nums.end(), rotateNums.begin(), rotateNums.end());
	}

	void rotate(vector<int>& nums, int k) {
		int numsSize = nums.size();
		k %= numsSize;
		if (k == 0) {
			return;
		}

		int iterationTimes = gcd(k, numsSize);
		for (int start = 0; start < iterationTimes; start++)
		{
			int current = start;
			int preValue = nums[start];
			do {
				int next = (current + k) % numsSize;
				swap(nums[next], preValue);
				current = next;
			} while (current != start);
		}
	}

	void rotate3(vector<int>& nums, int k) {
		int numsSize = nums.size();
		k %= numsSize;
		if (k == 0) {
			return;
		}

		Reverse(nums, 0, numsSize - 1);
		Reverse(nums, 0, k - 1);
		Reverse(nums, k, numsSize - 1);
	}

	void Reverse(vector<int>& nums, int start, int end) {
		while (start < end)
		{
			swap(nums[start], nums[end]);
			start++;
			end--;
		}
	}
};

//int main() {
//	vector<int> nums1{ 1,2,3,4,5,6,7 };
//
//	Solution189Rotate solution;
//	solution.rotate(nums1, 3);
//}
