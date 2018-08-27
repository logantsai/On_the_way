#include <iostream>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;
/*
	將 time[0] [1] [3] [4] 四個數排列去掉重複成str
	從最右邊那位開始，重複
	1.  如果是最大-> 則填str[0] //最小
		如果不是最大-> 則填 str[next] //你的下一個
*/

class Solution {
public:
	static string nextClosestTime(string time) {
        string res = time;
        set<int> s{time[0], time[1], time[3], time[4]};
        string str(s.begin(), s.end());
		cout << str << endl;
        for (int i = res.size() - 1; i >= 0; --i) {
            if (res[i] == ':') continue;
            int pos = str.find(res[i]);
            if (pos == str.size() - 1) {
                res[i] = str[0];
            } else {
                char next = str[pos + 1];
                if (i == 4) {
                    res[i] = next;
                    return res;
                } else if (i == 3 && next <= '5') {
                    res[i] = next;
                    return res;
                } else if (i == 1 && (res[0] != '2' || (res[0] == '2' && next <= '3'))) {
                    res[i] = next;
                    return res;
                } else if (i == 0 && next <= '2') {
                    res[i] = next;
                    return res;
                }
                res[i] = str[0];
            }
        }
        return res;
    }
};

int main()
{
	string a("19:32");
	cout << Solution::nextClosestTime(a) << endl;
	return 0;
}
