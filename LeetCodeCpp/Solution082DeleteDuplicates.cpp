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

using namespace std;

class Solution082DeleteDuplicates
{
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}

		ListNode* dump = new ListNode();
		ListNode* guard = dump;
		int lastValue = head->val;
		bool repeated = false;
		ListNode* nextNode = head->next;
		while (nextNode != nullptr)
		{
			if (lastValue == nextNode->val) {
				repeated = true;
			}
			else {
				if (!repeated) {
					guard->next = head;
					guard = guard->next;
				}
				lastValue = nextNode->val;
				repeated = false;
			}

			nextNode = nextNode->next;
			head = head->next;
		}

		if (!repeated) {
			guard->next = head;
			guard->next->next = nullptr;
		}
		else {
			guard->next = nullptr;
		}
		return dump->next;
	}
};

//int main() {
//	ListNode* listNode = GetListNode({ 1,2,2 });
//	Solution082DeleteDuplicates solution;
//	solution.deleteDuplicates(listNode);
//}