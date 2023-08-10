#include "stdafx.h"


using namespace std;

class Solution206ReverseList
{
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* preListNode = nullptr;
		while (head != nullptr)
		{
			ListNode* next = head->next;
			head->next = preListNode;
			preListNode = head;
			head = next;
		}
		return preListNode;
	}
};
