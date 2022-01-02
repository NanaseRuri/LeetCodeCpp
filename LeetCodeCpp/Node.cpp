#include "Node.h"
Node::Node() : val(0), left(nullptr), right(nullptr), next(nullptr),random(nullptr) {}

Node::Node(int val) : val(val), left(nullptr), right(nullptr), next(nullptr), random(nullptr) {}

Node::Node(int val, Node* left, Node* right, Node* next) : val(val), left(left), right(right), next(next), random(nullptr) {}

Node::Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors), random(nullptr) {}

Node* BuildNode(vector<int> nodeValues) {
	queue<Node*> nodes;
	Node* firstNode = new Node(nodeValues[0]);
	nodes.push(firstNode);

	int nodesSize = nodeValues.size();
	Node* currentNode = nodes.front();
	nodes.pop();

	for (int i = 1; i < nodesSize; i++)
	{
		if (i % 2 == 1) {
			if (nodeValues[i] != INT32_MAX) {
				Node* leftChild = new Node(nodeValues[i]);
				currentNode->left = leftChild;
				nodes.push(leftChild);
			}
		}
		else {
			if (nodeValues[i] != INT32_MAX) {
				Node* rightChild = new Node(nodeValues[i]);
				currentNode->right = rightChild;
				nodes.push(rightChild);
			}
			currentNode = nodes.front();
			nodes.pop();
		}
	}

	return firstNode;
}