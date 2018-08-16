#include <iostream>
#include <string>
/*
a / (b / c)，實際上就是a / b * c
So the answer is always X1/(X2/X3/../Xn) = (X1 *X3 *..*Xn)/X2
						= X1/(X2/(X3/../Xn))
*/
class Solution {
public:
    static string optimalDivision(vector<int>& nums) {
		string res = "";
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0) res += "/";
            if (i == 1 && n > 2) res += "(";
            res += to_string(nums[i]);
            if (i == n - 1 && n > 2) res += ")";
        }
        return res;
    }
};

