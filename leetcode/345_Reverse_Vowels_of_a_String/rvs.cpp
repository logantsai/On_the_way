#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static string reverseVowels(string s) {
 		int i = 0, j = s.size() - 1;
		auto isVowels = [] (char c) -> bool {
			if (c == 'a' || c == 'e' || c == 'i' ||
				c == 'o' || c == 'u') return true;
				return false;
		};
		while (i < j) {
			if (isVowels(s[i]) && isVowels(s[j])) {
				swap(s[i++], s[j--]);
			} else if (isVowels(s[i])) {
				--j;
			} else {
				++i;
			}
		}
		return s;
    }

	string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        string t = "aeiouAEIOU";
        while (left < right) {
            if (t.find(s[left]) == string::npos) ++left;
            else if (t.find(s[right]) == string::npos) --right;
            else swap(s[left++], s[right--]);
        }
        return s;
    }

	string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            left = s.find_first_of("aeiouAEIOU", left);
            right = s.find_last_of("aeiouAEIOU", right);
            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }


};


int main()
{
	string a("hello");
	string b("leetcode");
	cout << Solution::reverseVowels(a) << endl;
	cout << Solution::reverseVowels(b) << endl;
	return 0;
}
