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
class Solution160GetIntersectionNode {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* listNode1 = headA;
		ListNode* listNode2 = headB;

		while (listNode1 != listNode2)
		{
			listNode1 = listNode1 == nullptr ? headB : listNode1->next;
			listNode2 = listNode2 == nullptr ? headA : listNode2->next;
		}

		return listNode1;
	}
};