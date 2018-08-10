#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
*/

class Solution {
public:
    static void countBinarySubstrings(string s) {
		int n = s.size() - 1;
		int i;
		vector< pair<int, string> > res;
		for (i = 0; i < n; ++i) {
			if ((s[i] == '1' && s[i+1] == '0') ||
				(s[i] == '0' && s[i+1] == '1'))
				check(i, s, res);
		}
		for (auto pairs : res)
			cout << pairs.first << " " << pairs.second << endl;
    }

	static void check(int i, string s, vector< pair<int, string> >& res) {
		int n = s.size();
		int j = i + 1;
		int l = 0;
		while (j < n && i >= 0) {
			if (s[j+l] == s[j] && s[i-l] == s[i]) {
				pair<int, string> t(i-l, s.substr(i-l, (l+1)*2));
				res.push_back(t);
				++l;
			} else
				break;
		}
	}

	int countBinarySubstrings_github(string s) {
        int res = 0, pre = 0, cur = 1, n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) ++cur;
            else {
                pre = cur;
                cur = 1;
            }
            if (pre >= cur) ++res;
        }
        return res;
    }
};

int main()
{
	string a("00110011");
	cout << a << endl;
	Solution::countBinarySubstrings(a);


	string b("10101");
	cout << b << endl;
	Solution::countBinarySubstrings(b);
	return 0;
}
