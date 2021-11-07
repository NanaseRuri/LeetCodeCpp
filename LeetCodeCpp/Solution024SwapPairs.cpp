#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

namespace Solution024 {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class Solution024SwapPairs {
	public:
		ListNode* swapPairs(ListNode* head) {
			if (head == nullptr || head->next == nullptr) {
				return head;
			}

			ListNode* guard = new ListNode();
			ListNode* dump = guard;
			guard->next = head;
			while (head != nullptr && head->next != nullptr)
			{
				ListNode* nextNext = head->next->next;
				dump->next = head->next;
				head->next->next = head;
				head->next = nextNext;
				dump = head;
				head = nextNext;
			}

			return guard->next;
		}
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

using namespace Solution024;
//int main() {
//	ListNode* node1 = GetListNode({ 1,2,3,4 });
//
//	Solution024SwapPairs solution;
//	auto result = solution.swapPairs(node1);
//
//	while (result != nullptr)
//	{
//		cout << result->val << '\t';
//		result = result->next;
//	}
//}