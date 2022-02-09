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
#include "Node.h"
#include <set>

using namespace std;

class Solution230KthSmallest
{
public:
	int kthSmallest(TreeNode* root, int k) {
		if (root == nullptr) {
			return 0;
		}

		stack<TreeNode*> treeNodeStack;
		int currentCount = 0;
		while (!treeNodeStack.empty() || root != nullptr)
		{
			while (root != nullptr) {
				treeNodeStack.push(root);
				root = root->left;
			}
			root = treeNodeStack.top();
			treeNodeStack.pop();
			++currentCount;
			if (currentCount == k) {
				return root->val;
			}
			root = root->right;
		}

		return 0;
	}
};

//int main() {
//	vector<int> nums1{ 3,1,4, INT32_MAX,2 };
//	vector<int> nums2{ 5,3,6,2,4,INT32_MAX,INT32_MAX,1 };
//	TreeNode* node1 = BuildTreeNode(nums1);
//	TreeNode* node2 = BuildTreeNode(nums2);
//	Solution230KthSmallest solution;
//	cout << solution.kthSmallest(node1, 1) << endl;
//	cout << solution.kthSmallest(node2, 3) << endl;
//}