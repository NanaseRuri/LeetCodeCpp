#include "stdafx.h"

class Solution1000MergeStones
{
public:
	int mergeStones(vector<int>& stones, int k) {
		int n = stones.size();
		if ((n - k) % (k - 1) != 0) {
			return -1;
		}

		list<int> currentStones{ stones.begin(), stones.end() };
		while (true) {
			if (currentStones.size() == 1) {
				return currentStones.front();
			}

			int firstIndex = 0;
			int lastIndex = currentStones.size();

			while (true) {
				int currentPre = 0;
				for (int i = 0; i < k; i++) {
					currentPre += currentStones.front();
					currentStones.pop_front();
				}
				currentStones.push_front(currentPre);
				firstIndex += k;

				if (lastIndex - firstIndex < k) {
					break;
				}

				int currentPost = 0;
				for (int i = 0; i < k; i++) {
					currentPost += currentStones.back();
					currentStones.pop_back();
				}
				currentStones.push_back(currentPost);
				lastIndex -= k;

				if (lastIndex - firstIndex < k) {
					break;
				}
			}
		}

		return -1;
	}
};

//int main() {
//	Solution1000MergeStones solution;
//	vector<int> stone1{ 3,2,4,1 };
//	int k1 = 2;
//	vector<int> stone2{ 3,2,4,1 };
//	int k2 = 3;
//	vector<int> stone3{ 3,5,1,2,6};
//	int k3 = 3;
//	solution.mergeStones(stone1, k1);
//	solution.mergeStones(stone2, k2);
//	solution.mergeStones(stone3, k3);
//}
