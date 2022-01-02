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

using namespace std;

class Solution5967CheckString
{
public:
    bool checkString(string s) {
        int indexOfB = INT32_MAX;
        int sLength = s.length();

        for (int i = 0; i < sLength; i++)
        {
            if (s[i] == 'a') {
                if (i > indexOfB) {
                    return false;
                }
            }
            else {
                indexOfB = i;
            }
        }
        return true;
    }
};
