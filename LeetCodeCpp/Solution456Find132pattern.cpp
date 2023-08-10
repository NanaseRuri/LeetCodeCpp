#include "stdafx.h"

class Solution456Find132pattern {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> myStack;
        
        int k = INT32_MIN;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < k) {
                return true;
            }
            while (!myStack.empty() && myStack.top() < nums[i]) {
                k = max(k, myStack.top());
                myStack.pop();
            }
            myStack.push(nums[i]);
        }
        return false;
    }
};
