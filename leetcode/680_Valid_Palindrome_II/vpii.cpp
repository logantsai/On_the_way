#include <iostream>

using namespace std;
class Solution {
public:
    static bool validPalindrome(string s) {
		int l = 0, r = s.size() - 1;
		int cnt = 0;
		while (l < r) {
			if (s[l] != s[r]) {
				++cnt;
				if (cnt > 1) return false;
				if (s[l+1] == s[r]) {
					++l; continue;
				}
				if (s[l] == s[r-1]) {
					--r; continue;
				}
			} else {
				++l; --r;
			}
		}
		return true;
    }


	static bool validPalindrome(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right) {
			if (s[left] == s[right]) {
				++left; --right;
			} else {
				int l = left, r = right - 1;
				while (l < r) {
					if (s[l] != s[r]) break;
					++l; --r;
					if (l >= r) return true;
				}
				++left;
				while (left < right) {
					if (s[left] != s[right]) return false;
					++left; --right;
				}
			}
		}
		return true;
    }
};

int main()
{
	string a("aebbc");
	cout << a << " " << Solution::validPalindrome(a) << endl;
	return 0;
}
