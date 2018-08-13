#include <iostream>
#include <string>

/*
	Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
*/

/*
	abc
	abcabc
	abcabcabc
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
		int n = s.size();
		int i;
		/* 找可以整除 n 的 i */
		for (i = n/2; i > 1; --i) {
			if (n % i == 0) {
				int c = n / i;
                string t = "";
                for (int j = 0; j < c; ++j) {
                    t += s.substr(0, i);
                }

				if ( t == s ) return true;
			}
		}
		return false;
    }

	bool repeatedSubstringPattern_github(string str) {
        return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
    }
};

