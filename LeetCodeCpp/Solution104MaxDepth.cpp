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
