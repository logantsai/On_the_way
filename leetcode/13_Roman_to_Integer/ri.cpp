#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

unordered_map<char, int> roman_table;

/*	重點在 4, 9 的表示
	XXIX = 10 + 10 - 1 + 10 !!! 正負號由下一個值決定
	XXXI = 10 + 10 + 10 + 1
	key : a. 若當前值 < 後一位，則當前值為負
		  b. 其他則都為正號

*/

class Solution {
public:
    static int romanToInt(string s) {
		int sum = 0;
		int n = s.size();
		int i;
		for (i = 1; i < n; ++i) {
			if (roman_table[s[i]] > roman_table[s[i-1]]) {
				sum = sum - roman_table[s[i-1]];
			} else
				sum = sum + roman_table[s[i-1]];
			cout << sum << endl;
		}
		sum += roman_table[s[i-1]];
		cout << s << " to " << sum << endl;
		return sum;
	}
};


int main()
{
	roman_table['I'] = 1;
	roman_table['V'] = 5;
	roman_table['X'] = 10;
	roman_table['L'] = 50;
	roman_table['C'] = 100;
	roman_table['M'] = 1000;
	string a("MCMXCVIII");
	Solution::romanToInt(a);
	return 0;
}
