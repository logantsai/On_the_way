#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static string mostCommonWord(string paragraph, vector<string>& banned) {
		/* 去除其他符號只留 a-z 的方法 */
		for (auto & c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
		cout << paragraph << endl;

		istringstream parag_str(paragraph);
		unordered_map<string, int> map_table;
		pair<string, int> res ("", 0);
		string t;

		while (parag_str >> t) {
			/* vector 沒有定義 find 相關 operator 所以自己用lambda 寫 */
			auto it = find_if(banned.begin(), banned.end(),
				[t] (string s) -> bool {
    				if ( s == t ) return true;
    				return false;
				}
			);
			if (it == banned.end() && ++map_table[t] > res.second) {
				res = make_pair(t, map_table[t]);
			}
		}
		return res.first;
    }
};

int main()
{
	string a("Bob hit a ball, the hit BALL flew far after it was hit.");
	cout << a << endl;
	vector<string> v;
	v.push_back("hit");
	cout << Solution::mostCommonWord(a, v) << endl;
	return 0;
}
