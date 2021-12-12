#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include "ListNode.h"

using namespace std;

class Solution024SwapPairs {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}

		ListNode* guard = new ListNode();
		ListNode* dump = guard;
		guard->next = head;
		while (head != nullptr && head->next != nullptr)
		{
			ListNode* nextNext = head->next->next;
			dump->next = head->next;
			head->next->next = head;
			head->next = nextNext;
			dump = head;
			head = nextNext;
		}

		return guard->next;
	}
};

//int main() {
//	ListNode* node1 = GetListNode({ 1,2,3,4 });
//
//	Solution024SwapPairs solution;
//	auto result = solution.swapPairs(node1);
//
//	while (result != nullptr)
//	{
//		cout << result->val << '\t';
//		result = result->next;
//	}
//}