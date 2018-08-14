#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
		istringstream is(s);
		string tmp;
		int n;
		while (is >> tmp) {
			n = tmp.size();
		}
		return n;
    }
};

