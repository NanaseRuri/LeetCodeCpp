#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution071SimplifyPath
{
public:
	string simplifyPath(string& path) {
		stack<string> directoies;
		int pathSize = path.size();

		bool lastIsPoint = false;
		bool lastIsDoublePoint = false;
		bool lastIsChar = false;
		int wordStartIndex = false;

		int index = 0;
		while (index < pathSize)
		{
			if (path[index] >= 'A' && path[index] <= 'z') {
				if (lastIsDoublePoint) {
					wordStartIndex = index - 2;
					lastIsChar = true;
					lastIsDoublePoint = false;
				}
				else if (lastIsPoint) {
					wordStartIndex = index - 1;
					lastIsChar = true;
					lastIsPoint = false;
				}
				if (!lastIsChar) {
					lastIsChar = true;
					wordStartIndex = index;
				}
				lastIsPoint = false;
				++index;
				while (index < pathSize && path[index] != '/')
				{
					++index;
				}
			}
			else {
				if (lastIsChar) {
					directoies.push(path.substr(wordStartIndex, index - wordStartIndex));
					lastIsChar = false;
				}
				if (path[index] == '.') {
					if (lastIsDoublePoint) {
						lastIsChar = true;
						wordStartIndex = index - 2;
						lastIsDoublePoint = false;
						lastIsPoint = false;
						++index;
						while (index < pathSize && path[index] != '/')
						{
							++index;
						}
					}
					else {
						if (lastIsPoint) {
							lastIsDoublePoint = true;
						}
						lastIsPoint = true;
						++index;
					}
				}
				else {
					if (lastIsDoublePoint) {
						if (directoies.size() != 0) {
							directoies.pop();
						}
						lastIsDoublePoint = false;
					}
					lastIsPoint = false;
					++index;
				}
			}
		}
		if (lastIsChar) {
			directoies.push(path.substr(wordStartIndex, index - wordStartIndex));
		}
		else if (lastIsDoublePoint) {
			if (directoies.size() != 0) {
				directoies.pop();
			}
			lastIsDoublePoint = false;
		}

		if (directoies.size() == 0) {
			return "/";
		}

		string result;
		while (directoies.size() != 0)
		{
			result.insert(0, "/" + directoies.top());
			directoies.pop();
		}

		return result;
	}
};

//int main() {
//	Solution071SimplifyPath solution;
//	string path1 = "/home/";
//	string path2 = "/../";
//	string path3 = "/a/./b/../../c/";
//	string path4 = "/a/../../b/../c//.//";
//	string path5 = "/a//b////c/d//././/..";
//	string path6 = "/...";
//	string path7 = "/.../";
//	string path8 = "/.hidden";
//	cout << solution.simplifyPath(path1) << endl;
//	cout << solution.simplifyPath(path2) << endl;
//	cout << solution.simplifyPath(path3) << endl;
//	cout << solution.simplifyPath(path4) << endl;
//	cout << solution.simplifyPath(path5) << endl;
//	cout << solution.simplifyPath(path6) << endl;
//	cout << solution.simplifyPath(path7) << endl;
//	cout << solution.simplifyPath(path8) << endl;
//}