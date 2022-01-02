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