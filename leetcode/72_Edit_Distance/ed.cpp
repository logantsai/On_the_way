#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance_recu(string word1, string word2) {
        if(word1 == word2) return 0;
        int m = word1.size();
        int n = word2.size();

        if(word1 == "") return n;
        if(word2 == "") return m;
        if(word1[0] == word2[0]) {
            return minDistance_recu(word1.substr(1), word2.substr(1));
        } else {
			return min( 1 + minDistance_recu(word1, word2.substr(1)),
			           	min(1 + minDistance_recu(word1.substr(1), word2),
						    1 + minDistance_recu(word1.substr(1), word2.substr(1))
					   	)
				   );
        }
}


int misDistance_dp(string word1, string word2) {
	int n1 = word1.size(), n2 = word2.size();
	vector< vector<int> > dp(n1 + 1, vector<int>(n2 + 1, 0));
	int i, j;
	for ( i = 0; i <= n1; ++i ) {
		for ( j = 0; j <= n2; ++j ) {
			if ( i == 0 ) dp[i][j] = j;
			else if ( j == 0 ) dp[i][j] = i;
			else {
				if ( word1[i-1] == word2[j-1] ) dp[i][j] = dp[i-1][j-1];
				else {
					dp[i][j] = 1 + min(dp[i][j-1],  // Insert
									min(dp[i-1][j],  // Remove
									dp[i-1][j-1])); // Replace
				}
			}
		}
	}

	return dp[n1][n2];
}


int main()
{

	string word1("abcd");
	string word2("bbc");
	cout << misDistance_dp(word1, word2) << endl;
	return 0;
}

