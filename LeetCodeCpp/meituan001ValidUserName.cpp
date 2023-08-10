#include "stdafx.h"

using namespace std;

bool CheckUserNameValid(string& s) {
	int sLength = s.length();
	if (sLength == 0) {
		return false;
	}

	if (isalpha(s[0])) {
		bool containNum = false;
		for (int i = 1; i < sLength; i++)
		{
			if (isalpha(s[i])) {
				continue;
			}
			else if (isdigit(s[i])) {
				containNum = true;
			}
			else {
				return false;
			}
		}

		return containNum;
	}
	else {
		return false;
	}
}

//int main() {
//	vector<string> input;	
//	int circleCount;
//	cin >> circleCount;
//	for (int i = 0; i < circleCount; i++)
//	{
//		string str;
//		cin >> str;
//		input.emplace_back(str);
//	}
//	for (auto& str:input)
//	{
//		if (CheckUserNameValid(str)) {
//			cout << "Accept" << endl;
//		}
//		else {
//			cout << "Wrong" << endl;
//		}
//	}
//}
