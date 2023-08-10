#include "stdafx.h"

using namespace std;
class Offer06ReversePrint {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> result;
		while (head!=nullptr)
		{
			result.push_back(head->val);
			head = head->next;
		}

		reverse(result.begin(), result.end());
		return result;
	}
};
