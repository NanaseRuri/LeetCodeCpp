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

class Solution147InsertionSortList
{
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* newHead = new ListNode(INT32_MIN);
		ListNode* dump = newHead;
		dump->next = head;

		while (head != nullptr)
		{
			if (head->val < dump->val) {
				ListNode* temp = newHead;
				ListNode* nextHead = head->next;
				while (temp != nullptr) {
					if (head->val < temp->next->val) {
						dump->next = nextHead;
						head->next = temp->next;
						temp->next = head;
						break;
					}
					temp = temp->next;
				}
				head = nextHead;
			}
			else {
				head = head->next;
				dump = dump->next;
			}
		}
		return newHead->next;
	}
};

//int main() {
//	vector<int> listNodeValues{ 4,2,1,3 };
//	auto listNode = BuildListNode(listNodeValues);
//	Solution147insertionSortList solution;
//	solution.insertionSortList(listNode);
//}