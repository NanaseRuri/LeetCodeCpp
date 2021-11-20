#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution637AverageOfLevels {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		if (root == nullptr) {
			return vector<double>();
		}

		vector<double> result;
		stack<TreeNode*> stack1;
		stack<TreeNode*> stack2;
		stack1.push(root);
		while (!stack1.empty())
		{
			double currentSum = 0;
			double currentCount = 0;
			while (!stack1.empty())
			{
				TreeNode* treeNode = stack1.top();
				stack1.pop();
				currentSum += treeNode->val;
				++currentCount;

				if (treeNode->left != nullptr) {
					stack2.push(treeNode->left);
				}
				if (treeNode->right != nullptr) {
					stack2.push(treeNode->right);
				}
			}

			result.push_back((double)currentSum / currentCount);
			auto temp = stack2;
			stack2 = stack1;
			stack1 = temp;
		}
		return result;
	}
};