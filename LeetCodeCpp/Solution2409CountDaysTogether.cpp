#include "stdafx.h"

using namespace std;
class Solution2409CountDaysTogether
{
public:
	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		const int DayOfMonth[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		vector<int> sumDayOfMonth(12, 0);
		for (int i = 1; i < 12; i++) {
			sumDayOfMonth[i] = sumDayOfMonth[i - 1] + DayOfMonth[i - 1];
		}

		int arriveAliceTotalDay = TotalDay(arriveAlice, sumDayOfMonth);
		int leaveAliceTotalDay = TotalDay(leaveAlice, sumDayOfMonth);
		int arriveBobTotalDay = TotalDay(arriveBob, sumDayOfMonth);
		int leaveBobTotalDay = TotalDay(leaveBob, sumDayOfMonth);

		return max(0, min(leaveAliceTotalDay, leaveBobTotalDay) - max(arriveAliceTotalDay, arriveBobTotalDay) + 1);
	}

	int TotalDay(string dayStr, const vector<int> sumDayOfMonth) {
		int month = stoi(dayStr.substr(0, 2));
		int day = stoi(dayStr.substr(3));
		return sumDayOfMonth[month - 1] + day;
	}
};
