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

class Solution709ToLowerCase
{
public:
    string toLowerCase(string s) {
        string result;
        int sLength = s.length();
        result.resize(sLength);

        for (int i = 0; i < sLength; i++)
        {
            char c = s[i];
            if (c >= 'A' && c <= 'Z') {
                c += 'a' - 'A';
            }
            result[i] = c;
        }

        return result;
    }
};