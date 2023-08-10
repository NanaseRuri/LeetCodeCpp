#include "stdafx.h"

using namespace std;

class Solution117Connect
{
public:
	Node* connect(Node* root) {
		Node* head = root;
		Node* nextHead = nullptr;
		Node* dump = nullptr;
		while (head != nullptr)
		{
			if (head->left != nullptr) {
				if (dump == nullptr) {
					nextHead = head->left;
					dump = nextHead;
				}
				else {
					nextHead->next = head->left;
					nextHead = nextHead->next;
				}
			}
			if (head->right != nullptr) {
				if (dump == nullptr) {
					nextHead = head->right;
					dump = nextHead;
				}
				else {
					nextHead->next = head->right;
					nextHead = nextHead->next;
				}
			}
			head = head->next;

			if (head == nullptr) {
				head = dump;
				dump = nullptr;
			}
		}

		return root;
	}
};
