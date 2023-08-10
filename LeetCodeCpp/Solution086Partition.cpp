#include "stdafx.h"

using namespace std;

class Solution086Partition
{
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* guard = new ListNode();
		guard->next = head;

		ListNode* nodeBeforeInsertedHead = guard;
		ListNode* insertedHead = head;
		while (head != nullptr && head->val < x)
		{			
			head = head->next;
			nodeBeforeInsertedHead = insertedHead;
			insertedHead = insertedHead->next;
		}

		ListNode* nodeAfterInsertedNode = insertedHead;
		while (head != nullptr)
		{
			if (head->val < x) {
				ListNode* temp = head;
				head = head->next;
				nodeAfterInsertedNode->next = head;
				nodeBeforeInsertedHead->next = temp;
				temp->next = insertedHead;
				nodeBeforeInsertedHead = temp;
			}
			else {
				nodeAfterInsertedNode = head;
				head = head->next;
			}
		}

		return guard->next;
	}
};

//int main() {
//	auto listNode1 = GetListNode({ 1,4,3,2,5,2 });
//	auto listNode2 = GetListNode({ 2,1 });
//	auto listNode3 = GetListNode({ 1,4,3,0,2,5,2 });
//
//	Solution086Partition solution;
//	solution.partition(listNode1, 3);
//	solution.partition(listNode2, 2);
//	solution.partition(listNode3, 3);
//}
