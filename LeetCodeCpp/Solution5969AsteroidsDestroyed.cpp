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

using namespace std;

class Solution5969AsteroidsDestroyed
{
public:
	bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
		sort(asteroids.begin(), asteroids.end());

		for (auto asteroid : asteroids)
		{
			if (mass >= asteroid) {
				mass += asteroid;
				if (mass > 100000) {
					return true;
				}
			}
			else {
				return false;
			}
		}

		return true;
	}
};