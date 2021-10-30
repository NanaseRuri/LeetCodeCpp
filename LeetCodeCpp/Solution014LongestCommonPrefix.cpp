#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution014LongestCommonPrefix {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int right = 0;
		int strsLength = strs.size();
		bool needBreak = false;

		while (true)
		{
			if (right >= strs[0].length())
			{
				break;
			}
			char currentValue = strs[0][right];
			for (size_t i = 1; i < strsLength; i++)
			{
				if (right >= strs[i].length() || currentValue != strs[i][right])
				{
					needBreak = true;
				}
			}
			if (needBreak) {
				break;
			}

			right++;
		}

		return strs[0].substr(0, right);
	}
};
//
//int main() {
//	vector<string>  strs{ "flower","flow","flight" };
//	Solution014LongestCommonPrefix prefix;
//	cout << prefix.longestCommonPrefix(strs) << endl;
//}