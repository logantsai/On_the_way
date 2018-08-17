#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    static string longestPalindrome(string s) {
		int i = 0;
		int n = s.size();
		string ret = "";
		for ( i = 0; i < n; ++i ) {
			string s1 = helper(s, i, i);	// find those "aadaa"
			string s2 = helper(s, i, i+1);	// find those "aaaa"
			ret = ret.size() > s1.size() ? ret : s1;
			ret = ret.size() > s2.size() ? ret : s2;

		}
		return ret;
    }

	static string helper(string s, int i, int j) {
		int n = s.size();
		int cnt = 0;
		while ( i >= 0 && j < n && s[i] == s[j] ) {
			--i; ++j; ++cnt;
		}
		if ( cnt > 0 ) return s.substr(i+1, j-(i+1));
		return "";
	}
};

int main()
{
	string a("babad");
	cout << Solution::longestPalindrome(a) << endl;
	return 0;
}
