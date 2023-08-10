#include "stdafx.h"

class Solution404SumOfLeftLeaves {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		int result = 0;
		stack<TreeNode*> nodeStack{ {root} };

		while (!nodeStack.empty())
		{
			TreeNode* currentNode = nodeStack.top();
			nodeStack.pop();

			if (currentNode->left != nullptr) {
				if (currentNode->left->left == nullptr && currentNode->left->right == nullptr) {
					result += currentNode->left->val;
				}
				else {
					nodeStack.push(currentNode->left);
				}
			}
			if (currentNode->right != nullptr) {
				nodeStack.push(currentNode->right);
			}
		}

		return result;
	}
};
