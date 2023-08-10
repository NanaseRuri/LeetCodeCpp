#include "stdafx.h"

using namespace std;

ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode* next) : val(x), next(next) {}

ListNode* BuildListNode(vector<int>values) {
	ListNode* head = new ListNode(values[0]);
	ListNode* dump = head;
	for (int i = 1; i < values.size(); i++)
	{
		ListNode* temp = new ListNode(values[i]);
		dump->next = temp;
		dump = dump->next;
	}
	return head;
}
