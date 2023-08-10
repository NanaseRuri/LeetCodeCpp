#include "stdafx.h"

using namespace std;
class Offer35CopyRandomList {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) {
			return nullptr;
		}

		Node* headDump = head;

		while (headDump != nullptr) {
			Node* nextNode = headDump->next;
			Node* copyNode = new Node(headDump->val);
			headDump->next = copyNode;
			copyNode->next = nextNode;
			headDump = nextNode;
		}


		headDump = head;
		while (headDump != nullptr)
		{			
			if (headDump->random != nullptr) {
				headDump->next->random = headDump->random->next;
			}

			headDump = headDump->next->next;
		}

		Node* copyHead = head->next;
		while (head != nullptr) {
			Node* nextNode = head->next->next;

			if (nextNode != nullptr) {
				head->next->next = nextNode->next;
			}
			head->next = nextNode;

			head = nextNode;
		}

		return copyHead;
	}
};

//int main() {
//	Offer35CopyRandomList offer;
//
//	Node* node1 = new Node(7);
//	Node* node2 = new Node(13);
//	Node* node3 = new Node(11);
//	Node* node4 = new Node(10);
//	Node* node5 = new Node(1);
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//
//	node2->random = node1;
//	node3->random = node5;
//	node4->random = node3;
//	node5->random = node1;
//
//	offer.copyRandomList(node1);
//}
