#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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