#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
	1. Sort 是 nlogn的話
	2. 建立 1440 個時間點就是 n
*/

class Solution {
public:
    static int findMinDifference(vector<string>& timePoints) {

		auto HourSort = [] (string a, string b) -> bool {
			int h_a = stoi(a.substr(0, 2));
			int m_a = stoi(a.substr(3, 2));
			int h_b = stoi(b.substr(0, 2));
			int m_b = stoi(b.substr(3, 2));
			int A = h_a * 60 + m_a;
			int B = h_b * 60 - m_b;
			return A < B;
		};

		sort(timePoints.begin(), timePoints.end(), HourSort);
		for ( string s : timePoints )
			cout << s << endl;
    }
};


int main()
{
	vector<string> v{"23:59","19:55","19:54","12:00","08:00","00:00","06:38"};

	for ( string s : v )
		cout << s << endl;
	cout << "after sort" << endl;
	Solution::findMinDifference(v);
	return 0;
}
