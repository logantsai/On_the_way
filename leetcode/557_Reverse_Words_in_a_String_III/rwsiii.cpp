#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    static string reverseWords(string s) {
		int i = 0;
		auto str_it = s.begin();
		s.append(" ");
		cout << "s.size: " << s.size() << endl;
		for (char c : s) {
			if (c == ' ') {
				reverse(str_it, str_it + i);
				str_it = str_it + i + 1;
				i = -1;
			}
			++i;
		}
		s.erase(s.end()-1);
		cout << "s.size: " << s.size() << endl;
		return s;
    }

	static string reverseWords_stream(string s) {
        string res = "", t = "";
        istringstream is(s);
		/* default delimiter is ' ' */
        while (is >> t) {
			cout << t << endl;
            reverse(t.begin(), t.end());
            res += t + " ";
        }
        res.pop_back();
        return res;
    }
};

int main()
{
	string a("Let's take LeetCode contest");
	string b = Solution::reverseWords(a);
	cout << b << endl;
	string c = Solution::reverseWords_stream(b);
	cout << c << endl;
	return 0;
}
