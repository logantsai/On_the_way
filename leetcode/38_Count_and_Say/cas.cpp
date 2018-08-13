#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
    static string countAndSay(int n) {
		int i = 1;
		string res = "1";
		while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while (i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
	}
}
