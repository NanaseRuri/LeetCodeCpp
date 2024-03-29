#include "stdafx.h"

using namespace std;

class Solution1309FreqAlphabets
{
public:
    string freqAlphabets(string s) {
        string ans;
        int sLength = s.length();
        for (int i = 0; i < sLength; ++i) {
            if (i + 2 < sLength && s[i + 2] == '#') {
                ans += char((s[i] - '0') * 10 + (s[i + 1] - '1') + 'a');
                i += 2;
            }
            else {
                ans += char(s[i] - '1' + 'a');
            }
        }
        return ans;
    }
};
