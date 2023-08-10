#include "stdafx.h"

using namespace std;
class Solution2488CountSubarrays
{
public:
    inline int Sign(int num) {
        if (num == 0) {
            return 0;
        }
        return num > 0 ? 1 : -1;
    }

    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int indexOfK = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                indexOfK = i;
                break;
            }
        }
         
        int result = 0;
        unordered_map<int, int> counts;
        counts[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Sign(nums[i] - k);
            if (i < indexOfK) {
                counts[sum]++;
            }
            else {
                int prev0 = counts[sum];
                int prev1 = counts[sum - 1];
                result += prev0 + prev1;
            }
        }

        return result;
    }
};


//int main() {
//    Solution2488CountSubarrays solution;
//    vector<int> nums1{ 3,2,1,4,5 };
//    vector<int> nums2{ 2,3,1};
//    vector<int> nums3{ 1,0,-1,-2,-3};
//    solution.countSubarrays(nums1, 4);
//    solution.countSubarrays(nums2, 3);
//    solution.countSubarrays(nums3, 1);
//}
