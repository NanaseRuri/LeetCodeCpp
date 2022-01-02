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

class Solution143ReorderList
{
public:
	void reorderList(ListNode* head) {
		if (head == nullptr) {
			return;
		}

		ListNode* middleNode = GetMiddleNode(head);
		ListNode* left = head;
		ListNode* right = middleNode->next;
		middleNode->next = nullptr;
		right = ReverseListNode(right);
		MergeListNode(left, right);
	}

	ListNode* GetMiddleNode(ListNode* head) {
		ListNode* slow = head;
		while (head->next != nullptr && head->next->next != nullptr)
		{
			head = head->next->next;
			slow = slow->next;
		}
		return slow;
	}

	ListNode* ReverseListNode(ListNode* head) {
		ListNode* preListNode = nullptr;
		while (head != nullptr)
		{
			ListNode* nextNode = head->next;
			head->next = preListNode;
			preListNode = head;
			head = nextNode;
		}
		return preListNode;
	}

	void MergeListNode(ListNode* listNode1, ListNode* listNode2) {
		ListNode* listNode1Next;
		ListNode* listNode2Next;
		while (listNode1 != nullptr && listNode2 != nullptr)
		{
			listNode1Next = listNode1->next;
			listNode2Next = listNode2->next;

			listNode1->next = listNode2;
			listNode2->next = listNode1Next;

			listNode1 = listNode1Next;
			listNode2 = listNode2Next;
		}
	}
};