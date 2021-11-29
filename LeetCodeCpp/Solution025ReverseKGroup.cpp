#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

namespace Solution025 {
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

	class Solution025ReverseKGroup {
	private:
		bool CanExchangeNextTime(ListNode* head, int nextNodeCount) {
			for (int i = 0; i < nextNodeCount; i++)
			{
				if (head->next == nullptr) {
					return false;
				}
				head = head->next;
			}
			return true;
		}
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			if (head == nullptr || k <= 1) {
				return head;
			}

			ListNode* guard = new ListNode();
			ListNode* preHead = guard;
			guard->next = head;
			while (head != nullptr)
			{
				if (!CanExchangeNextTime(head, k - 1)) {
					break;
				}
				else {
					for (int i = 0; i < k - 1; i++)
					{
						auto nextNext = head->next->next;
						head->next->next = preHead->next;
						preHead->next = head->next;
						head->next = nextNext;
					}
					preHead = head;
					head = preHead->next;
				}
			}

			return guard->next;
		}
	};
}

using namespace Solution025;
//int main() {
//	ListNode* node1 = GetListNode({ 1,2,3,4 ,5 });
//	ListNode* node2 = GetListNode({ 1,2,3,4 ,5 });
//
//	Solution025ReverseKGroup solution;
//	auto result = solution.reverseKGroup(node1, 2);
//	auto result1 = solution.reverseKGroup(node2, 3);
//
//	while (result != nullptr)
//	{
//		cout << result->val << '\t';
//		result = result->next;
//	}
//
//	cout << endl;
//	while (result1 != nullptr)
//	{
//		cout << result1->val << '\t';
//		result1 = result1->next;
//	}
//}