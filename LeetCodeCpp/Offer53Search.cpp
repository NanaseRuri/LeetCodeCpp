#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include "Node.h"

using namespace std;
class Offer53Search {
public:

	int BinarySearchHigh(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int result = nums.size();

		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (nums[middle] <= target) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
				result = middle;
			}
		}

		return result;
	}

	int BinarySearchLow(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int result = nums.size();

		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (nums[middle] < target) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
				result = middle;
			}
		}

		return result;
	}

	int search(vector<int>& nums, int target) {
		int left = BinarySearchLow(nums, target);
		int right = BinarySearchHigh(nums, target);
		return right - left;
	}
};