#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static int longestPalindromeSubseq(string s) {
		int i = 0, j = 0, n = s.size();
        vector< vector<int> > dp(n, vector<int>(n));
#if 0
		for ( i = n - 1; i > 0; --i ) {
			dp[i][i] = 1;
			for ( j = i + 1; j < n; ++j ) {
				if ( s[i] == s[j] ) s[i][j] = s[i+1][j-1]+2;
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
#endif

		for ( j = 0; j < n; ++j ) {
			dp[j][j] = 1;
			for ( i = j - 1; i >= 0; --i ) {
				if ( s[i] == s[j] ) dp[i][j] = dp[i+1][j-1]+2;
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}

		return dp[0][n - 1];
    }

	TLE

 	int longestPalindromeSubseq_leetcode(string s) {
        int n = s.size();
        vector< vector<int> > memo(n, vector<int>(n, -1));
        return helper(s, 0, n - 1, memo);
    }
    int helper(string& s, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) return memo[i][j];
        if (i > j) return 0;
        if (i == j) return 1;
        if (s[i] == s[j]) {
            memo[i][j] = helper(s, i + 1, j - 1, memo) + 2;
        } else {
            memo[i][j] = max(helper(s, i + 1, j, memo), helper(s, i, j - 1, memo));
        }
        return memo[i][j];
    }
};

int main()
{
	string a("bbbab");
	cout << Solution::longestPalindromeSubseq(a) << endl;
	return 0;
}
