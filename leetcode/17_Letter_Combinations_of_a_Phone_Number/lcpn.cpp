#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> m{
	{'2', "abc"},
	{'3', "def"},
	{'4', "ghi"},
	{'5', "jkl"},
	{'6', "mno"},
	{'7', "pqrs"},
	{'8', "tuv"},
	{'9', "wxyz"}
};


class Solution {
public:
    static vector<string> letterCombinations(string digits) {
		vector<char> v(digits.begin(), digits.end());
		vector<string> ret;
		string in = "";
		helper(in, v, ret, 0);
		return ret;
    }

	static void helper(string in, vector<char> v, vector<string> &ret, int start) {
		int n = v.size();
		if ( n == start ) {
			ret.push_back(in);
			return;
		}
		string tmp_s = m[v[start]];
		for ( char c : tmp_s ) {
			helper(in + c, v, ret, start + 1);
		}
	}
};


int main()
{
	string digits{"232"};
	vector<string> res = Solution::letterCombinations(digits);
	cout << "size of result: " << res.size() << endl;
	for ( string s : res ) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
