#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.
*/

/*
	1. 使用兩次反轉
	2. 使用istringstream
	3. 使用getline and delimiter = ' '
 */
using namespace std;

class Solution {
public:

	void reverseWords_Grandyang(string &s) {
        int storeIndex = 0, n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.resize(storeIndex);
    }

	/* 沒有排除多於空格 */
	static void reverseWords_mark(string &s) {
		reverse(s.begin(), s.end());
		int i = 0;
		auto str_it = s.begin();
		s.append(" ");
		for (char c : s) {
			if (c == ' ') {
				reverse(str_it, str_it + i);
				str_it = str_it + i + 1;
				i = -1;
			}
			++i;
		}
		s.erase(s.end()-1);
	}

	static void reverseWords_stream(string &s) {
		istringstream is(s);
		string tmp;
		is >> s;
		while (is >> tmp) {
			s = tmp + " " + s;
		}
		if (!s.empty() && s[0] == ' ') s = "";
	}
};

int main()
{
	string a("the sky    is blue");
	Solution::reverseWords_stream(a);

	cout << a << endl;
	return 0;
}
