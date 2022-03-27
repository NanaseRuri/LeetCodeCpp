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

class Solution720LongestWord
{
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() < b.size();
            }
            else {
                return a > b;
            }
            });
        string longest = "";
        unordered_set<string> cnt;
        cnt.emplace("");
        for (auto& word : words) {
            if (cnt.count(word.substr(0, word.size() - 1))) {
                cnt.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};