#include "stdafx.h"

using namespace std;

class Solution083DeleteDuplicates
{
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}

		ListNode* guard = new ListNode(0, head);
		ListNode* dump = guard->next;
		head = head->next;

		while (head != nullptr)
		{
			if (head->val != dump->val) {
				dump->next = head;
				dump = dump->next;
			}
			head = head->next;
		}
		dump->next = nullptr;

		return guard->next;
	}
};
