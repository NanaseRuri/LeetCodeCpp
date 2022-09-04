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
#include <numeric>

using namespace std;

class Solution2024MaxConsecutiveAnswers
{
public:
    int GetResult(string& s, int k, char target) {

        int result = 0;
        int sLength= s.length();
        int windowLeft = 0;
        int count = 0;
        for (int i = 0; i < sLength; i++)
        {
            if (s[i] == target) {
                ++count;
            }
            while (count > k) {
                if (s[windowLeft] == target) {
                    count--;
                }
                windowLeft++;
            }
            result = max(result, i - windowLeft + 1);
        }

        return result;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(GetResult(answerKey, k, 'F'), GetResult(answerKey, k, 'T'));
    }
};

//int main() {
//    Solution2024MaxConsecutiveAnswers solution;
//    solution.maxConsecutiveAnswers("TTFF", 2);
//    solution.maxConsecutiveAnswers("TFFT", 1);
//    solution.maxConsecutiveAnswers("TTFTTFTT", 1);
//}