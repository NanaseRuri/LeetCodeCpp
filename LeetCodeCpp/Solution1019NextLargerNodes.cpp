#include "stdafx.h"

using namespace std;

class Solution1019NextLargerNodes
{
public:
	vector<int> nextLargerNodes(ListNode* head) {
		stack<pair<int, int>> s;
		vector<int> result;

		int currentIndex = 0;
		while (head != nullptr) {
			result.push_back(0);
			while (!s.empty() && head->val > s.top().first) {
				result[s.top().second] = head->val;
				s.pop();
			}
			s.push({ head->val,currentIndex });
			currentIndex++;
			head = head->next;
		}

		return result;
	}
};
