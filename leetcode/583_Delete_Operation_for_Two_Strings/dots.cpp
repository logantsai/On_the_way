#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    static int minDistance_dp(string word1, string word2) {
		int n1 = word1.size();
		int n2 = word2.size();
		int i, j;
		vector< vector<string> > dp(n1 + 1, vector<string>(n2 + 1, ""));

		for ( i = 1; i <= n1; ++i ) {
			for ( j = 1; j <= n2; ++j ) {
				if ( word1[i-1] == word2[j-1] ) {
					dp[i][j] = dp[i-1][j-1] + word2[j-1];
				} else {
					if ( dp[i-1][j].size() >= dp[i][j-1].size() )
						dp[i][j] = dp[i-1][j];
					else
						dp[i][j] = dp[i][j-1];
				}
				cout << i << " " << j << ":"<< dp[i][j] << endl;
			}
		}
		cout << dp[n1][n2] << endl;
		return dp[n1][n2].size();
    }

	static string minDistance_recu(string word1, string word2) {
		int n1 = word1.size();
		int n2 = word2.size();
		if ( word1 == word2 ) return word1;
		if ( n1 == 0 || n2 == 0 ) return "";
		if ( word1[0] == word2[0] ) {
			string r = word1[0] + minDistance_recu(word1.substr(1), word2.substr(1));
			return r;
		} else {
			string r1 = minDistance_recu(word1, word2.substr(1));
			string r2 = minDistance_recu(word1.substr(1), word2);
			string r = r1.size() > r2.size() ? r1 : r2;
			return r;
		}
	}

};

int main()
{
	string s1{"sea"};
	string s2{"eat"};
	int a = Solution::minDistance_dp(s1, s2);

	cout << "----------recu----------" << endl;
	cout << Solution::minDistance_recu(s1, s2) << endl;
	return 0;
}


