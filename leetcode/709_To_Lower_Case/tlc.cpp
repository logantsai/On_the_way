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
		string lower_case_str2(str.size(), 'a');
		cout << "lower_case_str2: " << lower_case_str2 << endl;
		cout << "lower_case_str size: " << lower_case_str.size() << endl;
		cout << "lower_case_str capacity: " << lower_case_str.capacity() << endl;
		/* lamdba */
		auto to_lower = [] (char c) -> char {
			if (c >= 65 && c <= 90) {
				return c + 32;
			}
			return c;
		};

		/* lower_case_str 沒有元素 begin 不知道在哪 */
		transform(str.begin(), str.end(), back_inserter(lower_case_str), to_lower);
		/* str 有值確定其 begin 有東西 */
		transform(str.begin(), str.end(), lower_case_str2.begin(), to_lower);
		return lower_case_str2;
	}
};

int main()
{
	string a("HELLO woLd");
	string b = Solution::toLowerCase(a);
	cout << b << endl;
	return 0;
}
