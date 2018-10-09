#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int i = 0, num = 0;
        int curRes = 0, res = 0;
        char op = '+';
        for ( i = 0; i < n; ++i ) {
            char c = s[i];
            if ( c >= '0' && c <= '9' ) {
                num = num*10 + c - '0';
            } else if ( c == '(' ) {
                int cnt = 0;
                int j = i;
                for ( ; i < n; ++i ) {
                    if ( s[i] == '(' ) cnt++;
                    if ( s[i] == ')' ) cnt--;
                    if ( cnt == 0 ) break;
                }
                num = calcute(s.substr(j+1, i-j-1));
            }
            if ( c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1 ) {
                switch (op) {
                    case '+': curRes += num; break;
                    case '-': curRes -= num; break;
                    case '*': curRes *= num; break;
                    case '/': curRes /= num; break;
                }
                if ( c == '+' || c == '-' || i == n - 1 ) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};
