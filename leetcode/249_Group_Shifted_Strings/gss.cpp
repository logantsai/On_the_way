#include <iostream>
#include <multiset>

// 循環中求距離
/*
	cbazyx....cbazyx => a, b距離 25
	abcde....xyzabce => a, b距離 1
	這個可有效辨別出是順時針還是逆時針
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, multiset<string>> m;
        for (auto a : strings) {
            string t = "";
            for (char c : a) {
				/* 算出每個字元對首字元的差值 */
                t += to_string((c - a[0] + 26) % 26) + ",";
            }
            m[t].insert(a);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return res;
    }
};
