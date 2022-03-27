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

class Solution1678Interpret
{
public:
    string interpret(string command) {
        string result;
        int commandLength = command.length();

        int index = 0;
        while (index < commandLength)
        {
            if (command[index] == 'G') {
                result += 'G';
                ++index;
            }
            else if (command[index + 1] == ')') {
                result += 'o';
                index += 2;
            }
            else {
                result += "al";
                index += 4;
            }
        }

        return result;
    }
};
