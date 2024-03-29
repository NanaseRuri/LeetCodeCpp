#include "stdafx.h"

using namespace std;

class Solution148SortList
{
	//private:
	//	ListNode* MergeListNode(ListNode* listNode1, ListNode* listNode2) {
	//		ListNode* guard = new ListNode();
	//		ListNode* dump = guard;
	//		while (listNode1 != nullptr && listNode2 != nullptr)
	//		{
	//			if (listNode1->val > listNode2->val) {
	//				dump->next = listNode2;
	//				listNode2 = listNode2->next;				
	//			}
	//			else {
	//				dump->next = listNode1;
	//				listNode1 = listNode1->next;
	//			}
	//			dump = dump->next;
	//		}
	//
	//		if (listNode1 != nullptr) {
	//			dump->next = listNode1;
	//		}
	//		else if (listNode2 != nullptr) {
	//			dump->next = listNode2;
	//		}
	//
	//		return guard->next;
	//	}
	//
	//public:
	//	ListNode* sortList(ListNode* head) {
	//		if (head == nullptr) {
	//			return nullptr;
	//		}
	//
	//		int length = 0;
	//		ListNode* headTemp = head;
	//		while (headTemp != nullptr)
	//		{
	//			length++;
	//			headTemp = headTemp->next;
	//		}
	//
	//		ListNode* guard = new ListNode(0, head);
	//		for (int subLength = 1; subLength < length; subLength <<= 1)
	//		{
	//			ListNode* pre = guard;
	//			ListNode* current = guard->next;
	//			while (current != nullptr)
	//			{
	//				ListNode* head1 = current;
	//				for (int i = 1; i < subLength && current->next != nullptr; i++)
	//				{
	//					current = current->next;
	//				}
	//				ListNode* head2 = current->next;
	//				current->next = nullptr;
	//				current = head2;
	//				for (int i = 1; i < subLength && current != nullptr && current->next != nullptr; i++)
	//				{
	//					current = current->next;
	//				}
	//				ListNode* next = nullptr;
	//				if (current != nullptr) {
	//					next = current->next;
	//					current->next = nullptr;
	//				}
	//				ListNode* merged = MergeListNode(head1, head2);
	//				pre->next = merged;
	//				while (pre->next != nullptr)
	//				{
	//					pre = pre->next;
	//				}
	//				current = next;
	//			}
	//		}
	//		return guard->next;
	//	}


public:
	//ListNode* sortList(ListNode* head) {
	//	return SortList(head, nullptr);
	//}

	//ListNode* SortList(ListNode* head, ListNode* tail) {
	//	if (head == nullptr) {
	//		return nullptr;
	//	}
	//	if (head->next == tail) {
	//		head->next = nullptr;
	//		return head;
	//	}

	//	ListNode* middleNode = GetMiddleNode(head, tail);
	//	ListNode* left = SortList(head, middleNode);
	//	ListNode* right = SortList(middleNode, tail);
	//	return MergeListNode(left, right);
	//}

	//ListNode* GetMiddleNode(ListNode* head, ListNode* tail) {
	//	ListNode* slow = head;
	//	while (head != tail && head->next != tail)
	//	{
	//		head = head->next->next;
	//		slow = slow->next;
	//	}
	//	return slow;
	//}

	//ListNode* MergeListNode(ListNode* listNode1, ListNode* listNode2) {
	//	ListNode* guard = new ListNode();
	//	ListNode* dump = guard;

	//	while (listNode1 != nullptr && listNode2 != nullptr)
	//	{
	//		if (listNode1->val > listNode2->val) {
	//			dump->next = listNode2;
	//			listNode2 = listNode2->next;
	//		}
	//		else {
	//			dump->next = listNode1;
	//			listNode1 = listNode1->next;
	//		}
	//		dump = dump->next;
	//	}
	//	if (listNode1 != nullptr) {
	//		dump->next = listNode1;
	//	}
	//	else if (listNode2 != nullptr) {
	//		dump->next = listNode2;
	//	}
	//	return guard->next;
	//}


	ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}

	ListNode* sortList(ListNode* head, ListNode* tail) {
		if (head == tail) {
			return nullptr;
		}
		if (head->next == tail) {
			head->next = nullptr;
			return head;
		}

		ListNode* middleNode = GetMiddleNode(head, tail);
		ListNode* newHead = sortList(head, middleNode);
		ListNode* newTail = sortList(middleNode, tail);
		return MergeListNode(newHead, newTail);
	}

	ListNode* GetMiddleNode(ListNode* head, ListNode* tail) {
		ListNode* slow = head;
		while (head != tail && head->next != tail)
		{
			head = head->next->next;
			slow = slow->next;
		}
		return slow;
	}

	ListNode* MergeListNode(ListNode* list1, ListNode* list2) {
		ListNode* guard = new ListNode();
		ListNode* dump = guard;
		while (list1 != nullptr && list2 != nullptr)
		{
			if (list1->val <= list2->val) {
				dump->next = list1;
				dump = dump->next;
				list1 = list1->next;
			}
			else {
				dump->next = list2;
				dump = dump->next;
				list2 = list2->next;
			}
		}

		if (list1 != nullptr) {
			dump->next = list1;
		}
		else if (list2 != nullptr) {
			dump->next = list2;
		}

		return guard->next;
	}
};

//int main() {
//	auto listNode = BuildListNode({ 4,2,1,3 });
//	Solution148SortList solution;
//	solution.sortList(listNode);
//}
