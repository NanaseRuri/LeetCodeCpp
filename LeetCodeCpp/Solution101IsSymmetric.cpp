#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"

using namespace std;

class Solution101IsSymmetric
{
private:
	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) {
			return true;
		}

		if (left == nullptr || right == nullptr) {
			return false;
		}

		if (left->val == right->val) {
			return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
		}
		else {
			return false;
		}
	}


public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}

		return isSymmetric(root->left, root->right);
	}
};
