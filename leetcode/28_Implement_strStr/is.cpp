#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    static int strStr(string haystack, string needle) {
		int i = 0;
		int m = needle.size();
		int n = haystack.size();
		for (i = 0; i < n - m + 1; ++i) {
			if (haystack.substr(i, m) == needle) return i;
		}
		return -1;
    }

	int strStr_github(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};

int main()
{

	string haystack("hello");
	string needle("ll");
	cout << Solution::strStr(haystack, needle) << endl;
	return 0;

}
