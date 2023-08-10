#include "stdafx.h"

using namespace std;

class Solution237DeleteNode
{
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* nextNode = node->next;
        node->next = nextNode->next;
        delete nextNode;
    }
};
