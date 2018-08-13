#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Solution {
public:
    static int countSegments(string s) {
		istringstream is(s);
		int cnt = 0;
		string t;
		while (is >> t) {
			cout << t << endl;
			++cnt;
		}
		return cnt;
    }

	static int countSegments_v2(string s) {
		int cnt = 0;
		if (s.back() != ' ') s += ' ';
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == ' ' && s[i-1] != ' ') {
				++cnt;
			}
		}
		return cnt;
	}
};


int main()
{
	string a("Hello,      my name is John");
	cout << Solution::countSegments(a) << endl;
	cout << Solution::countSegments_v2(a) << endl;
	return 0;
}
