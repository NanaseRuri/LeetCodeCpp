#include "stdafx.h"

using namespace std;

class Solution653FindTarget {
public:
	bool findTarget(TreeNode* root, int k) {
		unordered_set<int> valueMap;
		stack<TreeNode*> treeNodeStack{ {root} };
		while (!treeNodeStack.empty())
		{
			TreeNode* currentNode = treeNodeStack.top();
			treeNodeStack.pop();
			if (valueMap.find(k - currentNode->val) != valueMap.end()) {
				return true;
			}

			valueMap.insert(currentNode->val);
			if (currentNode->left != nullptr)
			{
				treeNodeStack.push(currentNode->left);
			}
			if (currentNode->right != nullptr) {
				treeNodeStack.push(currentNode->right);
			}
		}

		return false;
	}
};
