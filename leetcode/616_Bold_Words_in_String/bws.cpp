#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static string boldWords(vector<string>& words, string S) {
		int n = S.size();
		int i, j;
		vector<bool> bold(n, false);
		for (string word : words) {
			int len = word.size();
			for (i = 0; i <= n - len; ++i) {
				if (word[0] == S[i] && word == S.substr(i, len)) {
					for (int j = i; j < i + len; ++j) bold[j] = true;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
            if (bold[i]) {
                if (i == 0 || !bold[i - 1]) res += "<b>";
                res.push_back(S[i]);
                if (i == n - 1 || !bold[i + 1]) res += "</b>";
            } else {
                res.push_back(S[i]);
            }
        }
	}
};

