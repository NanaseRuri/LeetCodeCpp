#include "stdafx.h"

using namespace std;

class Solution5970MaximumInvitations
{
	int _maximum;
	void Bfs(unordered_map<int, vector<int>>& edge, vector<bool>& visited, vector<int>& currentPeople) {
		int key = currentPeople[currentPeople.size() - 1];

		if (visited[key]) {
			return;
		}

		bool lastFindCircle = false;
		for (auto favorite : edge[key])
		{
			visited[key] = true;
			if (visited[favorite]) {
				lastFindCircle = true;
				_maximum = max(_maximum, (int)currentPeople.size());
			}
			else {
				lastFindCircle = false;
				currentPeople.push_back(favorite);
				Bfs(edge, visited, currentPeople);
				currentPeople.pop_back();
			}
			visited[key] = false;
		}

		if (!lastFindCircle && edge[key].size() != 0 && currentPeople.size() < visited.size()) {
			_maximum = max(_maximum, (int)currentPeople.size() + 1);
		}
	}

public:
	int maximumInvitations(vector<int>& favorite) {
		_maximum = INT32_MIN;
		int favoriteSize = favorite.size();
		vector<bool> visited(favoriteSize);
		unordered_map<int, vector<int>> edge;

		for (int i = 0; i < favoriteSize; i++)
		{
			edge[favorite[i]].push_back(i);
		}

		vector<int> currentPeople;
		for (auto favoritePeople : favorite)
		{
			currentPeople.push_back(favoritePeople);
			Bfs(edge, visited, currentPeople);
			currentPeople.pop_back();
		}

		return _maximum;
	}
};

//int main() {
//	vector<int> favorite1{ 2,2,1,2 };
//	vector<int> favorite2{ 1,2,0 };
//	vector<int> favorite3{ 3,0,1,4,1 };
//	Solution5970MaximumInvitations solution;
//	solution.maximumInvitations(favorite1);
//	solution.maximumInvitations(favorite2);
//	solution.maximumInvitations(favorite3);
//}
