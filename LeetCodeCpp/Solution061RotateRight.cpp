#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

namespace Solution061 {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* GetListNode(vector<int>values) {
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
}

using namespace Solution061;
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