#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map< string, vector<string> > m;
		int i, j, n = strs.size();
		for (string str : strs) {
			vector<int> cnt(26, 0);
			string t = "";
			for (char c : str) ++cnt[c - 'a'];
			for (int k : cnt) t += to_string(k);
			m[t].push_back(str);
		}

		for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};
