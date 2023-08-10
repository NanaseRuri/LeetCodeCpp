#include "stdafx.h"

using namespace std;

class Solution1042GardenNoAdj
{
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		vector<vector<int>> adj(n);

		for (auto& path : paths) {
			adj[path[0] - 1].emplace_back(path[1] - 1);
			adj[path[1] - 1].emplace_back(path[0] - 1);
		}

		vector<int> result(n);
		for (int i = 0; i < n; i++) {
			vector<bool> colored(5);
			for (auto& vertex : adj[i]) {
				colored[result[vertex]] = true;
			}

			for (int j = 1; j <= 4; j++) {
				if (colored[j] == false) {
					result[i] = j;
					break;
				}
			}
		}

		return result;
	}
};
