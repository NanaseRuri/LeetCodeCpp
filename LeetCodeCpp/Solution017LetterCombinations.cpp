#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution017LetterCombinations {
private:
	unordered_map<char, vector<char>> _map;
public:
	Solution017LetterCombinations() {
		_map = unordered_map<char, vector<char>>{
			{'2',{'a','b','c'}},
			{'3',{'d','e','f'}},
			{'4',{'g','h','i'}},
			{'5',{'j','k','l'}},
			{'6',{'m','n','o'}},
			{'7',{'p','q','r','s'}},
			{'8',{'t','u','v'}},
			{'9',{'w','x','y','z'}},
		};
	}

	vector<string> letterCombinations(string digits) {
		vector<string> result;
		int strLength = digits.size();
		if (strlen == 0) {
			return result;
		}

		result.push_back("");
		for (int i = 0; i < strLength; i++)
		{
			vector<char> currentChars = _map[digits[i]];
			vector<string> temp;
			for (int j = 0; j < result.size(); j++) {
				for (int k = 0; k < currentChars.size(); k++) {
					temp.push_back(result[j] + currentChars[k]);
				}
			}
			result = temp;
		}
		return result;
	}
};

//int main() {
//	Solution017LetterCombinations solution;
//	solution.letterCombinations("23");
//	solution.letterCombinations("2");
//}