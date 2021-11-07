#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution021MergeTwoLists {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* guard = new ListNode();
		ListNode* dump = guard;
		while (l1 != nullptr || l2 != nullptr) {
			if (l1 != nullptr && l2 != nullptr) {
				if (l1->val > l2->val) {
					dump->next = l2;
					dump = dump->next;
					l2 = l2->next;
				}
				else {
					dump->next = l1;
					dump = dump->next;
					l1 = l1->next;
				}
			}
			else if (l1 == nullptr && l2 != nullptr) {
				dump->next = l2;
				dump = dump->next;
				l2 = l2->next;
			}
			else {
				dump->next = l1;
				dump = dump->next;
				l1 = l1->next;
			}
		}
		return guard->next;
	}
};