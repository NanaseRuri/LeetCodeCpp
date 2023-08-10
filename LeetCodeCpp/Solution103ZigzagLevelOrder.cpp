#include "stdafx.h"

using namespace std;

class Solution103ZigzagLevelOrder
{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr) {
			return result;
		}

		vector<int> currentResult;
		bool leftToRight = true;
		stack<TreeNode*> parent;
		stack<TreeNode*> children;
		parent.push(root);
		TreeNode* parentTreeNode;

		while (!parent.empty() || !children.empty())
		{
			parentTreeNode = parent.top();
			parent.pop();
			currentResult.push_back(parentTreeNode->val);

			if (leftToRight)
			{
				if (parentTreeNode->left != nullptr) {
					children.push(parentTreeNode->left);
				}
				if (parentTreeNode->right != nullptr) {
					children.push(parentTreeNode->right);
				}
			}
			else {
				if (parentTreeNode->right != nullptr) {
					children.push(parentTreeNode->right);
				}
				if (parentTreeNode->left != nullptr) {
					children.push(parentTreeNode->left);
				}
			}

			if (parent.empty()) {
				swap(parent, children);
				result.push_back(vector<int>(currentResult));
				currentResult.clear();
				leftToRight = !leftToRight;
			}
		}
		return result;
	}
};

//int main() {
//	auto treeNode = BuildTreeNode({ 3,9,20,4,5,15,7 });
//
//	Solution103ZigzagLevelOrder solution;
//	solution.zigzagLevelOrder(treeNode);
//}
