#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    static string shiftingLetters(string S, vector<int>& shifts) {
		for ( int &value : shifts ) {
			value = value % 26;
		}
		vector<int> shifts_tmp(shifts.begin(), shifts.end());
		int n = shifts_tmp.size();
		int m = S.size();
		int i,j;
		string ret = "";
		for ( i = n - 2; i >= 0; --i ) {
			shifts_tmp[i] = shifts_tmp[i] + shifts_tmp[i+1];
		}

		for ( int value : shifts_tmp ) {
			cout << value << " ";
		}
		cout << endl;

		for ( j = 0; j < m; ++j ) {
			char tmp_c = ((S[j] - 'a' + shifts_tmp[j]) % 26) + 'a';
			ret = ret + tmp_c;
		}
		return ret;
    }

	static string shiftingLetters_time(string S, vector<int>& shifts) {
		int p, i, n = shifts.size();
		string ret = "";
		for ( i = n - 1, p = 0; i >= 0; --i ) {
			S[i] = (S[i] - 'a' + (p += shifts[i] % 26)) % 26 + 'a';
		}
		return S;
	}


	string shiftingLetters(string S, vector<int>& shifts) {
		int n = shifts.size();
		int i,j;
		for ( i = n - 2; i >= 0; --i ) {
			shifts[i] = (shifts[i] + shifts[i+1]) % 26;
		}
		for ( j = 0; j < n; ++j ) {
			S[j] = (S[j] - 'a' + shifts[j]) % 26 + 'a';
		}
		return S;
	}
};

int main()
{
	string S{"abc"};
	vector<int> shifts{3,5,9};
	string S2{"mkgfzkkuxownxvfvxasy"};
	vector<int> shifts2{505870226,437526072,266740649,224336793,532917782,311122363,
	567754492,595798950,81520022,684110326,137742843,275267355,
	856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513};

	cout << Solution::shiftingLetters_time(S2, shifts2) << endl;
	return 0;
}
