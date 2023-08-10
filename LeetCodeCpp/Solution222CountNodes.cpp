#include "stdafx.h"

using namespace std;

class Solution222CountNodes
{
public:
	int countNodes1(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return countNodes1(root->left) + countNodes1(root->right) + 1;
	}

	int countNodes(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		TreeNode* node = root;
		int level = 0;
		while (node->left != nullptr)
		{
			level++;
			node = node->left;
		}

		int low = 1 << level;
		int high = (1 << (level + 1)) - 1;
		while (low < high)
		{
			int middle = (high - low + 1) / 2 + low;
			if (Exists(root, level, middle)) {
				low = middle;
			}
			else {
				high = middle - 1;
			}
		}

		return low;
	}

	bool Exists(TreeNode* root, int level, int k) {
		int bits = 1 << (level - 1);
		while (root != nullptr && bits > 0) {
			if (bits & k) {
				root = root->right;
			}
			else {
				root = root->left;
			}
			bits >>= 1;
		}
		return root != nullptr;
	}
};

//int main() {
//	Solution222CountNodes solution;
//	TreeNode* node = BuildTreeNode({ 1,2,3,4,5,6 });
//	solution.countNodes(node);
//}
