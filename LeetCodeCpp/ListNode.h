#pragma once
#include "stdafx.h"
using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode();
	ListNode(int x);
	ListNode(int x, ListNode* next);
};

ListNode* BuildListNode(vector<int>values);