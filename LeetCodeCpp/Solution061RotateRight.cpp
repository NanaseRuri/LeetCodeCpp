#include "stdafx.h"

using namespace std;


class Solution060GetPermutation {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* temp = head;
		int nodeCount = 0;
		while (temp != nullptr) {
			nodeCount++;
			temp = temp->next;
		}
		if (nodeCount <= 1) {
			return head;
		}

		k %= nodeCount;
		if (k == 0) {
			return head;
		}

		ListNode* dump = new ListNode(0, head);
		ListNode* guard = dump;

		for (int i = 0; i < nodeCount - k; i++)
		{
			dump = dump->next;
		}
		ListNode* afterHead = dump->next;
		dump->next = nullptr;
		guard->next = afterHead;
		while (afterHead->next != nullptr) {
			afterHead = afterHead->next;
		}
		afterHead->next = head;

		return guard->next;
	}
};


//int main() {
//	vector<int> nums{ 1,2,3,4,5 };
//	auto listNode = GetListNode(nums);
//	vector<int> nums1{ 0,1,2 };
//	auto listNode1 = GetListNode(nums1);
//	auto listNode2 = GetListNode(nums1);
//
//	Solution060GetPermutation solution;
//	auto result = solution.rotateRight(listNode, 2);
//	result =solution.rotateRight(listNode1, 4);
//	result =solution.rotateRight(listNode2, 3);
//}
