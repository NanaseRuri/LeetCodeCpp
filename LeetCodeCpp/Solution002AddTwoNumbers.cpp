#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* head = new ListNode(0);
		ListNode* pre = head;
		int currentValue = 0;
		int nextValue = 0;

		while (l1 != nullptr || l2 != nullptr || nextValue != 0)
		{
			currentValue = nextValue;
			if (l1 != nullptr)
			{
				currentValue += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				currentValue += l2->val;
				l2 = l2->next;
			}
			nextValue = currentValue >= 10 ? 1 : 0;
			currentValue = currentValue >= 10 ? currentValue - 10 : currentValue;
			ListNode* next = new ListNode(currentValue);
			pre->next = next;
			pre = pre->next;
		}

		return head->next;
	}
};