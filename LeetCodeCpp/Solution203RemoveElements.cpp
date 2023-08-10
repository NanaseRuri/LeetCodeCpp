#include "stdafx.h"


using namespace std;

class Solution203RemoveElements
{
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* guard = new ListNode();
		ListNode* dump = guard;
		guard->next = head;


		while (dump->next!=nullptr)
		{
			if (dump->next->val == val) {
				dump->next = dump->next->next;
			}
			else {
				dump = dump->next;
			}
		}

		return guard->next;
	}
};
