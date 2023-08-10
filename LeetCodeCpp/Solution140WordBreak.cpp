#include "stdafx.h"

using namespace std;

class Solution140WordBreak
{
private:
	int _minWordSize;
	int _maxWordSize;
	string _currentString;
	vector<string> _result;
	unordered_set<string> _wordSet;
	int _sLength;
	/// <summary>
	/// �Ƿ�Ϊ�ɲ�ֵ���
	/// </summary>
	vector<vector<int>> _canBreakRecord;
	/// <summary>
	/// ���±� i ȡ j ���Ȼ�ȡ�����ַ���
	/// </summary>
	vector<vector<string>> _existsWordRecord;

	void Dfs(string& s, int startIndex) {
		if (startIndex == _sLength) {
			string copyString = _currentString;
			copyString.pop_back();
			_result.push_back(copyString);
			return;
		}

		for (int i = _minWordSize; i <= _maxWordSize; i++)
		{
			if (startIndex + i > _sLength) {
				break;
			}
			int indexTemp = i -_minWordSize;
			if (_canBreakRecord[startIndex][indexTemp] == -1) {
				continue;
			}
			else if (_canBreakRecord[startIndex][indexTemp] == 1) {
				_currentString += _existsWordRecord[startIndex][indexTemp] + ' ';
				Dfs(s, startIndex + i);
				_currentString.erase(_currentString.end() - (i + 1), _currentString.end());
			}
			else {
				string currentWord = s.substr(startIndex, i);
				if (_wordSet.find(currentWord) != _wordSet.end()) {
					_canBreakRecord[startIndex][indexTemp] = 1;
					_existsWordRecord[startIndex][indexTemp] = currentWord;
					_currentString += currentWord + ' ';
					Dfs(s, startIndex + i);
					_currentString.erase(_currentString.end() - (i + 1), _currentString.end());
				}
				else {
					_canBreakRecord[startIndex][indexTemp] = -1;
				}
			}
		}
	}

public:
	vector<string> wordBreak(string& s, vector<string>& wordDict) {
		_minWordSize = INT32_MAX;
		_maxWordSize = 1;
		_currentString = "";
		_result.clear();
		_wordSet.clear();

		for (auto word : wordDict)
		{
			_minWordSize = min(_minWordSize, (int)word.size());
			_maxWordSize = max(_maxWordSize, (int)word.size());
			_wordSet.insert(word);
		}

		_sLength = s.length();
		_canBreakRecord.assign(_sLength, vector<int>(_maxWordSize - _minWordSize + 1));
		_existsWordRecord.assign(_sLength, vector<string>(_maxWordSize - _minWordSize + 1));

		Dfs(s, 0);
		return _result;
	}
};

//int main() {
//	string s = "catsanddog";
//	vector<string>wordDict{ "cat", "cats", "and", "sand", "dog" };
//	Solution140WordBreak solution;
//	solution.wordBreak(s, wordDict);
//}
