#include "stdafx.h"

using namespace std;

class Solution1026MaxAncestorDiff
{
public:
	int _result;

	void Dfs(TreeNode* currentNode, int currentMax, int currentMin) {
		if (currentMax < currentNode->val) {
			currentMax = currentNode->val;
			_result = max(_result, abs(currentMax - currentMin));
		}
		else if (currentMin > currentNode->val) {
			currentMin = currentNode->val;
			_result = max(_result, abs(currentMax - currentMin));
		}

		if (currentNode->left != nullptr) {
			Dfs(currentNode->left, currentMax, currentMin);
		}
		if (currentNode->right != nullptr) {
			Dfs(currentNode->right, currentMax, currentMin);
		}
	}

	int maxAncestorDiff(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		Dfs(root, root->val, root->val);
		return _result;
	}
};
