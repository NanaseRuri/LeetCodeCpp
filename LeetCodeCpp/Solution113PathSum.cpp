#include "stdafx.h"

using namespace std;

class Solution113PathSum
{
private:
	void Dfs(TreeNode* root, int targetSum, vector<vector<int>>& result, vector<int>& currentResult, int currentSum) {
		if (root == nullptr) {
			return;
		}

		currentSum += root->val;
		currentResult.push_back(root->val);

		if (root->left == nullptr && root->right == nullptr) {
			if (currentSum == targetSum) {
				result.push_back(vector<int>(currentResult));
			}
		}

		Dfs(root->left, targetSum, result, currentResult, currentSum);
		Dfs(root->right, targetSum, result, currentResult, currentSum);

		currentResult.pop_back();
	}

public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return vector<vector<int>>();
		}

		vector<vector<int>> result;
		vector<int> currentResult;

		Dfs(root, targetSum, result, currentResult, 0);
		return result;
	}
};
