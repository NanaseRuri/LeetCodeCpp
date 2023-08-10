#include "stdafx.h"

using namespace std;

class Solution129SumNumbers
{
public:
	int sumNumbers(TreeNode* root) {
		queue<int> parentValues{ {root->val} };
		queue<TreeNode*> parentNodeQueue{ {root} };

		int sum = 0;
		while (!parentNodeQueue.empty())
		{
			int lastTreeValue = parentValues.front();
			TreeNode* parentNode = parentNodeQueue.front();
			parentValues.pop();
			parentNodeQueue.pop();
			if (parentNode->left == nullptr && parentNode->right == nullptr) {
				sum += lastTreeValue;
				continue;
			}

			if (parentNode->left != nullptr) {
				parentValues.push(lastTreeValue * 10 + parentNode->left->val);
				parentNodeQueue.push(parentNode->left);
			}
			if (parentNode->right != nullptr) {
				parentValues.push(lastTreeValue * 10 + parentNode->right->val);
				parentNodeQueue.push(parentNode->right);
			}
		}

		return sum;
	}
};
