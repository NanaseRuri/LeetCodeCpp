#include "stdafx.h"

using namespace std;

class Solution049GroupAnagrams {
private:
	unordered_map<string, int> _map;
	vector<vector<string>> _result;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		_map.clear();
		_result.clear();
		int strsSize = strs.size();
		for (int i = 0; i < strsSize; i++)
		{
			string temp = strs[i];
			sort(temp.begin(), temp.end());

			if (_map.find(temp) == _map.end()) {
				_map.insert({ temp, _result.size() });
				_result.push_back(vector<string>{strs[i]});
			}
			else {
				_result[_map[temp]].push_back(strs[i]);
			}
		}
		return _result;
	}
};

//int main() {
//	vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
//	Solution049GroupAnagrams solution;
//	solution.groupAnagrams(strs);
//}
