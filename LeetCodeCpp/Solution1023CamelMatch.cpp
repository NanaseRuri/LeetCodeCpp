#include "stdafx.h"

using namespace std;

class Solution1023CamelMatch
{
public:
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		int patternSize = pattern.size();
		int queriesSize = queries.size();
		vector<bool> result(queriesSize, true);
		for (int i = 0; i < queriesSize; i++)
		{
			int patternIndex = 0;
			for (auto c : queries[i]) {
				if (patternIndex < patternSize && c == pattern[patternIndex]) {
					patternIndex++;
				}
				else if (c <= 'Z') {
					result[i] = false;
					break;
				}
			}

			if (patternIndex != patternSize) {
				result[i] = false;
			}
		}

		return result;
	}
};

//int main() {
//	Solution1023CamelMatch solution;
//	vector<string> queries1{ "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
//	string pattern1 = "FB";
//	vector<string> queries2{ "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
//	string pattern2 = "FoBa";
//	vector<string> queries3{ "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
//	string pattern3 = "FoBaT";
//	vector<string> queries4{ "CompetitiveProgramming","CounterPick","ControlPanel" };
//	string pattern4 = "CooP";
//
//	solution.camelMatch(queries1, pattern1);
//	solution.camelMatch(queries2, pattern2);
//	solution.camelMatch(queries3, pattern3);
//	solution.camelMatch(queries4, pattern4);
//}
