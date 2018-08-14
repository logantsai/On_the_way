#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		int m = strs[0].size();
		int i;
		string res = "";
		int idx = 0;
		while (idx < m) {
			for (i = 1; i < n; ++i) {
				if (strs[i-1][idx] != strs[i][idx]) {
					if (idx == 0) return res;
					else return strs[0].substr(0, idx);
				}
			}
			++idx;
		}
		return strs[0];
    }
};

int main()
{
	vector<string> a{"flower","flow","flight"};
	vector<string> b{"dog","racecar","car"};
	vector<string> c{"dog","dog","dog"};
	cout << Solution::longestCommonPrefix(a) << endl;
	cout << Solution::longestCommonPrefix(b) << endl;
	cout << Solution::longestCommonPrefix(c) << endl;
	return 0;
}
