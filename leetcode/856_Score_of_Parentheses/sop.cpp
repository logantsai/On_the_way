#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
	// recursion
    int scoreOfParentheses(string S) {
		int n = S.size();
		if ( n == 2 ) return 1;
		int i;
		int cnt = 0;
		int start = 0;
		int res = 0;

		for ( i = 0; i < n; ++i ) {
			if ( S[i] == '(' ) ++cnt;
			else --cnt;

			cout << cnt << endl;

			if ( cnt == 0 && i == n - 1 && start == 0 ) { // ( ()()() )
				//cout << S.substr(1, n - 2) << endl;
				res = res + 2*scoreOfParentheses(S.substr(1, n - 2));
			} else if ( cnt == 0 && i < n ) {
				//cout << S.substr(start, i - start + 1) << endl;
				res = res + scoreOfParentheses(S.substr(start, i - start + 1));
				start = i + 1;
			}
		}
		return res;
    }

	int scoreOfParentheses_github(string S) {
        int res[30] = {0}, i = 0;
        for (char c : S)
            if (c == '(') res[++i] = 0;
            else res[i - 1] += max(res[i] * 2, 1), i--;
        return res[0];
    }

	static int scoreOfParentheses_stack(string S) {
		int res = 0;
		stack<int> st;
		for ( char c : S ) {
			if ( c == '(' ) {
				st.push(-1);
			} else {
				int val = 0;
				while ( st.top() != -1 ) {
					val += st.top();
					st.pop();
				}

				st.pop();
				int t = (val == 0) ? 1 : 2*val;
				st.push(t);
			}
		}
		return st.top();
	}
};



int main()
{
	Solution s;
	string a("(()(()))");
	//cout << s.scoreOfParentheses(a) << endl;
	cout << s.scoreOfParentheses_stack(a) << endl;
	return 0;

}
