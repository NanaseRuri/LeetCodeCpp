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

using ll = long long;
class LCP29OrchestraLayout
{
public:
	int orchestraLayout(int num, int xPos, int yPos) {
		int circle = (num + 1) / 2;
		int layer = min(min(xPos, yPos), min(num - xPos - 1, num - yPos - 1)) + 1;

		ll area = (ll)num * num;
		ll currentCircle = (ll)num - (ll)2 * (layer - 1);
		currentCircle *= currentCircle;

		ll index = (area - currentCircle) % 9 + 1;
		int right = num - layer;
		int left = layer - 1;
		// 在 ———上
		if (xPos == left) {
			index += yPos - left;
		}
		// 在  | 右
		else if (yPos == right) {
			index += right - left;
			index += xPos - left;
		}
		// 在 ——— 下
		else if (xPos == right) {
			index += 2 * (right - left);
			index += right - yPos;
		}
		else {
			index += 3 * (right - left);
			index += right - xPos;
		}

		return (int)(index % 9 == 0 ? 9 : index % 9);
	}
};