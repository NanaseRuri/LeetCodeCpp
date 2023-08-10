#include "stdafx.h"

using namespace std;

class Solution030FindSubstring {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		// �±��뵥�ʵ�ӳ��
		unordered_map<int, string> indexWordMap;
		// ÿ�����ʵļ���
		unordered_map<string, int> wordCountMap;
		// ��ǰ���е�ÿ�����ʵļ���
		unordered_map<string, vector<int>> currentCountMap;
		vector<int> result;

		int wordArraySize = words.size();
		for (int i = 0; i < wordArraySize; i++) {
			if (wordCountMap.find(words[i]) != wordCountMap.end()) {
				++wordCountMap[words[i]];
			}
			else {
				wordCountMap.insert({ words[i], 1 });
				currentCountMap.insert({ words[i], {} });
			}
		}

		int wordSize = words[0].size();
		int strSize = s.size();
		// �ϴ��Ƿ����¼���ĵ���
		bool lastContainsWord = false;
		int matchingWordStartIndex = 0;
		int currentMatchingSize = 0;
		for (int i = 0; i < wordSize; i++) {
			for (int j = i; j + wordSize * (wordArraySize - currentMatchingSize - 1) < strSize; j += wordSize)
			{
				string currentWord = s.substr(j, wordSize);
				if (lastContainsWord) {
					if (currentCountMap.find(currentWord) != currentCountMap.end()) {
						currentCountMap[currentWord].push_back(j);
						indexWordMap.insert({ j, currentWord });
						currentMatchingSize++;

						// �ҵ���������Ŀ���ƣ�����õ��ʵ�һ�ε���Ϣ
						if (currentCountMap[currentWord].size() > wordCountMap[currentWord]) {
							int currentWordLastIndex = currentCountMap[currentWord][0];
							for (int k = matchingWordStartIndex; k <= currentWordLastIndex; k += wordSize) {
								currentCountMap[indexWordMap[k]].erase(currentCountMap[indexWordMap[k]].begin());
								indexWordMap.erase(k);
								currentMatchingSize--;
							}
							matchingWordStartIndex = currentWordLastIndex + wordSize;
						}
					}
					else {
						// ֮ǰ�ҵ����ʣ�����û�ҵ��������Ϣ
						for (auto iterator = indexWordMap.begin(); iterator != indexWordMap.end(); iterator++)
						{
							currentCountMap[iterator->second].clear();
						}
						currentMatchingSize = 0;
						indexWordMap.clear();
						lastContainsWord = false;
					}
				}
				else {
					if (currentCountMap.find(currentWord) != currentCountMap.end()) {
						currentCountMap[currentWord].push_back(j);
						indexWordMap.insert({ j, currentWord });
						matchingWordStartIndex = j;
						currentMatchingSize++;
						lastContainsWord = true;
					}
				}

				// �ҵ�һ�飬�����һ�����ʵ���Ϣ
				if (currentMatchingSize == wordArraySize) {
					result.push_back(matchingWordStartIndex);

					currentCountMap[indexWordMap[matchingWordStartIndex]].erase(currentCountMap[indexWordMap[matchingWordStartIndex]].begin());
					indexWordMap.erase(matchingWordStartIndex);
					currentMatchingSize--;
					matchingWordStartIndex += wordSize;
				}
			}

			// ��һ��ѭ��ǰ�����Ϣ
			for (auto iterator = indexWordMap.begin(); iterator != indexWordMap.end(); iterator++)
			{
				currentCountMap[iterator->second].clear();
			}
			currentMatchingSize = 0;
			indexWordMap.clear();
			lastContainsWord = false;
		}

		return result;
	}
};

//int main() {
//	Solution030FindSubstring solution;
//	string s1 = "barfoothefoobarman";
//	vector<string> words1{ "foo","bar" };
//
//	string s2 = "wordgoodgoodgoodbestword";
//	vector<string> words2{ "word","good","best","word" };
//
//	string s3 = "barfoofoobarthefoobarman";
//	vector<string> words3{ "bar","foo","the" };
//
//	string s4 = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
//	vector<string> words4{ "fooo", "barr", "wing", "ding", "wing" };
//
//	string s5 = "wordgoodgoodgoodbestword";
//	vector<string> words5{ "word", "good", "best", "good" };
//
//	string s6 = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
//	vector<string> words6{ "ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba" };
//
//	auto result1 = solution.findSubstring(s1, words1);
//	auto result2 = solution.findSubstring(s2, words2);
//	auto result3 = solution.findSubstring(s3, words3);
//	auto result4 = solution.findSubstring(s4, words4);
//	auto result5 = solution.findSubstring(s5, words5);
//	auto result6 = solution.findSubstring(s6, words6);
//}
