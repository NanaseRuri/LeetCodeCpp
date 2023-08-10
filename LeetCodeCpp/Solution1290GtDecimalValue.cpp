#include "stdafx.h"

using namespace std;

class Solution1290GtDecimalValue
{
public:
	int getDecimalValue(ListNode* head) {
		int result = 0;
		while (head != nullptr)
		{
			result <<= 1;
			result += head->val;
			head = head->next;
		}
		return result;
	}
};
