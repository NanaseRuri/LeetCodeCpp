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
#include "Node.h"
#include <set>

using namespace std;

class Solution144PreorderTraversal
{
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == nullptr) {
			return result;
		}

		stack<TreeNode*> rootStack{ {root} };

		while (!rootStack.empty()) {
			TreeNode* head = rootStack.top();
			rootStack.pop();
			result.push_back(head->val);
			if (head->right != nullptr) {
				rootStack.push(head->right);
			}
			if (head->left != nullptr) {
				rootStack.push(head->left);
			}
		}
		return result;
	}
};