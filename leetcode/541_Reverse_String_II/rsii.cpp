#include <iostream>
#include <string>
#include <algorithm>
/*
	Given a string and an integer k, you need to reverse the first k characters
	for every 2k characters counting from the start of the string. If there are
	less than k characters left, reverse all of them. If there are less than 2k
	but greater than or equal to k characters, then reverse the first k characters
	and left the other as original.
 */

using namespace std;

class Solution {
public:
	static string reverseStr(string s, int k) {
		int r = 0, l = k - 1;
		while(l < s.size()) {
			int rtmp = r, ltmp = l;
			while (rtmp < ltmp)
				swap(s[rtmp++], s[ltmp--]);

			r = r + 2*k;
			l = l + 2*k;
    	}

		if (r < s.size()) {
			l = s.size() - 1;
			while (r < l)
    			swap(s[r++], s[l--]);
		}

		return s;
	}

	static string reverseStr_Grandyang2(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};

int main()
{
	string a("abcedfghijklmnopqrstuvwxyz");
	cout << a << endl;
	string b = Solution::reverseStr(a, 20);
	string c = Solution::reverseStr(a, 20);
	cout << b << endl;
	cout << c << endl;
	return 0;
}
