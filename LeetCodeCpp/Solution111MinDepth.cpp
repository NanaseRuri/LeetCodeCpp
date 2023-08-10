#include "stdafx.h"

using namespace std;

class Solution111IsBalanced
{
private:
	int _minDepth = INT32_MAX;

	void Dfs(TreeNode* root, int currentDepth) {
		if (_minDepth < currentDepth || root == nullptr) {
			return;
		}

		++currentDepth;
		if (root->left == nullptr && root->right == nullptr) {
			_minDepth = min(currentDepth, _minDepth);
		}
		else {
			Dfs(root->left, currentDepth);
			Dfs(root->right, currentDepth);
		}
	}

public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		Dfs(root, 0);
		return _minDepth;
	}
};
