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

class Solution114Flatten
{
public:
	void flatten(TreeNode* root) {
		TreeNode* guard = root;

		while (guard != nullptr)
		{
			if (guard->left != nullptr) {
				TreeNode* leftChildren = guard->left;
				while (leftChildren->right != nullptr)
				{
					leftChildren = leftChildren->right;
				}
				leftChildren->right = guard->right;
				guard->right = guard->left;
				guard->left = nullptr;
			}

			guard = guard->right;
		}
	}
};