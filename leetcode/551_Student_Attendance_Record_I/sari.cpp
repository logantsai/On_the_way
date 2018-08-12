#include <iostream>
using namespace std;


/*
	不能有連續三個LLL
*/

class Solution {
public:
    static bool checkRecord(string s) {
		int cntA = 0, cntL = 0;
        for (char c : s) {
            if (c == 'A') {
                if (++cntA > 1) return false;
                cntL = 0;
            } else if (c == 'L') {
                if (++cntL > 2) return false;
            } else {
                cntL = 0;
            }
        }
        return true;
    }

	static bool checkRecord_normal(string s) {
		return !regex_search(s, regex("A.*A|LLL"));
	}
};

