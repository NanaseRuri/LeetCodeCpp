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

class Solution404SumOfLeftLeaves {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		int result = 0;
		stack<TreeNode*> nodeStack{ {root} };

		while (!nodeStack.empty())
		{
			TreeNode* currentNode = nodeStack.top();
			nodeStack.pop();

			if (currentNode->left != nullptr) {
				if (currentNode->left->left == nullptr && currentNode->left->right == nullptr) {
					result += currentNode->left->val;
				}
				else {
					nodeStack.push(currentNode->left);
				}
			}
			if (currentNode->right != nullptr) {
				nodeStack.push(currentNode->right);
			}
		}

		return result;
	}
};