#include "stdafx.h"

using namespace std;
class Solution165CompareVersion {
public:
	int compareVersion(string version1, string version2) {
		vector<string> splitResult1;
		vector<string> splitResult2;
		Split(version1, splitResult1);
		Split(version2, splitResult2);

		int splitResult1Size = splitResult1.size();
		int splitResult2Size = splitResult2.size();
		int index = 0;
		while (index < splitResult1Size && index < splitResult2Size)
		{
			if (Atoi(splitResult1[index]) > Atoi(splitResult2[index])) {
				return 1;
			}
			else if (Atoi(splitResult1[index]) < Atoi(splitResult2[index])) {
				return -1;
			}
			index++;
		}

		while (index < splitResult1Size)
		{
			if (Atoi(splitResult1[index]) != 0) {
				return 1;
			}
			index++;
		}

		while (index < splitResult2Size)
		{
			if (Atoi(splitResult2[index]) != 0) {
				return -1;
			}
			index++;
		}

		return 0;
	}

	int Atoi(string& str) {
		int result = 0;
		int startIndex = 0;
		int strSize = str.size();

		while (startIndex < strSize)
		{
			if (str[startIndex] != '0')
			{
				break;
			}
			startIndex++;
		}
		while (startIndex < strSize)
		{
			result *= 10;
			result += str[startIndex] - '0';
			startIndex++;
		}
		return result;
	}

	void Split(string version, vector<string>& result) {
		int subStartIndex = 0;
		int startIndex = 0;
		int versionLength = version.length();
		int subStringLength = 0;

		for (int i = 0; i < versionLength; i++)
		{
			if (version[i] == '.') {
				result.push_back(version.substr(startIndex, subStringLength));
				startIndex = i + 1;
				subStringLength = 0;
			}
			else {
				subStringLength++;
			}
		}

		if (subStringLength != 0) {
			result.push_back(version.substr(startIndex, subStringLength));
		}
	}
};
