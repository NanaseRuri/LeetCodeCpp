#include "stdafx.h"

using namespace std;

class Solution130Solve
{
	//private:
	//	vector<vector<string>> _result;
	//	vector<string> _currentResult;
	//	vector<vector<int>> _palidromeRecord;
	//	int _sLength;
	//	bool IsPalindrome(string& s, int startIndex, int length) {
	//		for (int i = length / 2; i < length; i++)
	//		{
	//			if (s[startIndex + i] != s[startIndex + length - i - 1]) {
	//				_palidromeRecord[startIndex][length] = -1;
	//				return false;
	//			}
	//		}
	//		_palidromeRecord[startIndex][length] = 1;
	//		return true;
	//	}
	//
	//	void Dfs(string& s, int startIndex) {
	//		if (startIndex == _sLength) {
	//			_result.push_back(vector<string>(_currentResult));
	//			return;
	//		}
	//
	//		for (int i = 1; i <= _sLength - startIndex; i++)
	//		{
	//			if (_palidromeRecord[startIndex][i] == -1) {
	//				continue;
	//			}
	//
	//			if (_palidromeRecord[startIndex][i] == 1 || IsPalindrome(s, startIndex, i)) {
	//				_currentResult.push_back(s.substr(startIndex, i));
	//				Dfs(s, startIndex + i);
	//				_currentResult.pop_back();
	//			}
	//		}
	//	}
	//public:
	//	vector<vector<string>> partition(string& s) {
	//		_result.clear();
	//		_sLength = s.size();
	//		_palidromeRecord.assign(_sLength, vector<int>(_sLength + 1));
	//		Dfs(s, 0);
	//
	//		return _result;
	//	}
public:
	vector<vector<string>> _result;
	vector<string> _currentResult;
	vector<vector<bool>> _palidromeRecord;
	int _sLength;

	void Dfs(string& s, int startIndex) {
		if (startIndex == _sLength) {
			_result.push_back(vector<string>(_currentResult));
			return;
		}

		for (int i = startIndex; i < _sLength; i++)
		{
			if (_palidromeRecord[startIndex][i]) {
				_currentResult.push_back(s.substr(startIndex, i - startIndex + 1));
				Dfs(s, i + 1);
				_currentResult.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		_result.clear();
		_sLength = s.length();
		_palidromeRecord.assign(_sLength, vector<bool>(_sLength, true));

		for (int i = _sLength - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < _sLength; j++)
			{
				_palidromeRecord[i][j] = _palidromeRecord[i + 1][j - 1] && s[i] == s[j];
			}
		}
		Dfs(s, 0);

		return _result;
	}
};

//int main() {
//	string s = "aab";
//	string s1 = "ccaacabacb";
//	Solution130Solve solution;
//	solution.partition(s);
//	solution.partition(s1);
//}
