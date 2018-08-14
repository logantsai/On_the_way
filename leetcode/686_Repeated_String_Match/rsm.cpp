#include <iostream>
#include <string>

/* notice A = "abc" B = "cab" */
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t = A;
        for (int i = 1; i <= B.size() / A.size() + 2; ++i) {
            if (t.find(B) != string::npos) return i;
            t += A;
        }
        return -1;
    }

};
