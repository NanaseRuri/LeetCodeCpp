#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"

using namespace std;

class Solution108SortedArrayToBST
{
private:
	TreeNode* BuildTree(vector<int>& nums, int left, int right) {
		if (left > right) {
			return nullptr;
		}

		int middle = (left + right) / 2;
		TreeNode* root = new TreeNode(nums[middle]);
		root->left = BuildTree(nums, left, middle - 1);
		root->right = BuildTree(nums, middle + 1, right);
		return root;
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return BuildTree(nums, 0, nums.size() - 1);
	}
};

//int main() {
//	Solution108SortedArrayToBST solution;
//	
//	vector<int> nums1{ -10,-3,0,5,9 };
//	solution.sortedArrayToBST(nums1);
//}