#include "stdafx.h"

using namespace std;

class Solution1041IsRobotBounded
{
public:
	bool isRobotBounded(string instructions) {
		vector<pair<int, int>> directionMove{ {1,0}, {0,1},{-1,0},{0,-1} };
		int direction = 0;

		int currentX = 0;
		int currentY = 0;

		for (auto instruction : instructions) {
			if (instruction == 'G') {
				currentX += directionMove[direction].first;
				currentY += directionMove[direction].second;
			}
			else if (instruction == 'L') {
				direction += 1;
				direction %= 4;
			}
			else {
				direction += 3;
				direction %= 4;
			}
		}

		return direction != 0 || (currentX == 0 && currentY == 0);
	}
};
