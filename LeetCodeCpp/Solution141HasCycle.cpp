#include "stdafx.h"

using namespace std;

class Solution141HasCycle
{
public:
	bool hasCycle(ListNode* head) {
		ListNode* slowHead = head;

		while (head != nullptr && head->next != nullptr)
		{
			head = head->next->next;
			slowHead = slowHead->next;
			if (head == slowHead) {
				return true;
			}
		}

		return false;
	}
};
