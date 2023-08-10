#include "stdafx.h"

class Solution796RotateString
{
public:
    bool rotateString(string s, string goal) {
        int sSize = s.size();
        int goalSize = goal.size();
        if (sSize != goalSize) {
            return false;
        }

        vector<int> kmp(goalSize);
        for (int i = 1, j = 0; i < goalSize; ++i) {
            while (j > 0 && goal[i] != goal[j]) {
                j = kmp[j - 1];
            }
            if (goal[i] == goal[j]) {
                ++j;
            }

            kmp[i] = j;
        }

        string temp = s + s;
        int tempSize = temp.size();
        for (int i = 0, j = 0; i < tempSize; ++i) {
            while (j > 0 && temp[i] != goal[j]) {
                j = kmp[j - 1];
            }

            if (temp[i] == goal[j]) {
                ++j;
            }
            if (j == goalSize) {
                return true;
            }
        }

        return false;
    }
};
