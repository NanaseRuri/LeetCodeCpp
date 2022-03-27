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

class Solution1232CheckStraightLine {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltaX = coordinates[0][0];
        int deltaY = coordinates[0][1];

        for (auto& coordinate:coordinates)
        {
            coordinate[0] -= deltaX;
            coordinate[1] -= deltaY;
        }

        int a = coordinates[1][1];
        int b = coordinates[1][0];
        int coordinatesSize = coordinates.size();
        for (int i = 2; i < coordinatesSize; i++)
        {
            if (a * coordinates[i][0] - b * coordinates[i][1] != 0) {
                return false;
            }
        }
        return true;
    }
};
