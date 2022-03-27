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

class Solution1523CountOdds
{
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + ((high % 2) || (low % 2));
    }
};
