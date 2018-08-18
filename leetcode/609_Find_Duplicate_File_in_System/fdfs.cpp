#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    static bool findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string> > map;
		for ( string s : paths ) {
			istringstream in(s);
			string t;
			string t2;
			while ( in >> t ) {
				if ( t.find("root") != string::npos )
					t2 = t;
				else {
					int idx = t.find_first_of("(");
					string t3 = t2 + "/" + t.substr(0, idx);
					map[t.substr(idx + 1, t.size() - (idx + 1) - 1)].push_back(t3);
				}
			}
		}

		for ( auto pairs : map ) {
			cout << pairs.first << " : ";
			for ( string s : pairs.second )
				cout << s << " ";

			cout << endl;
		}
		return false;
    }
};

int main()
{
	vector<string> a{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
	for ( string s : a ) {
		cout << s << endl;
	}
	Solution::findDuplicate(a);
	return 0;
}


