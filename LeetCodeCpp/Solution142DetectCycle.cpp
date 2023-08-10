#include "stdafx.h"

using namespace std;

class Solution142DetectCycle
{
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				while (head != slow)
				{
					head = head->next;
					slow = slow->next;
				}
				return head;
			}
		}

		return nullptr;
	}
};
