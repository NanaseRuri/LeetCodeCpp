#include "stdafx.h"

using namespace std;

class Solution019RemoveNthFromEnd {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dump = head;
		ListNode* guard = new ListNode();
		guard->next = head;
		ListNode* result = guard;

		for (int i = 0; i < n - 1; i++)
		{
			dump = dump->next;
		}

		while (dump->next != nullptr)
		{
			dump = dump->next;
			guard = guard->next;
		}

		guard->next = guard->next->next;
		return result->next;
	}
};
