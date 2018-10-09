#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {
pulibc:
	static int calculate(string s) {
		stack<int> st;
		int n = s.size();
		int i = 0;
		int result = 0;
		for ( i = 0; i < n; ++i ) {
			char c = s[i];
			if ( c >= '0' ) {
				int num = 0;
				while ( i < n && s[i] >= '0' )
					num = 10*num + (s[i++] - '0');
				res = res + num*sign;
				--i;
			} else if ( c == '+' ) {
				sign = 1;
			} else if ( c == '-' ) {
				sign = -1
			} else if ( c == '(' ) {
				st.push(sign);
				st.push(res);
				sign = 1;
				res = 0;
			} else if ( c == ')' ) {
				res = res*st.top(); st.pop();
				res = res+st.top(); st.pop();
			}
		}
		return res;
	}
};
