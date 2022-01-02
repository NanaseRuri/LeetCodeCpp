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

using namespace std;

class Solution139WordBreak
{
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) {
			return nullptr;
		}

		Node* guard = new Node(0);
		Node* dump = guard;
		unordered_map<Node*, Node*> copyNodeIndexMap;

		while (head != nullptr)
		{
			Node* currentNode;
			if (copyNodeIndexMap.find(head) != copyNodeIndexMap.end()) {
				currentNode = copyNodeIndexMap[head];
			}
			else {
				currentNode = new Node(head->val);
				copyNodeIndexMap.insert({ head,currentNode });
			}

			if (head->random != nullptr) {
				Node* randomNode;
				if (copyNodeIndexMap.find(head->random) != copyNodeIndexMap.end()) {
					randomNode = copyNodeIndexMap[head->random];
				}
				else {
					randomNode = new Node(head->random->val);
					copyNodeIndexMap.insert({ head->random,randomNode });
				}
				currentNode->random = randomNode;
			}

			dump->next = currentNode;
			dump = dump->next;
			head = head->next;
		}
		return guard->next;
	}
};