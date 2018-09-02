#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static int expressiveWords(string S, vector<string>& words) {
		unordered_map< char, int > m;
		vector< unordered_map< char,int > > v;
		for ( char c : S ) ++m[c];

		for ( string word : words ) {
			unordered_map< char, int > m_tmp;
			for ( char c : word ) ++m_tmp[c];

			v.push_back(m_tmp);
		}


		for ( auto m1 : v ) {
			for ( auto s : m1 )
				cout << s.first << s.second <<" ";
			cout << endl;
		}

		int ret = 0;
		int n = v.size();
		for ( int i = 0; i < n; ++i ) {
			bool stretchy = true;

			for ( auto tmp : m ) {
				cout << tmp.first << tmp.second << v[i].count(tmp.first) << " ";
#if 1
				if (v[i].count(tmp.first) > 0 ) {
					int num = tmp.second - v[i][tmp.first];
					if ( num == 0 || num >= 2 ) {}
					else stretchy = false;
				} else {
					stretchy = false;
				}
#else
				int num = tmp.second - v[i][tmp.first];	// 記住！map 這樣會新增
				if ( v[i].count(tmp.first) > 0 && (num == 0 || num >= 2) ) {}
				else stretchy = false;
#endif
			}
			if ( stretchy ) ++ret;
			cout << endl;
		}
		return ret;
    }
};

int main()
{
	string S{"heeellooo"};
	vector<string> words{"hello", "hi", "helo"};
	cout << Solution::expressiveWords(S, words) << endl;
	return 0;
}
