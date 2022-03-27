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

class Solution876MiddleNode
{
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* fastListNode = head;
		while (fastListNode != nullptr && fastListNode->next != nullptr)
		{
			fastListNode = fastListNode->next->next;
			head = head->next;
		}

		return head;
	}
};