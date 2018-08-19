#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, char> roman_table;
vector<int> v{1000, 500, 100, 50, 10, 5, 1};
class Solution {
public:
    static string intToRoman(int num) {
		if ( num > 3999 ) return "";
		int n = v.size();
		int i = 0;
		string res = "";
		for ( i = 0; i < n; i += 2 ) {
			int q = num / v[i];
			if ( q > 0 && q < 5 ) {
				if ( q == 4 ) {
					res = res + roman_table[v[i]] + roman_table[v[i-1]];
				} else {
					res += roman_table[v[i]];
					while ( --q ) res += roman_table[v[i]];
				}
			} else if ( q > 5 ){
				if ( q == 9 ) {
					res = res + roman_table[v[i]] + roman_table[v[i-2]];
				} else {
					q = q - 5;
					res += roman_table[v[i-1]];
					while ( --q ) res += roman_table[v[i]];
				}
			}
			num = num % v[i];
    	}

		return res;
	}
};

int main()
{
	roman_table[1] = 'I';
	roman_table[5] = 'V';
	roman_table[10] = 'X';
	roman_table[50] = 'L';
	roman_table[100] = 'C';
	roman_table[500] = 'D';
	roman_table[1000] = 'M';

#if 0
	for ( auto pairs : roman_table ) {
		cout << pairs.first << " " << pairs.second << endl;
	}
#endif
	cout << Solution::intToRoman(194) << endl;
	return 0;
}
