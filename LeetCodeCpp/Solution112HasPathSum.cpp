#include "stdafx.h"

using namespace std;

class Solution112HasPathSum
{
public:
	bool hasPathSum1(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return false;
		}

		if (root->left == nullptr && root->right == nullptr) {
			return targetSum == root->val;
		}

		return hasPathSum1(root->left, targetSum - root->val) || hasPathSum1(root->right, targetSum - root->val);
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return false;
		}

		queue<TreeNode*> treeNodeQueue;
		queue<int> currentSumQueue;
		treeNodeQueue.push(root);
		currentSumQueue.push(root->val);

		while (!treeNodeQueue.empty()) {
			TreeNode* parent = treeNodeQueue.front();
			int currentSum = currentSumQueue.front();

			treeNodeQueue.pop();
			currentSumQueue.pop();

			if (parent->left == nullptr && parent->right == nullptr) {
				if (currentSum == targetSum) {
					return true;
				}
				continue;
			}

			if (parent->left != nullptr) {
				treeNodeQueue.push(parent->left);
				currentSumQueue.push(parent->left->val + currentSum);
			}
			if (parent->right != nullptr) {
				treeNodeQueue.push(parent->right);
				currentSumQueue.push(parent->right->val + currentSum);
			}
		}

		return false;
	}
};
