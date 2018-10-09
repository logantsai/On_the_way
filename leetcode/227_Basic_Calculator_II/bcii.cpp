#include <iostream>
#include <string>

using namespace std;


class Solution {
pulibc:
	static int calculate(string s) {
		stack<int> st;
		char opt = '+';
		int i = 0, n = s.size(), num = 0;
		for ( i = 0; i < n; ++i ) {
			if (s[i] >= '0') {
				while ( i < n && s[i] >= '0' ) {
					num = num*10 + s[i++] - '0';
				}
			}
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
                if (opt == '+') {
                    st.push(num);
                } else if (opt == '-') {
                    st.push(-num);
                } else {
                    int tmp = st.top(); st.pop();
                    opt == '*' ? st.push(tmp*num) : st.push(tmp/num);
                }
            }
			opt = s[i]; //!!!
			num = 0;

			while (!st.empty()) {
				res += st.top();
				st.pop();
			}
		}
	}
};
