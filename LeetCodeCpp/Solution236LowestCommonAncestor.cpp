#include "stdafx.h"

using namespace std;

class Solution236LowestCommonAncestor
{
private:
	TreeNode* Dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) {
			return nullptr;
		}
		else {
			if (root == p || root == q) {
				return root;
			}
			TreeNode* leftContain = Dfs(root->left, p, q);
			TreeNode* rightContain = Dfs(root->right, p, q);
			if (leftContain != nullptr && rightContain != nullptr) {
				return root;
			}
			return leftContain != nullptr ? leftContain : rightContain;
		}
	}

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return Dfs(root, p, q);
	}
};
