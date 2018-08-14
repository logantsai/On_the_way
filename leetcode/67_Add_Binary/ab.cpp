#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    static string addBinary(string a, string b) {
		int a_idx = a.size() - 1;
		int b_idx = b.size() - 1;
		string res = "";
		int carry = 0;
		while (a_idx > -1 && b_idx > -1) {
			int sum = a[a_idx--] - '0' + b[b_idx--] - '0' + carry;
			res = to_string(sum % 2) + res;
			carry = sum / 2;
		}
		cout << res << endl;
		string tmp;
		if (a_idx > -1 && !(b_idx > -1))
			tmp = a.substr(0, a_idx + 1);

		if (b_idx > -1 && !(a_idx > -1))
    		tmp = b.substr(0, b_idx + 1);

		if (!(b_idx > -1) && !(a_idx > -1))
			tmp = "";
		cout << "------" << endl;
		cout << "res " << res << endl;
		cout << "tmp " << tmp << endl;
		cout << "carry " << carry << endl;
		cout << endl;
		if (carry == 1) {
			if (tmp == "") res = "1" + res;
			else res = addOne(tmp) + res;
		} else
			res = tmp + res;

		return res;
	}

	static string addOne(string s) {
		int n = s.size();
		int carry = 0;
		string res = "";
		while (--n > -1) {
			int sum = s[n] - '0' + 1 + carry;
			res = to_string(sum % 2) + res;
			carry = sum / 2;
		}
		if (carry == 1) res = "1" + res;
		return res;
    }

	static string addBinary_github(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};

int main()
{
	string a("11");
	string b("1");

	string c("1010");
	string d("1011");
	cout << Solution::addBinary(a, b) << endl;
	cout << Solution::addBinary(c, d) << endl;
	return 0;
}
