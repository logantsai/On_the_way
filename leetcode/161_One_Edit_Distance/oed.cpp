#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
	static bool isOneEditDistance(string s, string t) {
		int s_size = s.size();
		int t_size = t.size();
		if ( s_size < t_size ) {	//assign s is larger string, and t is smaller one.
			swap(s, t);
			swap(s_size, t_size);
		}
		int diff = s_szie - t_size;
		if ( diff >= 2 ) {
			return false;
		} else if ( diff == 1 ){	// Compare how many char different.
			int i = 0;
			for ( i = 0; i < t_size; ++i ) {
				if ( s[i] != t[i] ) return s.substr(i + 1) == t.substr(i);
			}
			return true;
		} else {
			int i = 0;
			int cnt = 0;
			for ( i = 0; i < t_size; ++i ) {
    			if ( s[i] != t[i] ) ++cnt;
			}
			return cnt == 1;
		}

	}
};

int main()
{
	string s("aaab");
	string s("aaa");
}
