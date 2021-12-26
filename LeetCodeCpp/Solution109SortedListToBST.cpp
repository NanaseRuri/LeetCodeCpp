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

class Solution109SortedListToBST
{
private:
	TreeNode* BuildTree(vector<int>& nums, int left, int right) {
		if (left > right) {
			return nullptr;
		}

		int middle = (left + right) / 2;
		TreeNode* head = new TreeNode(nums[middle]);
		head->left = BuildTree(nums, left, middle - 1);
		head->right = BuildTree(nums, middle + 1, right);
		return head;
	}
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums;
		while (head != nullptr)
		{
			nums.push_back(head->val);
			head = head->next;
		}

		return BuildTree(nums, 0, nums.size() - 1);
	}

	TreeNode* sortedListToBST1(ListNode* head) {
		int length = GetLength(head);
		return BuildTree(head, 0, length - 1);
	}

	TreeNode* BuildTree(ListNode*& head, int left, int right) {
		if (left < right) {
			return nullptr;
		}

		int middle = (left + right + 1) / 2;
		TreeNode* root = new TreeNode();
		root->left = BuildTree(head, left, middle - 1);
		head = head->next;
		root->right = BuildTree(head, middle + 1, right);
		return root;
	}

	int GetLength(ListNode* head) {
		int ret = 0;
		while (head != nullptr)
		{
			++ret;
			head = head->next;
		}
		return ret;
	}
};