#include "stdafx.h"

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