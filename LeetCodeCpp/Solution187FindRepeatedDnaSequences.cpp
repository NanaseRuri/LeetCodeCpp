#include "stdafx.h"

using namespace std;

class Solution187FindRepeatedDnaSequences
{
public:
    vector<string> findRepeatedDnaSequences(string s) {        
        vector<string> result;
        int sLength = s.length();
        if (sLength <= 10) {
            return result;
        }

        // ֵ����ӳ��
        int* mapValue = new int[256]{};
        mapValue['A'] = 0;
        mapValue['C'] = 1;
        mapValue['G'] = 2;
        mapValue['T'] = 3;


        int* reverseMapValue = new int[4]{};
        reverseMapValue[0] = 'A';
        reverseMapValue[1] = 'C';
        reverseMapValue[2] = 'G';
        reverseMapValue[3] = 'T';

        unordered_map<int, int> dnaValueMap;

        int currentValue = 0;
        for (int i = 0; i < 9; i++)
        {
            currentValue <<= 2;
            currentValue += mapValue[s[i]];
        }

        for (int i = 9; i < sLength; i++)
        {
            currentValue &= 0x0003FFFF;
            currentValue <<= 2;
            currentValue += mapValue[s[i]];
            dnaValueMap[currentValue]++;
        }

        for (auto& tempPair: dnaValueMap)
        {
            if (tempPair.second > 1) {
                int currentDnaValue = tempPair.first;
                string currentString;
                for (int i = 0; i < 10; i++)
                {
                    currentString.insert(currentString.begin(), reverseMapValue[currentDnaValue & 3]);
                    currentDnaValue >>= 2;
                }
                result.push_back(currentString);
            }
        }

        return result;
    }
};

//int main() {
//    string s1 = "AAAAAAAAAAAAA";
//    string s2 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
//    Solution187FindRepeatedDnaSequences solution;
//    solution.findRepeatedDnaSequences(s1);
//    solution.findRepeatedDnaSequences(s2);
//}
