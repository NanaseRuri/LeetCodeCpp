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

class Solution098IsValidBST
{
public:
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}

		stack<TreeNode*> parentNodes;

		long long lastValue = (long long)INT_MIN - 1;
		while (!parentNodes.empty() || root != nullptr)
		{
			while (root != nullptr)
			{
				parentNodes.push(root);
				root = root->left;
			}
			root = parentNodes.top();
			parentNodes.pop();

			if (root->val <= lastValue) {
				return false;
			}
			lastValue = root->val;
			root = root->right;
		}
		return true;
	}
};

//int main() {
//	vector<int> treeNodeValues{ 20,10,30,7,14,25,35,6,8,13,15,24,26,34,36 };
//
//	TreeNode* head = BuildTreeNode(treeNodeValues);
//
//	Solution098IsValidBST solution;
//	solution.isValidBST(head);
//}