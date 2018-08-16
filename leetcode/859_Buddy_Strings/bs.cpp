#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/*
	lengthA != lengthB => false
	cnt == 0 => "abc" "abc" vs "abca" "abca"
	cnt > 2 => false
	cnt = 2 => "ab" "ba" vs "ab" "ca"
*/


class Solution {
public:
    static bool buddyStrings(string A, string B) {
    	int a_len = A.size();
		int b_len = B.size();

		if (a_len != b_len) return false;

		int i = 0, cnt = 0;
		vector<int> v;

		for ( i = 0; i < a_len; ++i ) {
			if ( A[i] != B[i] ) {
				++cnt; v.push_back(i);
			}
			if (cnt > 2) return false;
		}

		if (cnt == 2) {
			swap(A[v[0]], A[v[1]]);
			return A == B;
		}

		unordered_set<char> st_A(A.begin(), A.end());
		if (cnt == 0 && st_A.size() < a_len) return true;
		return false;

    }
};


int main()
{
	string a("abcad");
	string b("abcad");
	cout << Solution::buddyStrings << endl;
	return 0;
}
