#include "stdafx.h"

using namespace std;

class Solution092ReverseBetween
{
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (left == right) {
			return head;
		}

		ListNode* guard = new ListNode(0, head);

		ListNode* dump = guard;
		for (int i = 1; i < left; i++)
		{
			dump = dump->next;
		}

		ListNode* reverseEnd = dump->next;
		ListNode* nextNode;
		while (left < right)
		{
			nextNode = reverseEnd->next;
			reverseEnd->next = reverseEnd->next->next;

			nextNode->next = dump->next;
			dump->next = nextNode;

			left++;
		}

		return guard->next;
	}
};

//int main() {
//	auto listNode = GetListNode({ 1,2,3,4,5 });
//
//	Solution092ReverseBetween solution;
//	solution.reverseBetween(listNode, 2, 4);
//
//	listNode = GetListNode({ 1,2,3,4,5 });
//	solution.reverseBetween(listNode, 1, 5);
//
//	listNode = GetListNode({ 1,2,3,4,5 });
//	solution.reverseBetween(listNode, 1, 1);
//
//	listNode = GetListNode({ 1,2,3,4,5 });
//	solution.reverseBetween(listNode, 3, 5);
//}
