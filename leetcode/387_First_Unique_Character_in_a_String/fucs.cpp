#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static int firstUniqChar(string s) {
		unordered_map<char, int> m;
		for (char c : s) {
			++m[c];
			cout << c << " " << m[c] << endl;
		}
		int i;
		cout << "----------" << endl;
		for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 1) return i;
        }
    }
};


int main()
{
	string a("loveleetcode");
	cout << Solution::firstUniqChar(a) << endl;
}
