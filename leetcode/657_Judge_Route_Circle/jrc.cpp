#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	static bool judgeCircle(string moves) {

		int updown = 0;
		int rl = 0;
		for (auto c : moves) {
			if (c == 'U') ++updown;
			else if (c == 'D') --updown;
			else if (c == 'R') ++rl;
			else if (c == 'L') --rl;
		}

		return updown == 0 && rl == 0;
    }

	bool judgeCircle_Grandyang(string moves) {
        unordered_map<char, int> m;
        for (char c : moves) ++m[c];
        return m['L'] == m['R'] && m['U'] == m['D'];
    }
};

int main()
{
	bool ret = Solution::judgeCircle("UDRLUUUDD");
	cout << ret << endl;
	return 0;
}
