#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
	Given a list of strings, you need to find the longest uncommon subsequence
	among them. The longest uncommon subsequence is defined as the longest
	subsequence of one of these strings and this subsequence should not be any
	subsequence of the other strings.

	A subsequence is a sequence that can be derived from one sequence by deleting
	some characters without changing the order of the remaining elements.
	Trivially, any string is a subsequence of itself and an empty string is a
	subsequence of any string.

	The input will be a list of strings, and the output needs to be the length of
	the longest uncommon subsequence. If the longest uncommon subsequence doesn't
	exist, return -1.
*/


/*
	brute force
	除去 字串 其為別人子字串
	剩下的找最大
 */

class Solution {
public:
    static int findLUSlength(vector<string>& strs) {
		int i, j, n = strs.size();
		int res = 0;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (i == j) continue;
				if (is_sub_of_str(strs[i], strs[j])) {
					break;	// strs[i] 為某個的subsequence
				}
			}
			// strs[i] 不為其他字串的 subsequence
			if (j == n) res = max(res, (int)strs[i].size());
		}
		return res;
	}

	static bool is_sub_of_str(string sub, string str) {
		int i = 0;
		for (char c : str) {
			if (c == sub[i]) i++;
			if (i == sub.size()) break;
		}
		return i == sub.size();
	}

	/* 將同長度的字串放一群, 先從最大長度那一群開始找起 */
	static void findLUSlength_opt(vector<string>& strs) {
		unordered_map<int, vector<string> > map_table;
		for (string s : strs)
			map_table[s.size()].push_back(s);

		for (auto& int_vec : map_table) {
			cout << int_vec.first << ": ";
			for (auto& s : int_vec.second)
				cout << s << " ";
			cout << endl;
			cout <<  "lus: " << findLUSlength(int_vec.second) << endl;
		}

	}
};

int main()
{
	vector<string> strs;
	strs.reserve(10);
	strs.push_back("aad");
	strs.push_back("aaabbb");
	strs.push_back("aaaaaaaaa");
	strs.push_back("adasdb");
	strs.push_back("adasdf");
	strs.push_back("aaaaaaaaa");
	Solution::findLUSlength_opt(strs);
	return 0;
}
