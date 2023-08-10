#include "stdafx.h"

using namespace std;

class Solution102LevelOrder
{
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr) {
			return result;
		}

		queue<TreeNode*> parent;
		queue<TreeNode*> children;
		parent.push(root);
		vector<int> currentResult;

		TreeNode* parentTreeNode;
		while (!parent.empty() || !children.empty()) {
			parentTreeNode = parent.front();
			parent.pop();
			currentResult.push_back(parentTreeNode->val);

			if (parentTreeNode->left != nullptr) {
				children.push(parentTreeNode->left);
			}
			if (parentTreeNode->right != nullptr) {
				children.push(parentTreeNode->right);
			}

			if (parent.empty()) {
				swap(parent, children);
				result.push_back(vector<int>(currentResult));
				currentResult.clear();
			}
		}

		return result;
	}
};
