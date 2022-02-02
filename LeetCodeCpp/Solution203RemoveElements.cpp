#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>


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
