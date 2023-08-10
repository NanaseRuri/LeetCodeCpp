#include "stdafx.h"

using namespace std;

class Solution1502CanMakeArithmeticProgression
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int arrSize = arr.size();

        int difference = arr[1] - arr[0];
        for (int i = 2; i < arrSize; i++)
        {
            if (arr[i] - arr[i - 1] != difference) {
                return false;
            }
        }

        return true;
    }
};
