#include "stdafx.h"

using namespace std;

class Solution1014MaxScoreSightseeingPair
{
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int valuesSize = values.size();
        int currentValue = values[0] + 0;
        int result = 0;
        for (int i = 1; i < valuesSize; i++) {
            result = max(result, currentValue + values[i] - i);
            currentValue = max(currentValue, values[i] + i);
        }

        return result;
    }
};
