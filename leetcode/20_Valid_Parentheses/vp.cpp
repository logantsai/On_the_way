#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

/*
123 {
125 }
91 [
93 ]
40 (
41 )
*/

class Solution {
public:
    static bool isValid(string s) {
		stack<char> st;

		for (char c : s) {
			if (c == '(' || c == '[' || c == '{')
				st.push(c);
			else {
				char tmp = st.top();
				if (abs(c - tmp) <= 2){
					st.pop();
					continue;
				}
				else return false;
			}
		}
		return st.empty();
    }
};

int main()
{
	string a("([");
	cout << Solution::isValid(a) << endl;
	string b("()[]{}");
	cout << Solution::isValid(b) << endl;
	return 0;
}
