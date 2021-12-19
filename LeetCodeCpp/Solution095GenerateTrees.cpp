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

class Solution095GenerateTrees
{
private:
	vector<TreeNode*> GetTreeNodes(int start, int end) {
		if (start > end) {
			return vector<TreeNode*>{nullptr};
		}

		vector<TreeNode*> result;
		for (int i = start; i <= end; i++)
		{
			vector<TreeNode*> left = GetTreeNodes(start, i - 1);
			vector<TreeNode*> right = GetTreeNodes(i + 1, end);

			for (auto leftChild : left)
			{
				for (auto rightChild : right)
				{
					TreeNode* oneResult = new TreeNode(i);
					oneResult->left = leftChild;
					oneResult->right = rightChild;
					result.push_back(oneResult);
				}
			}
		}
		return result;
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		return GetTreeNodes(1, n);
	}
};

//int main() {
//
//}