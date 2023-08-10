#include "stdafx.h"

using namespace std;
class Solution160GetIntersectionNode {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* listNode1 = headA;
		ListNode* listNode2 = headB;

		while (listNode1 != listNode2)
		{
			listNode1 = listNode1 == nullptr ? headB : listNode1->next;
			listNode2 = listNode2 == nullptr ? headA : listNode2->next;
		}

		return listNode1;
	}
};
