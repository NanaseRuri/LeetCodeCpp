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

class Solution350Intersect
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numsMap(1001);
        for (auto& num : nums1) {
            ++numsMap[num];
        }

        vector<int> result;
        for (auto& num : nums2) {
            if (numsMap[num] > 0) {
                result.push_back(num);
                --numsMap[num];
            }
        }

        return result;
    }
};
