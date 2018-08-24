#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*  0xxxxx0 => impossible
	0xxxxx1 => only 0.xxxx1
	1xxxxx0 => only 100000. => 100000
	1xxxxx1	=> have size - 1 combination
*/

class Solution {
public:
    static vector<string> ambiguousCoordinates(string S) {
		int n = S.size();
		int i, x, y;
		vector<string> ret;
		for ( i = 1; i < n; ++i ) {
			vector<string> xaxis = isVaild(S.substr(0, i));
			vector<string> yaxis = isVaild(S.substr(i));
			int xaxis_size = xaxis.size();
			int yaxis_size = yaxis.size();
			if ( xaxis_size != 0 && yaxis_size != 0 ) {
				for ( x = 0; x < xaxis_size; ++x ) {
					for ( y = 0; y < yaxis_size; ++y ) {
						ret.push_back("(" + xaxis[x] +  "," + yaxis[y] + ")");
					}
				}
			}
		}
		return ret;
    }

	static vector<string> isVaild(string S) {
		int n = S.size();
		int i;
		vector<string> ret;
		if ( n == 1 ) ret.push_back(S);
		else {
			//if ( S[0] == '0' && S.back() == '0' ) do nothing
			if ( S[0] == '0' && S.back() != '0' )
				ret.push_back(S.substr(0, 1) + '.' + S.substr(1));

			if ( S[0] != '0' && S.back() == '0' )
				ret.push_back(S);

			if ( S[0] != '0' && S.back() != '0' ) {
				for ( int i = 1; i <= n-1; ++i ) {
					ret.push_back(S.substr(0, i) + '.' + S.substr(i));
				}
					ret.push_back(S);
			}
		}
		return ret;
	}
};

int main()
{
	vector<string> v;
	v = Solution::ambiguousCoordinates("123");
	for ( string s : v ) {
		cout << s << endl;
	}
	return 0;

}
