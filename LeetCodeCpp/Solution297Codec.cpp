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
#include <list>

using namespace std;

class Solution297Codec
{
public:
	void Serialize(TreeNode* root, string& result) {
		if (root == nullptr) {
			result += "NULL,";
		}
		else {
			result += to_string(root->val) + ",";
			Serialize(root->left, result);
			Serialize(root->right, result);
		}
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string result;
		Serialize(root, result);
		return result;
	}

	TreeNode* Deserialize(list<string>& dataList) {
		if (dataList.front() == "NULL") {
			dataList.erase(dataList.begin());
			return nullptr;
		}

		TreeNode* root = new TreeNode(stoi(dataList.front()));
		dataList.pop_front();
		root->left = Deserialize(dataList);
		root->right = Deserialize(dataList);
		return root;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		list<string> dataList;
		string str;
		for (auto& ch : data)
		{
			if (ch == ',') {
				dataList.push_back(str);
				str.clear();
			}
			else {
				str.push_back(ch);
			}
		}
		if (!str.empty()) {
			dataList.push_back(str);
		}
		return Deserialize(dataList);
	}
};

//int main() {
//	Solution297Codec solution;	
//
//	solution.deserialize("1,2,NULL,NULL,3");
//}