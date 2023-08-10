#include "stdafx.h"

class Solution709ToLowerCase
{
public:
    string toLowerCase(string s) {
        string result;
        int sLength = s.length();
        result.resize(sLength);

        for (int i = 0; i < sLength; i++)
        {
            char c = s[i];
            if (c >= 'A' && c <= 'Z') {
                c += 'a' - 'A';
            }
            result[i] = c;
        }

        return result;
    }
};
