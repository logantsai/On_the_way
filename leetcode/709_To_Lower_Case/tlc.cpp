#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

/*
	Implement function ToLowerCase() that has a string parameter str,
	and returns the same string in lowercase.

	A-Z 的ascii 碼是65-90 ，a-z 的ascii 碼是97-122
 */

class Solution {
public:
	static string toLowerCase(string str) {
		string lower_case_str;
		lower_case_str.reserve(str.size());

		/* lamdba */
		const auto to_lower = [](const char c) -> char {
			if (c >= 65 && c <= 90) {
				return c + 32;
			}
			return c;
		};

		transform(str.begin(), str.end(), back_inserter(lower_case_str), to_lower);
		return lower_case_str;
	}
};

int main()
{
	string a("HELLO woLd");
	string b = Solution::toLowerCase(a);
	cout << b << endl;
	return 0;
}
