#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static string complexNumberMultiply(string a, string b) {
		int a_plus = a.find_first_of("+");
		int b_plus = b.find_first_of("+");
		int a_Re = stoi(a.substr(0, a_plus));
		int b_Re = stoi(b.substr(0, b_plus));
		int a_Im = stoi(a.substr(a_plus+1, a.size() -  (a_plus+1) - 1));
		int b_Im = stoi(b.substr(b_plus+1, b.size() -  (b_plus+1) - 1));
		cout << "a: " << a_Re << "+" << a_Im << "I" << endl;
		cout << "b: " << b_Re << "+" << b_Im << "I" << endl;
		int new_Re = a_Im*b_Im*(-1) + a_Re*b_Re;
		int new_Im = a_Re*b_Im + b_Re*a_Im;

		return to_string(new_Re) + "+" + to_string(new_Im) + "I";
    }
};

int main()
{
	string a("1+-1i");
	string b("1+-1i");
	cout << Solution::complexNumberMultiply(a, b) << endl;
	return 0;
}


