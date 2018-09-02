#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;


class Solution {
public:
    static string reorganizeString(string S) {
		map<char, int> m;
		string res = "";

		for ( char c : S ) ++m[c];
		for ( auto a : m ) {
			if (a.second > (S.size() + 1) / 2) return "";
		}
		vector<pair<char, int> > vec(m.begin(), m.end());

		auto ValueCmp = [] (pair<char,int> a, pair<char, int> b) -> bool {
			if ( a.second > b.second ) return true;
			return false;
		};
		// 只能用在vector, list, queue
		sort(vec.begin(), vec.end(), ValueCmp);
		for ( auto p : vec ) {
			cout << p.first << p.second << endl;
		}

		while ( vec[0].second > 0 ) {
			for ( auto &p : vec ) {
				if ( p.second > 0 ) {
					res = res + p.first;
					--p.second;
				}
				cout << res << endl;
			}
		}
		return res;
    }

	string reorganizeString_github(string S) {
        vector<int> mp(26);
        int n = S.size();
        for (char c: S)
            ++mp[c-'a'];
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] > (n+1)/2) return "";
            if (mp[i]) pq.push({mp[i], i+'a'});
        }
        queue<pair<int, char>> myq;
        string ans;
        while (!pq.empty() || myq.size() > 1) {
            if (myq.size() > 1) {
                auto cur = myq.front();
                myq.pop();
                if (cur.first != 0) pq.push(cur);
            }
            if (!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                ans += cur.second;
                cur.first--;
                myq.push(cur);
            }
        }
        return ans;
    }
};

int main()
{
	string S{"caabbba"};
	cout << Solution::reorganizeString(S) << endl;
	return 0;
}
