#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    static int countSubstrings(string s) {
		int i = 0, n = s.size(), j = 0;
		int cnt = 0;
		for ( i = 1; i <= n; ++i ) {
			for (j = 0; j < n - (i - 1); ++j ) {
				if (isPalindromic(s.substr(j, i))) {
					++cnt;
				}
			}
		}

		return cnt;
    }

	static bool isPalindromic(string s) {
		if (s.size() == 1) return true;
		int i = 0, j = s.size() - 1;
		while ( i < j ) {
			if ( s[i] == s[j] ) {
				++i; --j;
			} else return false;
		}
		return true;
	}

	/* dp */
	static int countSubstrings_leetcode(string s) {
		int i = 0, j = 0, n = s.size();
		int cnt = 0;
		for ( i = 0; i < n; ++i ) {
			helper(s, i, i, cnt);
			helper(s, i, i+1, cnt);
		}
		return cnt;

	}

	static void helper(string s, int i, int j, int &cnt) {
		while ( i >= 0 && j < s.size() && s[i] == s[j] ) {
			--i; ++j; ++cnt;
		}
	}
};


int main()
{
	string a("abc");
	cout << Solution::countSubstrings_leetcode(a) << endl;
	return 0;
}
