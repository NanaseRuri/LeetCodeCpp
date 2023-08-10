#include "stdafx.h"

using namespace std;

class Solution1802NumDifferentIntegers
{
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> result;
        int left = 0;
        int right = 0;
        int wordSize = word.size();
        while (right < wordSize) {
            if (word[right] >= '0' && word[right] <= '9') {
                right++;
            }
            else {
                if (left != right) {
                    while (word[left] == '0' && left < right) {
                        left++;
                    }
                    if (left != right) {
                        result.insert(word.substr(left, right - left));
                    }
                }
                right++;
                left = right;
            }
        }

        while (word[left] == '0' && left < right) {
            left++;
        }
        if (left != right) {
            result.insert(word.substr(left, right - left));
        }

        return result.size();
    }
};

//int main() {
//    Solution1802NumDifferentIntegers solution;
//    solution.numDifferentIntegers("a1b01c001");
//}
