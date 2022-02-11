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

class Solution234IsPalindrome
{
public:
	bool isPalindrome(ListNode* head) {
		vector<ListNode*> nodeList;
		while (head != nullptr)
		{
			nodeList.push_back(head);
			head = head->next;
		}

		int left = 0;
		int right = nodeList.size() - 1;
		while (left < right)
		{
			if (nodeList[left]->val != nodeList[right]->val) {
				return false;
			}
			++left;
			--right;
		}
		return true;
	}

	bool isPalindrome1(ListNode* head) {
		if (head == nullptr) {
			return true;
		}

		ListNode* middleNode = GetMiddleListNode(head);
		ListNode* reverseMiddleNode = ReverseListNode(middleNode->next);
		ListNode* dump = reverseMiddleNode;
		bool valid = true;
		while (valid && reverseMiddleNode != nullptr)
		{
			if (head->val != reverseMiddleNode->val) {
				valid = false;
			}
			head = head->next;
			reverseMiddleNode = reverseMiddleNode->next;
		}
		ReverseListNode(dump);

		return valid;
	}

	ListNode* GetMiddleListNode(ListNode* node) {
		ListNode* slow = node;
		ListNode* fast = node;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;
	}

	ListNode* ReverseListNode(ListNode* node) {
		ListNode* preNode = nullptr;
		while (node != nullptr)
		{
			ListNode* nextNode = node->next;
			node->next = preNode;
			preNode = node;
			node = nextNode;
		}
		return preNode;
	}
};