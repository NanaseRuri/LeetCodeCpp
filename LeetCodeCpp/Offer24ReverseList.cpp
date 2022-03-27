#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include "ListNode.h"

using namespace std;
class Offer24ReverseList {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = nullptr;
        while (head != nullptr)
        {
            ListNode* nextListNode = head->next;
            head->next = preNode;
            preNode = head;
            head = nextListNode;
        }

        return preNode;
    }
};