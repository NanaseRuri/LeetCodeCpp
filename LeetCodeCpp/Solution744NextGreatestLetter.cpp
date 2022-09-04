#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>

class Solution744NextGreatestLetter
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int right = letters.size() - 1;
        if (target >= letters[right]) {
            return letters[0];
        }

        int left = 0;

        int middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (letters[middle] > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return letters[left];
    }
};