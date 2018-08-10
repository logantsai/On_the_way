#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
X is a good number if after rotating each digit individually by 180 degrees,
we get a valid number that is different from X.  Each digit must be rotated
- we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8
rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other,
and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?
*/

enum state {
	valid = 1,
	invalid = -2,
	original = 0,
};

class Solution {
public:
    static int rotatedDigits(int N) {
		int i, count = 0;
		for (i = 0; i <= N; ++i) {
			if (check(i)) {
				cout << i << " ";
				count++;
			}
		}
		cout << endl;
		return count;
    }
	static bool check_Grandyang(int k) {
        string str = to_string(k);
        bool flag = false;
        for (char c : str) {
            if (c == '3' || c == '4' || c == '7') return false;
            if (c == '2' || c == '5' || c == '6' || c == '9') flag = true;
        }
        return flag;
    }

	static bool check(int k) {
		string s = to_string(k);
		auto with_743 = [] (char c) -> bool {
			if (c == '3' || c == '4' || c == '7') return true;
		};
		auto with_2569 = [] (char c) -> bool {
			if (c == '2' || c == '5' || c == '6' || c == '9') return true;
		};

		int a = count_if(s.begin(), s.end(), with_743);
		int b = count_if(s.begin(), s.end(), with_2569);

		/* 有2569 且 無347 => true */
		return (b > 0) && (a == 0);
	}

	/* abcd => abc + d => dp[i] => dp[i/10] with dp[i%10] */
	static int rotatedDigits_dp(int N) {
        int res = 0;
        vector<int> dp(N + 1, original);
		for (int i = 0; i <= N; ++i) {
			if (i < 10) {
				if (i == 3 || i == 4 || i == 7) dp[i] = invalid;
				else if (i == 2 || i == 5 || i == 6 || i == 9) {
					dp[i] = valid; ++res; cout << i << " ";
				}
			} else {
				if ((dp[i/10] == valid && dp[i%10] != invalid) ||
					(dp[i/10] != invalid && dp[i%10] == valid)) {
						dp[i] = valid; ++res;
						cout << i << " ";
				}
			}
		}
		cout << endl;
        return res;
    }
};

int main()
{
	Solution::rotatedDigits(100);
	Solution::rotatedDigits_dp(100);
	return 0;
}
