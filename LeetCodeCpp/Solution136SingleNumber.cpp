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

class Solution136SingleNumber
{
public:
    int singleNumber(vector<int>& nums) {
        int numsSize = nums.size();
        int result = 0;
        for (int i = 0; i < numsSize; i++)
        {
            result ^= nums[i];
        }
        return result;
    }
};