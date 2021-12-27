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

using namespace std;

class Solution116Connect
{
public:
	Node* connect(Node* root) {
		if (root == nullptr || root->left == nullptr) {
			return root;
		}

		Node* leftChild = root->left;
		Node* rightChild = root->right;
		while (leftChild != nullptr)
		{
			leftChild->next = rightChild;
			leftChild = leftChild->right;
			rightChild = rightChild->left;
		}

		connect(root->left);
		connect(root->right);
		return root;
	}
};

//int main() {
//	vector<int> nodeValues1{ 1,2,3,4,5,6,7 };
//	auto node1 = BuildNode(nodeValues1);
//
//	vector<int> nodeValues2{ -1,0,1,2,3,4,5,6,7,8,9,10,11,12,13};
//	auto node2 = BuildNode(nodeValues2);
//
//	Solution116Connect solution;
//	solution.connect(node1);
//	solution.connect(node2);
//}