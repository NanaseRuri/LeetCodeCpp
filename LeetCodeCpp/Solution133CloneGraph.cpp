#include "stdafx.h"

using namespace std;

class Solution133CloneGraph
{
public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr) {
			return nullptr;
		}

		int headValue = node->val;
		unordered_map<int, Node*> addedNode
		{
			{headValue,new Node(node->val)}
		};

		queue<Node*> nodeQueue{ {node} };

		while (!nodeQueue.empty()) {
			Node* currentNode = nodeQueue.front();
			int currentNodeValue = currentNode->val;
			nodeQueue.pop();
			for (auto neighbor : currentNode->neighbors)
			{
				if (addedNode.find(neighbor->val) == addedNode.end()) {
					Node* neightborNode = new Node(neighbor->val);
					nodeQueue.push(neighbor);
					addedNode.insert({ neighbor->val, neightborNode });
				}
				addedNode[currentNodeValue]->neighbors.push_back(addedNode[neighbor->val]);
			}
		}

		return addedNode[headValue];
	}
};
