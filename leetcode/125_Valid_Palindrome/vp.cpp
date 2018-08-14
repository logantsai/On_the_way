#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    static bool isPalindrome(string s) {
		int i = 0, j = s.size() - 1;

		while (i < j) {
			s[i] = isalpha(s[i]) ? tolower(s[i]) : ' ';
			s[j] = isalpha(s[j]) ? tolower(s[j]) : ' ';
			if (s[i] == ' ') {
				++i;
			} else if (s[j] == ' ') {
				--j;
			} else if (s[i] != s[j]) {
				return false;
			} else {
				++i; --j;
			}
		}
		return true;
    }
};

int main()
{
	string a("A man, a plan, a canal: Panama");
	cout << a << endl;
	cout << Solution::isPalindrome(a) << endl;

	string b("race a car");
	cout << b << endl;
	cout << Solution::isPalindrome(b) << endl;
	return 0;

}
