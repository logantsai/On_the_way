#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    static string reverseWords(string s) {
		int i = 0;
		auto str_it = s.begin();
		reverse(s.begin(), s.end());
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
};

int main()
{
	string a("the sky is blue");
	string b = Solution::reverseWords(a);
	cout << b << endl;
	return 0;
}
