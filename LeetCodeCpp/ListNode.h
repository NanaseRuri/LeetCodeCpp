class ListNode {
public:
	int val;
	ListNode* next;
	ListNode();
	ListNode(int x);
	ListNode(int x, ListNode* next);
};

#include <vector>
using namespace std;
ListNode* GetListNode(vector<int>values);