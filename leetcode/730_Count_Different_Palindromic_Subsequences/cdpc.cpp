#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int countPalindromicSubsequences_dp(string S) {
		int n = S.size();
		int M = 1e9 + 7;
		vector< vector<int> > dp(n, vector<int>(n, 0));
		int i, j;
		for ( i = 0; i < n; ++i) dp[i][i] = 1;
		for ( i = n - 1; i > 0; --i ) {
			for ( j = i + 1; j < n; ++j ) {
				if (s[i] != s[j]) dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
				else {
					int l = i + 1, r = j - 1;
					while ( l <= r && s[i] != s[l] ) ++l;
					while ( l <= r && s[i] != s[r] ) --r;
					if ( l > r ) { /* no char in s[i+1:j-1] same as s[i] */
						dp[i][j] = dp[i+1][j-1]*2 + 2;
					} else if ( l == r ) { /* only one same as s[i] */
						dp[i][j] = dp[i+1][j-1]*2 + 2 - 1;
					} else {	/* more than or equal to 2 char same as s[i] */
						dp[i][j] = dp[i+1][j-1]*2 - dp[l+1][r-1];
					}
				dp[i][j] = (dp[i][j] < 0) ? dp[i][j] + M : dp[i][j] % M;
			}
		}
    }
	return dp[0][n-1];

};


class Solution_recur {
public:
    int countPalindromicSubsequences(const string& S) {
        const int n = S.length();
        m_ = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return count(S, 0, S.length() - 1);
    }
private:
    static constexpr long kMod = 1000000007;
    long count(const string& S, int s, int e) {
        if (s > e) return 0;
        if (s == e) return 1;
        if (m_[s][e] > 0) return m_[s][e];

        long ans = 0;
        if (S[s] == S[e]) {
            int l = s + 1;
            int r = e - 1;
            while (l <= r && S[l] != S[s]) ++l;
            while (l <= r && S[r] != S[s]) --r;
            if (l > r)
                ans = count(S, s + 1, e - 1) * 2 + 2;
            else if (l == r)
                ans = count(S, s + 1, e - 1) * 2 + 1;
            else
                ans = count(S, s + 1, e - 1) * 2
                    - count(S, l + 1, r - 1);
        } else {
            ans = count(S, s, e - 1)
                + count(S, s + 1, e)
                - count(S, s + 1, e - 1);
        }
        return m_[s][e] = (ans + kMod) % kMod;
    }

    vector<vector<int>> m_;
};
