#include "stdafx.h"

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
