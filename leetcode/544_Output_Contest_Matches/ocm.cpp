#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

	static string findContestMatch_leetcode(int n) {
        vector<string> v;
        for (int i = 1; i <= n; ++i) v.push_back(to_string(i));
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) {
                v[i] = "(" + v[i] + "," + v[n - i - 1] + ")";
            }
            n /= 2;
        }
        return v[0];
    }

};

int main()
{
	cout << Solution::findContestMatch_leetcode(8) << endl;
	return 0;
}
