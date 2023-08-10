#include "stdafx.h"

using namespace std;

class Solution104MaxDepth
{
private :
	int Dfs(TreeNode* parent, int currentValue) {
		if (parent == nullptr) {
			return currentValue;
		}

		return max(Dfs(parent->left, currentValue + 1), Dfs(parent->right, currentValue + 1));
	}

public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		return Dfs(root, 0);
	}
};
