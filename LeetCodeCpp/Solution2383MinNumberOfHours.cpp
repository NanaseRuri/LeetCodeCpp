#include "stdafx.h"

using namespace std;
class Solution2383MinNumberOfHours
{
public:
	int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
		int totalEnergy = accumulate(energy.begin(), energy.end(), 1);

		int trainDay = 0;
		for (auto ex : experience) {
			if (ex >= initialExperience) {
				trainDay += ex - initialExperience + 1;
				initialExperience = 2 * ex + 1;
			}
			else {
				initialExperience += ex;
			}
		}

		return max(totalEnergy - initialEnergy, 0) + trainDay;
	}
};
