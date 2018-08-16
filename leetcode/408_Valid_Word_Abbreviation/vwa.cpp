#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    static bool validWordAbbreviation_v1(string word, string abbr) {
		cout << word << " " << abbr << endl;
		int m = word.size();
		int n = abbr.size();
		int i = 0, j = 0, cnt = 0;
		while ( i < n && j < m ) {
			cnt = 0;
			if (word[j] == abbr[i]) {
				++i; ++j;
			} else if ( abbr[i] - '0' >= 0 && abbr[i] - '0' <= 9 ) {
				cout << "--------" << endl;
				while (abbr[i] - '0' >= 0 && abbr[i] - '0' <= 9) {
					++cnt; ++i;
				}
				cout << "cnt: " << cnt << " i: " << i << endl;
				j = j + stoi(abbr.substr(i - cnt, cnt));
			} else return false;	// word[i] != abbr[j]

		}
		return true;
	}

	static bool validWordAbbreviation_github(string word, string abbr) {
		cout << word << " " << abbr << endl;
		int m = word.size();
		int n = abbr.size();
		int i = 0, j = 0, cnt = 0;
		while ( i < n && j < m ) {
			if ( abbr[j] >= '0' && abbr[j] <= '9' ) {
				if ( abbr[j] == 0 ) return false;
				cnt = 0;
				while ( i < n && abbr[i] - '0' >= 0 && abbr[i] - '0' <= 9 )
					cnt = cnt * 10 + abbr[i++] - '0';
				i += val;

			} else {
				if ( word[j++] != abbr[i++] ) return false;
			}
		}
		return true;
	}
};

int main()
{
#if 1
	string s("internationalization");
	string abbr("i12iz4n");
	cout << Solution::validWordAbbreviation(s, abbr) << endl;
#endif
	string s2("apple");
	string abbr2("a2e");
	cout << Solution::validWordAbbreviation(s2, abbr2) << endl;
	return 0;
}
