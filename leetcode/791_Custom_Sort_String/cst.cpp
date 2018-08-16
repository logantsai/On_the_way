#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static string customSortString(string S, string T) {
		unordered_map<char, int> map;
		string t = "";
		int n = S.size();

		for (char c : T) {
			int flag = 0;	// indicat c is in S or not.
			for (int i = 0; i < n; ++i) {
				if (c == S[i]) {
					flag++; break;
				}
			}

			if (flag) ++map[c];
			else t += c;
		}

		string res = "";
		for (char c : S) {
			int cnt = map[c];
			while (cnt--) res += c;
		}
		res = res + t;
		return res;
    }

	string customSortString_leetcode(string S, string T) {
        string res = "";
        unordered_map<char, int> m;
        for (char c : T) ++m[c];
        for (char c : S) {
            res += string(m[c], c);
            m[c] = 0;
        }
        for (auto a : m) {
            res += string(a.second, a.first);
        }
        return res;
    }

	string customSortString(string S, string T) {
        sort(T.begin(), T.end(), [&](char a, char b) {return S.find(a) < S.find(b);});
        return T;
    }
};

int main()
{
	string S("cba");
	string T("abcd");
	cout << Solution::customSortString(S, T) << endl;
	return 0;
}
